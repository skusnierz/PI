#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
    int* elements;
    int top;
    int max_size;
} stack;

void push(stack* s, int n) {
    s->elements[s->top]=n;
    s->top++;
}

int pop(stack* s) {
    s->top--;
    return s->elements[s->top];
}

bool is_empty(stack* s) {
    return s->top==0 ? true : false;
}

stack* new_stack(int size) {
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    int *tab;
    tab = (int *) malloc(size * sizeof(tab));
    s->elements=tab;
    s->max_size=size;
    s->top=0;
    return s;
}

void delete_stack(stack* s) {
    free(s->elements);
    free(s);
}

typedef enum entry_type {number, add, subtract, multiply, divide} entry_type;

entry_type parse(char* raw) {
    if (raw[0] == '+') return add;
    if (raw[0] == '-') return subtract;
    if (raw[0] == '*') return multiply;
    if (raw[0] == '/') return divide;
    return number;
}

/****************************
* implement functions below *
****************************/

void do_add(stack* s) {
    int tmp = pop(s);
    int tmp1 = pop(s);
    push(s, tmp+tmp1);
}

void do_subtract(stack* s) {
    int tmp = pop(s);
    int tmp1 = pop(s);
    push(s, tmp1-tmp);
}

void do_multiply(stack* s) {
    int tmp = pop(s);
    int tmp1 = pop(s);
    push(s,tmp*tmp1);
}

void do_divide(stack* s) {
    int tmp = pop(s);
    int tmp1 = pop(s);
    push(s,tmp1/tmp);
}

int read_and_calculate(int operands_count, int max_entry_size) {
    stack* operands = new_stack(operands_count);
    char* entry = malloc((max_entry_size+1)*sizeof(char));
    int counter = 0;
    while(counter<operands_count || operands->top!=1){
        for(int i=0; i<max_entry_size; i++) entry[i] = '\0';
        scanf("%s", entry);
        if(parse(entry)==0)
        {
            int liczba=0;
            for(int i=0; i<max_entry_size; i++)
            {
                if(entry[i]=='\0')break;
                liczba=liczba*10;
                liczba=liczba+entry[i]-'0';
            }
            push(operands,liczba);
            counter++;
        }
        if(parse(entry)==1)do_add(operands);
        if(parse(entry)==2)do_subtract(operands);
        if(parse(entry)==3)do_multiply(operands);
        if(parse(entry)==4)do_divide(operands);
    }
    int result = operands->elements[0];
    delete_stack(operands);
    free(entry);
    return result;
}

int main() {
    int operands_count, max_entry_size;
    scanf("%d", &operands_count);
    scanf("%d", &max_entry_size);
    printf("%d\n", read_and_calculate(operands_count, max_entry_size));
}
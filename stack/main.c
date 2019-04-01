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
    return s==NULL ? false : true;
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

int main() {
    int size;
    scanf("%d", &size);
    stack* s = new_stack(size);
    int tmp;
    for(int i=0; i<size; i++)
    {
        scanf("%d", &tmp);
        push(s,tmp);
    }
    for(int j=0; j<size; j++)
    {
        printf("%d\n",pop(s));
    }
    delete_stack(s);
}
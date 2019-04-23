#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Uncomment line with "#define DEBUG" if you want to see your hashtable.
// But remember to send only solutions with debug turned off!
// #define DEBUG 1
#define MAX_CHARS 30

typedef unsigned int uint;

typedef struct Node {
    char text[MAX_CHARS];
    struct Node *next;
} Node;


uint hashfunc(const char* txt) {
    int i=0;
    uint sum=0;
    while(txt[i]!=NULL)
    {
        sum+=txt[i];
        i++;
        sum%=311;
    }
    return sum;
}

void add_to_hashtable(Node** hashtable, int n, const char* txt) {
    uint index = hashfunc(txt)%n;
    Node *new_node = malloc(sizeof(Node));
    strcpy(new_node->text,txt);
    new_node->next=NULL;
    if(hashtable[index]==NULL)hashtable[index]=new_node;
    else
    {
        Node *last = hashtable[index];
        while(last->next)last=last->next;
        last->next=new_node;
    }
    return;
}

bool check_if_exists(Node** hashtable, int n, const char* txt) {
    if(n==0) return false;
    uint index = hashfunc(txt)%n;
    Node *tmp = hashtable[index];
    while(tmp!=NULL)
    {
        if(strcmp(tmp->text,txt)==0)return true;
        tmp=tmp->next;
    }
    return false;
}

void free_memory(Node** hashtable, int n) {
    for (int i=0; i<n; i++) {
        Node * p = hashtable[i];
        Node * q = p;
        while(!p)
        {
            p=p->next;
            free(q);
            q=p;
        }
    }
    free(hashtable);
}

void debug_print_hashtable(Node** hashtable, int n) {
#ifdef DEBUG
    Node* ptr;
		for (int i = 0; i < n; i++) {
			printf("%d: ", i);
			ptr = hashtable[i];
			while (ptr != NULL) {
				printf("%s | ", ptr->text);
				ptr = ptr->next;
			}
			printf("\n");
		}
#endif
}

int main() {
    int Z;
    scanf("%d", &Z);

    while (Z--) {
        int n, k;
        char tmp[MAX_CHARS];

        scanf("%d", &n);
        scanf("%d", &k);

        Node** hashtable = (Node**)calloc(n, sizeof(Node*));

        for (int i = 0; i < n; i++)
            hashtable[i] = NULL;

        for (int i = 0; i < n; i++) {
            scanf("%s", tmp);
            add_to_hashtable(hashtable, n, tmp);
        }

        debug_print_hashtable(hashtable, n);

        for (int i = 0; i < k; i++) {
            scanf("%s", tmp);
            if (check_if_exists(hashtable, n, tmp)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
        //free_memory(hashtable, n);
    }
}

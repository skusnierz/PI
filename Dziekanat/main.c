#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char MAX_NAME_SIZE = 30;

typedef struct node {
    struct node *left, *right, *parent;
    int number;
    char* name;
} node;

node* create_node(int number, char* name) {
    node* tmp = malloc(sizeof(node));
    tmp->parent=NULL;
    tmp->right=NULL;
    tmp->left=NULL;
    tmp->number=number;
    tmp->name = (char*)malloc(MAX_NAME_SIZE * sizeof(char));
    strcpy(tmp->name, name);
    return tmp;
}

void delete_tree(node* root) {
    if(root==NULL)return;
    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
}

node* insert (node* root, node* to_insert) {
    if(root==NULL) root = to_insert;
    else {
        node *p = root;
        node *q = NULL;
        while (p != NULL) {
            q = p;
            if (p->number > to_insert->number)p = p->left;
            else p = p->right;
        }
        if (to_insert->number < q->number)q->left = to_insert;
        else q->right = to_insert;
        to_insert->parent=q;
    }
    return root;
}

node* find (node* root, int number) {
    if(root==NULL) return NULL;
    if(root->number==number) return root;
    if(root->number<number) return find(root->right, number);
    else return find(root->left, number);
}

node* FindMin(struct node* tmp)
{
    struct node* current = tmp;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

node* delete(node* root, int number) {
    if (root == NULL) return root;
    if (number < root->number)
        root->left = delete(root->left, number);
    else if (number > root->number)
        root->right = delete(root->right, number);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;

            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        node* temp = FindMin(root->right);
        root->number = temp->number;
        strcpy(root->name, temp->name);
        root->right = delete(root->right, temp->number);
    }
    return root;
}

int main() {
    int n, r, f;
    scanf("%d", &n);
    scanf("%d", &r);
    scanf("%d", &f);

    node* root = NULL;
    int number;
    char* name = malloc(MAX_NAME_SIZE*sizeof(char));

    while (n-- > 0) {
        scanf("%d", &number);
        scanf("%s", name);
        root = insert(root, create_node(number, name));
    }
    while (r-- > 0) {
        scanf("%d", &number);
        root = delete(root, number);
    }

    while (f-- > 0) {
        scanf("%d", &number);
        node* x = find(root, number);
        printf("%s\n", x == NULL ? "NOTFOUND" : x->name);
    }

    delete_tree(root);
    free(name);
}
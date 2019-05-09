#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    struct node *left, *right, *parent;
    int value;
} node;


node* create_node(int val) {
    node *tmp = malloc(sizeof(node));
    tmp->value=val;
    tmp->left=NULL;
    tmp->right=NULL;
    tmp->parent=NULL;
    return tmp;
}

void delete_tree(node* root) {
    if(root==NULL)return;
    delete_tree(root->left);
    free(root);
    delete_tree(root->right);
}

void insert (node* root, node* to_insert) {
    if(root==NULL)root=to_insert;
    else {
        node *p = root;
        node *q = NULL;
        while (p != NULL) {
            q = p;
            if (p->value > to_insert->value)p = p->left;
            else p = p->right;
        }
         if (to_insert->value < q->value)
            q->left = to_insert;
        else q->right = to_insert;
        to_insert->parent=q;
    }
}

void print_in_order(node* root) {
    if(root==NULL)return;
    print_in_order(root->left);
    printf("%d\n",root->value);
    print_in_order(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    node* root = NULL;
    int val;

    if (n-- > 0) {
        scanf("%d", &val);
        root = create_node(val);
    }
    while (n-- > 0) {
        scanf("%d", &val);
        insert(root, create_node(val));
    }

    print_in_order(root);

    delete_tree(root);
}

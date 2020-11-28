#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    struct node *left;
    struct node *right;
    struct node *father;
    int value;
}NODE;
typedef NODE *BINARY_TREE;

int main() {
    
}

void maketree(BINARY_TREE *tree, int value)
{
    *tree = (BINARY_TREE) malloc (sizeof (NODE));
    if (!(*tree)) {
        printf("Erro! Nao existe memoria disponivel!");
        exit (1);
    }
    (*tree)->value = value;
    (*tree)->left = (*tree)->father = (*tree)->right = NULL;
}

void setleft(BINARY_TREE tree, int value)
{
    tree->left = (BINARY_TREE) malloc (sizeof (NODE));
    if (!(tree->left)) {
        printf("Erro! Nao existe memoria disponivel!");
        exit (1);
    }
    tree->left->value = value;
    tree->left->left = NULL;
    tree->left->right = NULL;
    tree->left->father = tree;
}

void setleft(BINARY_TREE tree, int value)
{
    tree->right = (BINARY_TREE) malloc (sizeof (NODE));
    if (!(tree->right)) {
        printf("Erro! Nao existe memoria disponivel!");
        exit (1);
    }
    tree->right->value = value;
    tree->right->right = NULL;
    tree->right->left = NULL;
    tree->right->father = tree;
}

int value(BINARY_TREE tree) {
    return tree->value;
}

BINARY_TREE left(BINARY_TREE tree) {
    return tree->left;
}

BINARY_TREE right(BINARY_TREE tree) {
    return tree->right;
}

BINARY_TREE father(BINARY_TREE tree) {
    return tree->father;
}

int isleft(BINARY_TREE tree) {
    NODE *q = father(tree);
    if (!q)
        return (0);
    if (left(q) == tree)
        return (1);
    return (0);
}
int isright(BINARY_TREE tree) {
    if (father(tree))
        return (!isleft(tree));
    return (0);
}

BINARY_TREE brother(BINARY_TREE tree) {
    if (father(tree))
        if (isleft(tree))
            return right(father(tree));
        else
            return left(father(tree));
    return NULL;
}

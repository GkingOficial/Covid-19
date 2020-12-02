#include"./Árvore binária.h"

int main() {
    BINARY_TREE tree;
    makeTree(&tree, 46);
    insertElement(&tree, 15);
    insertElement(&tree, 9);
    insertElement(&tree, 45);
    insertElement(&tree, 100);
    insertElement(&tree, 78);
    insertElement(&tree, 29);

    preOrderRoute(tree);
    printf("\n");
    postOrderRoute(tree);
    printf("\n");
    ascendingOrder(tree);
    printf("\n");
    descendingOrder(tree);
    printf("\n");
}

void makeTree(BINARY_TREE *tree, int value) {
    *tree = (BINARY_TREE) malloc (sizeof (NODE));
    if (!(*tree)) {
        printf("Erro! Nao existe memoria disponivel!");
        exit (1);
    }
    (*tree)->value = value;
    (*tree)->left = (*tree)->father = (*tree)->right = NULL;
}

void setLeft(BINARY_TREE tree, int value) {
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

void setRight(BINARY_TREE tree, int value) {
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

int valueOfNode(BINARY_TREE tree) {
    if(tree == NULL) {
        printf("\nThe tree is empty!\n\n");
        exit(2);
    }
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

BINARY_TREE brother(BINARY_TREE tree) {
    if (father(tree))
        if (isLeft(tree))
            return right(father(tree));
        else
            return left(father(tree));
    return NULL;
}

int isLeft(BINARY_TREE tree) {
    NODE *q = father(tree);
    if (!q)
        return (0);
    if (left(q) == tree)
        return (1);
    return (0);
}

int isRight(BINARY_TREE tree) {
    if (father(tree))
        return (!isLeft(tree));
    return (0);
}

void insertElement(BINARY_TREE *tree, int value) {
    if (!(*tree))
        makeTree(tree, value);
    else {
        BINARY_TREE father = *tree;
        do {
            if (value < valueOfNode(father)) {
                if(father->left)
                    father = father->left;
                else {
                    setLeft(father, value);
                    break;
                }
            } else {
                if(father->right)
                    father = father->right;
                else {
                    setRight(father, value);
                    break;
                }
            }
        } while(TRUE);
    }
}

void removalByFusion(BINARY_TREE *tree) {
    if (*tree) {
        BINARY_TREE aux = *tree;
        if (!((*tree)->right))
            *tree = (*tree)->left;
        else
            if ((*tree)->left == NULL)
                *tree = (*tree)->right;
            else {
                aux = (*tree)->left;
                while (aux->right)
                aux = aux->right;
                aux->right = (*tree)->right;
                aux->right ->father= aux;
                aux = *tree;
                *tree = (*tree)->left;
            }
        free(aux);
    }
}

void removalByCopy(BINARY_TREE *tree) {
    if (*tree) {
        BINARY_TREE aux = *tree;
        if ((*tree)->right == NULL) {
            *tree = (*tree)->left;
            (*tree)->father=NULL;
        } else
            if ((*tree)->left == NULL) {
                *tree = (*tree)->right;
                (*tree)->father=NULL;
            } else {
                aux = (*tree)->right;
                while (aux->left!=NULL)
                    aux = aux->left;

                (*tree)->value = aux->value;

                if (aux->father == *tree) {
                    aux->father->right = aux->right;
                    aux->father->right->father = aux->father;
                } else {
                    aux->father->left = aux->right;
                    aux->father->left->father = aux->father;
                }
            }
        free(aux);
    }
}

void preOrderRoute(BINARY_TREE tree) {
    if (tree) {
        printf("%d...", valueOfNode(tree));
        preOrderRoute(left(tree));
        preOrderRoute(right(tree));
    }
}

void postOrderRoute(BINARY_TREE tree) {
    if (tree) {
        postOrderRoute(left(tree));
        postOrderRoute(right(tree));
        printf("%d...", valueOfNode(tree));
    }
}

void ascendingOrder(BINARY_TREE tree) {
    if (tree) {
        ascendingOrder(left(tree));
        printf("%d...", valueOfNode(tree));
        ascendingOrder(right(tree));
    }
}

void descendingOrder(BINARY_TREE tree) {
    if(tree) {
        descendingOrder(right(tree));
        printf("%d...", valueOfNode(tree));
        descendingOrder(left(tree));
    }
}
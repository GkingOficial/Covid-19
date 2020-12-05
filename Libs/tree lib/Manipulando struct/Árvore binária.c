#include"./Árvore binária.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE *file;
    CSV csv;
    
    file = fopen("amostra de dados.csv", "r");
    setRowsAndColumns(file, &csv);
    file = fopen("amostra de dados.csv", "r");
    readCSV(file, &csv);
    
    printCSV(csv);
}

void setRowsAndColumns(FILE *file, CSV *csv) {
    char c;
    int rows = 1, columns = 1;

    while(c = getc(file), c != '\n'){
        if(c == ','){
            columns++;
        }
    }
    while(c = getc(file), !feof(file)){
        if(c == '\n'){
            rows++;
        }
    }
    csv->column = columns;
    csv->row = rows;
}

void readCSV(FILE *file, CSV *csv){
    char texto[100], *word;
    int i, j, column, row;
    
    csv -> array = NULL;
    csv -> array = (char ***)malloc(sizeof(char **) * csv->row);
    for(i=0;i<4;i++) {
        csv->array[i] = (char **)malloc(sizeof(char *) * csv->column);
    }

    row = 0;
    while(fgets(texto, 100, file)) {
        column = 0;
        
        texto[strlen(texto) - 1] = '\0';
        word = strtok(texto, ",");

        while(word) {
            int lengthOfWord = strlen(word);
            csv->array[row][column] = (char *)malloc(sizeof(char) * (lengthOfWord + 1));
            strcpy(csv->array[row][column], word);
            column++;

            word = strtok(NULL, ",");
        }
        row++;
    }
}

void printCSV(CSV csv){
    for(int i = 0; i < csv.row; i++) {
        for(int j = 0; j < csv.column; j++) {
            printf("%s, ", csv.array[i][j]);
        }
        puts("\b\b");
    }
}






void makeTree(BINARY_TREE *tree, VALUES values) {
    *tree = (BINARY_TREE) malloc (sizeof (NODE));
    if (!(*tree)) {
        printf("Erro! Nao existe memoria disponivel!");
        exit (1);
    }
    strcpy((*tree)->informations.estado, values.estado);

    (*tree)->informations.casos = values.casos;
    (*tree)->informations.saude.estadoPsicologico = values.saude.estadoPsicologico;
    (*tree)->informations.saude.qualidadeDaAlimentacao = values.saude.qualidadeDaAlimentacao;
    (*tree)->informations.saude.qualidadeDoSono = values.saude.qualidadeDoSono;
    (*tree)->informations.saude.sedentarismo = values.saude.sedentarismo;

    (*tree)->left = (*tree)->father = (*tree)->right = NULL;
}

void setLeft(BINARY_TREE tree, VALUES values) {
    tree->left = (BINARY_TREE) malloc (sizeof (NODE));
    if (!(tree->left)) {
        printf("Erro! Nao existe memoria disponivel!");
        exit (1);
    }
    strcpy(tree->left->informations.estado, values.estado);

    tree->left->informations.casos = values.casos;
    tree->left->informations.saude.estadoPsicologico = values.saude.estadoPsicologico;
    tree->left->informations.saude.qualidadeDaAlimentacao = values.saude.qualidadeDaAlimentacao;
    tree->left->informations.saude.qualidadeDoSono = values.saude.qualidadeDoSono;
    tree->left->informations.saude.sedentarismo = values.saude.sedentarismo;

    tree->left->left = tree->left->right = NULL;
    tree->left->father = tree;
}

void setRight(BINARY_TREE tree, VALUES values) {
    tree->right = (BINARY_TREE) malloc (sizeof (NODE));
    if (!(tree->right)) {
        printf("Erro! Nao existe memoria disponivel!");
        exit (1);
    }
    strcpy(tree->right->informations.estado, values.estado);

    tree->right->informations.casos = values.casos;
    tree->right->informations.saude.estadoPsicologico = values.saude.estadoPsicologico;
    tree->right->informations.saude.qualidadeDaAlimentacao = values.saude.qualidadeDaAlimentacao;
    tree->right->informations.saude.qualidadeDoSono = values.saude.qualidadeDoSono;
    tree->right->informations.saude.sedentarismo = values.saude.sedentarismo;

    tree->right->right = tree->right->left = NULL;
    tree->right->father = tree;
}

VALUES valueOfNode(BINARY_TREE tree) {
    if(tree == NULL) {
        printf("\nThe tree is empty!\n\n");
        exit(2);
    }
    return tree->informations;
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

void insertElement(BINARY_TREE *tree, VALUES values) {
    if (!(*tree))
        makeTree(tree, values);
    else {
        BINARY_TREE father = (*tree);
        do {
            if (values.casos < valueOfNode(father).casos) {
                if(father->left)
                    father = father->left;
                else {
                    setLeft(father, values);
                    break;
                }
            } else {
                if(father->right)
                    father = father->right;
                else {
                    setRight(father, values);
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

                strcpy((*tree)->informations.estado, aux->informations.estado);

                (*tree)->informations.casos = aux->informations.casos;
                (*tree)->informations.saude.estadoPsicologico = aux->informations.saude.estadoPsicologico;
                (*tree)->informations.saude.qualidadeDaAlimentacao = aux->informations.saude.qualidadeDaAlimentacao;
                (*tree)->informations.saude.qualidadeDoSono = aux->informations.saude.qualidadeDoSono;
                (*tree)->informations.saude.sedentarismo = aux->informations.saude.sedentarismo;

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
        printf("%d...", valueOfNode(tree).casos);
        preOrderRoute(left(tree));
        preOrderRoute(right(tree));
    }
}

void postOrderRoute(BINARY_TREE tree) {
    if (tree) {
        postOrderRoute(left(tree));
        postOrderRoute(right(tree));
        printf("%d...", valueOfNode(tree).casos);
    }
}

void ascendingOrder(BINARY_TREE tree) {
    if (tree) {
        ascendingOrder(left(tree));
        printf("%d...", valueOfNode(tree).casos);
        ascendingOrder(right(tree));
    }
}

void descendingOrder(BINARY_TREE tree) {
    if(tree) {
        descendingOrder(right(tree));
        printf("%d...", valueOfNode(tree).casos);
        descendingOrder(left(tree));
    }
}

// void generateTree(BINARY_TREE *tree, CSV *csv, int organizate) {
//     int line;
//     VALUES values;
//     for(line = 2; line <= csv->row; line++) {
//         values = fromCSVToValue(csv, line);
//         insertElement(tree, values);
//     }
// }

// VALUES fromCSVToValue(CSV *csv, int line) {
//     VALUES values;
//     strcpy(values.estado, csv->array[line - 1][0]);
//     values.casos = csv->array[line - 1][1];
//     values.saude.sedentarismo = csv->array[line - 1][2];
//     values.saude.qualidadeDoSono = csv->array[line - 1][3];
//     values.saude.qualidadeDaAlimentacao = csv->array[line - 1][4];
//     values.saude.estadoPsicologico = csv->array[line - 1][5];
//     return values;
// }
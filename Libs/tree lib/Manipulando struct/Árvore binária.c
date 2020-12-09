#include"./Árvore binária.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define DUMP(varname) fprintf(stderr, "%s", #varname)
#define NONE 0
#define CASOS 1
#define SEDENTARISMO 2
#define SONO 3
#define ALIMENTACAO 4
#define PSICOLOGICO 5
int treeOrdering = NONE;

int main() {
    FILE *file;
    CSV csv;
    BINARY_TREE tree;
    char optionUser[30];
    int choice;
    
    file = fopen("amostra de dados.csv", "r");
    setRowsAndColumns(file, &csv);
    file = fopen("amostra de dados.csv", "r");
    readCSV(file, &csv);
    printCSV(csv);
    printf("\n");

    do {
        // Solicitação para o usuário
        scanf("%[^\n]", optionUser);

        // Ordenação
        if(strcmp(optionUser, "ordenate") == 0) {
            printf("Ordernar por...\n[ 1 ] Quantidade de casos\n[ 2 ] Nível de sedentarismo\n[ 3 ] Qualidade do sono\n[ 4 ] Qualidade da alimentação\n[ 5 ] Qualidade psicológica\n[ 6 ] Ordem alfabética dos estados\n");
            printf("Escolha uma opção: ");
            scanf("%d", &choice);

            generateTree(&tree, &csv, choice);
            treeOrdering = choice;


            printf("Tipo de ordenação:\n[ 1 ] Crescente\n[ 2 ] Decrescente\nEscolha a opção: ");
            scanf("%d", &choice);
            if(choice == 1) {
                ascendingOrder(tree);
            } else {
                descendingOrder(tree);
            }
        } else if(strcmp(optionUser, "generate csv file") == 0) {
            char nameOfFile[30];
            scanf("%[^\n]", nameOfFile);

            if(treeOrdering > 0) {
                // generateFromTreeToCSVFile(&tree, nameOfFile);
            } else {
                // generateFromCsvToCSVFile(&csv, nameOfFile);
            }
        } else if(strcmp(optionUser, "search") == 0) {
            int quantidade;
            BINARY_TREE *busca;
            printf("Procurar com base em...\n[ 1 ] Quantidade de casos\n[ 2 ] Nível de sedentarismo\n[ 3 ] Qualidade do sono\n[ 4 ] Qualidade da alimentação\n[ 5 ] Qualidade psicológica\n");
            printf("Escolha uma opção: ");
            scanf("%d", &choice);
            printf("Quantidade: ", quantidade);
            scanf("%d", &quantidade);

            generateTree(&tree, &csv, choice);
            treeOrdering = choice;

            if(choice == CASOS) {
                busca = buscaNaArvore(&tree, quantidade, CASOS);
            } else if(choice == SEDENTARISMO) {
                busca = buscaNaArvore(&tree, quantidade, SEDENTARISMO);
            } else if(choice == SONO) {
                busca = buscaNaArvore(&tree, quantidade, SONO);
            } else if(choice == ALIMENTACAO) {
                busca = buscaNaArvore(&tree, quantidade, ALIMENTACAO);
            } else if(choice == PSICOLOGICO) {
                busca = buscaNaArvore(&tree, quantidade, PSICOLOGICO);
            }
            preOrderRoute(*busca);
        }
    } while();
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
    
    csv->array = NULL;
    csv->array = (char ***)malloc(sizeof(char **) * csv->row);
    if(csv->array == NULL) {
        printf("There is not storage enough\n");
    }
    for(i=0; i<csv->row; i++) {
        csv->array[i] = (char **)malloc(sizeof(char *) * csv->column);
        if(csv->array[i] == NULL) {
            printf("There is not storage enough\n");
        }
    }

    row = 0;
    while(fgets(texto, 100, file)) {
        column = 0;
        
        texto[strlen(texto) - 1] = '\0';
        word = strtok(texto, ",");

        while(word) {
            int lengthOfWord = strlen(word);
            csv->array[row][column] = (char *)malloc(sizeof(char) * (lengthOfWord + 1));
            if(csv->array[row][column] == NULL) {
                printf("There is not storage enough\n");
            }
            strcpy(csv->array[row][column], word);
            column++;

            word = strtok(NULL, ",");
        }
        row++;
    }
}

void printTitle(CSV csv) {
    for(int j = 0; j < csv.column; j++) {
        printf("%*s%*s| ", -12, csv.array[0][j], 4, "");
    }
    puts("");
}

void printCSV(CSV csv){
    for(int j = 0; j < csv.column; j++) {
        printf("%*s%*s| ", -12, csv.array[0][j], 4, "");
    }
    puts("");
    for(int i = 1; i < csv.row; i++) {
        for(int j = 0; j < csv.column; j++) {
            if(j >= 2) {
                printf("%*s%*s| ", -12, csv.array[i][j], 4, "%");
            } else {
                printf("%*s%*s| ", -12, csv.array[i][j], 4, "");
            }
        }
        puts("\b\b");
    }
}


void centerText(char *text, int fieldWidth) {
    int padlen = (fieldWidth - strlen(text)) / 2;
    printf("%*s%s%*s\n", padlen, "", text, padlen, "");
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

int putOnTheSide(VALUES values1, VALUES values2, int organizate) {
    int aux;
    switch(organizate) {
        case 1: 
            if(values1.casos < values2.casos) {
                aux = -1;
            } else if(values1.casos > values2.casos) {
                aux = 1;
            } else {
                aux = 0;
            }
            break;
        case 2:
            if(values1.saude.sedentarismo < values2.saude.sedentarismo) {
                aux = -1;
            } else if(values1.saude.sedentarismo > values2.saude.sedentarismo) {
                aux = 1;
            } else {
                aux = 0;
            }
            break;
        case 3:
            if(values1.saude.qualidadeDoSono < values2.saude.qualidadeDoSono) {
                aux = -1;
            } else if(values1.saude.qualidadeDoSono > values2.saude.qualidadeDoSono) {
                aux = 1;
            } else {
                aux = 0;
            }
            break;
        case 4:
            if(values1.saude.qualidadeDaAlimentacao < values2.saude.qualidadeDaAlimentacao) {
                aux = -1;
            } else if(values1.saude.qualidadeDaAlimentacao > values2.saude.qualidadeDaAlimentacao) {
                aux = 1;
            } else {
                aux = 0;
            }
            break;
        case 5:
            if(values1.saude.estadoPsicologico < values2.saude.estadoPsicologico) {
                aux = -1;
            } else if(values1.saude.estadoPsicologico > values2.saude.estadoPsicologico) {
                aux = 1;
            } else {
                aux = 0;
            }
            break;
    }
    return aux;
}

void insertElement(BINARY_TREE *tree, VALUES values, int organizate) {
    if (!(*tree))
        makeTree(tree, values);
    else {
        BINARY_TREE father = (*tree);
        do {
            if(putOnTheSide(values, valueOfNode(father), organizate) == -1) {
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
        printf("%*s%*s| ", -12, valueOfNode(tree).estado, 4, "");
        printf("%-12d| ", valueOfNode(tree).casos);
        printf("%-12d| ", valueOfNode(tree).saude.sedentarismo);
        printf("%-12d| ", valueOfNode(tree).saude.qualidadeDoSono);
        printf("%-12d| ", valueOfNode(tree).saude.qualidadeDaAlimentacao);
        printf("%-12d| ", valueOfNode(tree).saude.estadoPsicologico);
        puts("");
        preOrderRoute(left(tree));
        preOrderRoute(right(tree));
    }
}

void postOrderRoute(BINARY_TREE tree) {
    if (tree) {
        postOrderRoute(left(tree));
        postOrderRoute(right(tree));
        printf("%*s%*s| ", -12, valueOfNode(tree).estado, 4, "");
        printf("%-12d| ", valueOfNode(tree).casos);
        printf("%-12d| ", valueOfNode(tree).saude.sedentarismo);
        printf("%-12d| ", valueOfNode(tree).saude.qualidadeDoSono);
        printf("%-12d| ", valueOfNode(tree).saude.qualidadeDaAlimentacao);
        printf("%-12d| ", valueOfNode(tree).saude.estadoPsicologico);
        puts("");
    }
}

void ascendingOrder(BINARY_TREE tree) {
    if (tree) {
        ascendingOrder(left(tree));
        printf("%*s%*s| ", -12, valueOfNode(tree).estado, 4, "");
        printf("%-12d| ", valueOfNode(tree).casos);
        printf("%-12d| ", valueOfNode(tree).saude.sedentarismo);
        printf("%-12d| ", valueOfNode(tree).saude.qualidadeDoSono);
        printf("%-12d| ", valueOfNode(tree).saude.qualidadeDaAlimentacao);
        printf("%-12d| ", valueOfNode(tree).saude.estadoPsicologico);
        puts("");
        ascendingOrder(right(tree));
    }
}

void descendingOrder(BINARY_TREE tree) {
    if(tree) {
        descendingOrder(right(tree));
        printf("%*s%*s| ", -12, valueOfNode(tree).estado, 4, "");
        printf("%-12d| ", valueOfNode(tree).casos);
        printf("%-12d| ", valueOfNode(tree).saude.sedentarismo);
        printf("%-12d| ", valueOfNode(tree).saude.qualidadeDoSono);
        printf("%-12d| ", valueOfNode(tree).saude.qualidadeDaAlimentacao);
        printf("%-12d| ", valueOfNode(tree).saude.estadoPsicologico);
        puts("");
        descendingOrder(left(tree));
    }
}

void generateTree(BINARY_TREE *tree, CSV *csv, int organizate) {
    int line = 2;
    VALUES *values;
    makeTree(tree, (*fromCSVToValue(csv, line)));
    for(line++; line <= csv->row; line++) {
        values = fromCSVToValue(csv, line);
        insertElement(tree, *values, organizate);
    }
}

VALUES *fromCSVToValue(CSV *csv, int line) {
    VALUES *values = (VALUES *)malloc(sizeof(VALUES));

    strcpy(values->estado, csv->array[line - 1][0]);
    values->casos = atoi(csv->array[line - 1][1]);
    values->saude.sedentarismo = atoi(csv->array[line - 1][2]);
    values->saude.qualidadeDoSono = atoi(csv->array[line - 1][3]);
    values->saude.qualidadeDaAlimentacao = atoi(csv->array[line - 1][4]);
    values->saude.estadoPsicologico = atoi(csv->array[line - 1][5]);
    return values;
}

void printVALUES(VALUES *values) {
    printf("%s = %s%c", "Estado", values->estado, '\n');
    printf("%s = %d%c", "Casos", values->casos, '\n');
    printf("%s = %d%c", "Sedentarismo", values->saude.sedentarismo, '\n');
    printf("%s = %d%c", "Sono", values->saude.qualidadeDoSono, '\n');
    printf("%s = %d%c", "Alimentação", values->saude.qualidadeDaAlimentacao, '\n');
    printf("%s = %d%s", "Estado psicológico", values->saude.estadoPsicologico, "\n\n");
}

void helperToSearch(BINARY_TREE tree) {
    if (tree) {
        ascendingOrder(left(tree));
        printf("%*s%*s| ", -12, valueOfNode(tree).estado, 4, "");
        printf("%-12d| ", valueOfNode(tree).casos);
        printf("%-12d| ", valueOfNode(tree).saude.sedentarismo);
        printf("%-12d| ", valueOfNode(tree).saude.qualidadeDoSono);
        printf("%-12d| ", valueOfNode(tree).saude.qualidadeDaAlimentacao);
        printf("%-12d| ", valueOfNode(tree).saude.estadoPsicologico);
        puts("");
        ascendingOrder(right(tree));
    }
}

BINARY_TREE *buscaNaArvore(BINARY_TREE *tree, int quantidade, int escolha) {
    BINARY_TREE *busca = NULL;
    BINARY_TREE father = (*tree);
    VALUES values;
    switch(escolha) {
        case CASOS:
            values.casos = quantidade;
            break;
        case SEDENTARISMO:
            values.saude.sedentarismo = quantidade;
            break;
        case SONO:
            values.saude.qualidadeDoSono = quantidade;
            break;
        case ALIMENTACAO:
            values.saude.qualidadeDaAlimentacao = quantidade;
            break;
        case PSICOLOGICO:
            values.saude.estadoPsicologico = quantidade;
            break;
    }
    do {
        int aux = putOnTheSide(values, valueOfNode(father), escolha);
        printf("1");
        if(aux == -1) {
            if(father->left)
                father = father->left;
            else {
                break;
            }
        } else {
            if(!aux) {
                if(busca) {
                    insertElement(busca, valueOfNode(father), escolha);
                    printf("2");
                } else {
                    makeTree(busca, valueOfNode(father));
                    printf("3");
                }
            }
            if(father->right)
                father = father->right;
            else {
                break;
            }
        }
    } while(TRUE);
    return busca;
}

FILE *generateFromTreeToCSVFile(BINARY_TREE *tree, char *nameOfFile){
    if(strlen(nameOfFile) > 30){
        puts("The file name exceeds 30 characters!");
        return NULL;
    }

    char name[35];
    strcpy(name, nameOfFile);
    strcat(name, ".csv");

    FILE *aux;
    aux = fopen(name, "w");
    
    printInFile(*tree, aux);
}

void printInFile(BINARY_TREE tree, FILE *file) {
    if (tree) {
        printInFile(left(tree), file);
        fprintf(file, "%s,", valueOfNode(tree).estado);
        fprintf(file, "%d,", valueOfNode(tree).casos);
        fprintf(file, "%d,", valueOfNode(tree).saude.sedentarismo);
        fprintf(file, "%d,", valueOfNode(tree).saude.qualidadeDoSono);
        fprintf(file, "%d,", valueOfNode(tree).saude.qualidadeDaAlimentacao);
        fprintf(file, "%d,\n", valueOfNode(tree).saude.estadoPsicologico);
        printInFile(right(tree), file);
    }
}
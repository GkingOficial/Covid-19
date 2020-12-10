#ifndef ARVORE_BINARIA
#define ARVORE_BINARIA
#endif

#define TRUE 1

typedef struct {
    int sedentarismo;
    int qualidadeDoSono;
    int qualidadeDaAlimentacao;
    int estadoPsicologico;
} HEALTH_INFORMATION;

typedef struct {
    char estado[30];
    int casos;
    HEALTH_INFORMATION saude;
} VALUES;

typedef struct node {
    struct node *left;
    struct node *right;
    struct node *father;
    VALUES informations;
} NODE;

typedef NODE *BINARY_TREE;

void makeTree(BINARY_TREE *tree, VALUES values);
void setLeft(BINARY_TREE tree, VALUES values);
void setRight(BINARY_TREE tree, VALUES values);
VALUES valueOfNode(BINARY_TREE tree);
BINARY_TREE left(BINARY_TREE tree);
BINARY_TREE right(BINARY_TREE tree);
BINARY_TREE father(BINARY_TREE tree);
BINARY_TREE brother(BINARY_TREE tree);
int isLeft(BINARY_TREE tree);
int isRight(BINARY_TREE tree);
void insertElement(BINARY_TREE *tree, VALUES values, int organizate);

void removalByFusion(BINARY_TREE *tree);
void removalByCopy(BINARY_TREE *tree);

// Raiz - Esquerda - Direita
void preOrderRoute(BINARY_TREE tree);
// Esquerda - Direita - Raíz
void postOrderRoute(BINARY_TREE tree);


// Esquerda - Raíz - Direita
void ascendingOrder(BINARY_TREE tree);
// Direita - Raíz - Esquerda
void descendingOrder(BINARY_TREE tree);

void generateTree(BINARY_TREE *tree, CSV *csv, int organizate);
VALUES *fromCSVToValue(CSV *csv, int line);
void printVALUES(VALUES values);
int putOnTheSide(VALUES values1, VALUES values2, int organizate);

FILE *generateFromTreeToCSVFile(BINARY_TREE *tree, char *nameOfFile, int order, CSV csv);
FILE *generateFromCsvToCSVFile(CSV csv, char *nameOfFile);
// void buscaNaArvore(BINARY_TREE *tree, int quantidade, int escolha);
BINARY_TREE *buscaNaArvore(BINARY_TREE *tree, int quantidade, int escolha);
void printInFile(BINARY_TREE tree, FILE *file, int order);

void clearBuffer();
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int row;
    int column;
    char **array;
}CSV;
typedef struct {
    char *nome;
    int idade;
    char *sexo;
}PESSOA;

ORDERED_LINKED_LIST * readCsv(FILE *, CSV *);
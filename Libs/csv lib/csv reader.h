#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1

typedef struct{
    int row;
    int column;
    char ***array;
}CSV;
void setRowsAndColumns(FILE *file, CSV *csv);
void readCSV(FILE *file, CSV *csv);
void printCSV(CSV csv);
void printTitle(CSV csv);

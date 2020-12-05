#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct{
    int row;
    int column;
    char ***array;
}CSV;
void setRowsAndColumns(FILE *file, CSV *csv);
void readCSV(FILE *file, CSV *csv);
void printCSV(CSV csv);
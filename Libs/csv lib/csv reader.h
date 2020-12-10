#ifndef CSV_READER
#define CSV_READER
#endif

#include <stdio.h>

typedef struct{
    int row;
    int column;
    char ***array;
} CSV;

void setRowsAndColumns(FILE *file, CSV *csv);
void readCSV(FILE *file, CSV *csv);
void printCSV(CSV csv);
void printTitle(CSV csv);
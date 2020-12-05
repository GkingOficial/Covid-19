#include "./csv reader.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

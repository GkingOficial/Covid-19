#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int row;
    int column;
    char ***array;
}CSV;

void readCSV(FILE *, CSV *);
void printCSV(CSV);

int main(){
    FILE *file;
    CSV csv;
    
    file = fopen("file.csv", "r");
    readCSV(file, &csv);
    printCSV(csv);
}

void readCSV(FILE *f, CSV *c){
    char texto[100], *word;
    int i, j, column = 0, row = 0;
    
    c -> array = NULL;
    c -> array = (char ***)malloc(sizeof(char **) * 4);
    for(i=0;i<4;i++) {
        c->array[i] = (char **)malloc(sizeof(char *) * 3);
        for(j=0;j<3;j++) {
            c->array[i][j] = (char *)malloc(sizeof(char) * 40);
        }
    }

    while(fgets(texto, 100, f)) {
        
        texto[strlen(texto) - 1] = '\0';
        //puts(texto);
        word = strtok(texto, ",");

        while(word) {
            //puts(word);
            strcpy(c->array[row][column], word);

            word = strtok(NULL, ",");
            column++;
        }
        column = 0;
        row++;
    }
}

void printCSV(CSV csv){
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%s, ", csv.array[i][j]);
        }
        printf("\b\b\n");
    }
}

#include "./csv reader.h"

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
    fseek(file, 0, SEEK_SET);
}

void readCSV(FILE *file, CSV *csv){
    char texto[100], *word;
    int i, column, row;
    
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
    int padlen;
    printf("| ");
    for(int j = 0; j < csv.column; j++) {
        padlen = (16 - strlen(csv.array[0][j])) / 2;
        printf("%*s%s%*s| ", padlen, "", csv.array[0][j], strlen(csv.array[0][j]) % 2 ? padlen + 1 : padlen, "");
    }
    puts("");
}

void printCSV(CSV csv){
    int padlen;
    printf("| ");
    for(int j = 0; j < csv.column; j++) {
        padlen = (16 - strlen(csv.array[0][j])) / 2;
        printf("%*s%s%*s| ", padlen, "", csv.array[0][j], strlen(csv.array[0][j]) % 2 ? padlen + 1 : padlen, "");
    }
    puts("");
    for(int i = 1; i < csv.row; i++) {
        printf("| ");
        for(int j = 0; j < csv.column; j++) {
            j >= 2 ? printf("%8s%-8c| ", csv.array[i][j], '%') : printf("%8s%-8s| ", csv.array[i][j], "");
        }
        puts("\b\b");
    }
}

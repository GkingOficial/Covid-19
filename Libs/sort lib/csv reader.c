#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int row;
    int column;
    char **array;
} CSV;

void readCsv(FILE *, CSV *);
void printArray(CSV , int );

int main(){
    FILE *file;
    CSV csv;
    
<<<<<<< HEAD:Libs/csv reader.c
    file = fopen("data2.csv", "r");
=======
    
    file = fopen("file.csv", "r");
>>>>>>> d2253bb427b2084aa09423dc9270c68727968ba0:Libs/sort lib/csv reader.c
    if(!file){
        puts("Invalid file! 666\n");
        exit(666);
    }
    readCsv(file, &csv);
}

void readCsv(FILE *f, CSV *c){
    char texto[100], *word;
    int i = 0, words_amount = 0;
    
    c -> array = NULL;
    c -> array = (char **)malloc(sizeof(char *) * words_amount);
    if(!c -> array){
        puts("Error allocating memory! 999");
        exit(999);
    }
    
    while(fgets(texto, 100, f)) {
        texto[strlen(texto) - 1] = '\0';
        word = strtok(texto, ",");
        while(word){
            c -> array[words_amount] = word;
            word = strtok(NULL, ",");
            words_amount++;
        }
        printArray(*c, words_amount);
        words_amount = 0;
    }
}

void printArray(CSV csv, int amount){
    printf("|");
    for(int i = 0; i < amount; i++){
        printf("%s, ", csv.array[i]);
    }
    puts("\b\b|");
}

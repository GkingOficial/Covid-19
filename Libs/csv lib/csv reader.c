#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int row;
    int column;
    char **array;
}CSV;

void readCsv(FILE *, CSV *);
void printArray(CSV , int );

int main(){
    FILE *file;
    CSV csv;
    
    file = fopen("file.csv", "r");
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
    // Talisson, por que aqui você não está alocando nada? words_amount deveria ter a quantidade de colunas que estaríamos trabalhando na nossa tabela do CSV não?
    
    if(!c -> array){
        puts("Error allocating memory! 999");
        exit(999);
    }
    
    while(fgets(texto, 100, f)) {
        // A função fgets coloca o '\0' automaticamente
        // Mas no caso tu colocou para substituir o '\n' né?
        
        printf("%s", texto);
        printf("Aqui está o \\n => %c <==\n", texto[strlen(texto) - 1]);
        texto[strlen(texto) - 1] = '\0';
        printf("%s", texto);

        printf("\n\n");
        word = strtok(texto, ",");

        while(word){
            puts(word);

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
    puts("\b\b|\n\n\n\n\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char *nome;
    int idade;
    char *sexo;
}PESSOA;
typedef struct{
    int row;
    int column;
    char **array;
}CSV;

void readCsv(FILE *, CSV *);
void printArray(CSV , int );

int main(){
    
    FILE *novosDoentes;
    CSV atributosPessoa;

    novosDoentes = fopen("file.csv", "r");
    readCsv(novosDoentes, &atributosPessoa);
}

void readCsv(FILE *f, CSV *c){
    char texto[100], *word;
    int i = 0, words_amount = 0, contadorDePessoas = 0;
    PESSOA *pessoas = NULL;
    
    c -> array = NULL;
    c -> array = (char **)malloc(sizeof(char *) * words_amount);
    // Talisson, por que aqui você não está alocando nada? words_amount deveria ter a quantidade de colunas que estaríamos trabalhando na nossa tabela do CSV não?
    
    if(c->array == NULL){
        puts("Error allocating memory! 999");
        exit(999);
    }
    
    while(fgets(texto, 100, f)) {
        contadorDePessoas++;
        // A função fgets coloca o '\0' automaticamente
        // Mas no caso tu colocou para substituir o '\n' né?
        
        texto[strlen(texto) - 1] = '\0';
        word = strtok(texto, ",");
        while(word) {
            c -> array[words_amount] = word;
            word = strtok(NULL, ",");
            words_amount++;
        }
        printf("%s\n", c->array[0]);
        printf("%d\n", atoi(c->array[1]));
        printf("%s\n", c->array[2]);

        // Não está dando certo
        // if(contadorDePessoas == 1) {
        //     pessoas = (PESSOA *)malloc(sizeof(PESSOA) * contadorDePessoas);
        // } else {
        //     pessoas = (PESSOA *)realloc(pessoas, sizeof(PESSOA) * contadorDePessoas);
        // }
        // strcpy(pessoas[contadorDePessoas - 1].nome, c->array[0]);
        // strcpy(pessoas[contadorDePessoas - 1].sexo, c->array[2]);
        // pessoas[contadorDePessoas - 1].idade = c->array[1];

        words_amount = 0;
    }
}

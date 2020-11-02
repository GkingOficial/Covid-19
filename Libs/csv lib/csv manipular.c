#include<csv manipular.h>
#include<../list/Lista encadeada com nó cabeçalho ordenada.h>

ORDERED_LINKED_LIST * readCsv(FILE *f, CSV *c){
    char texto[100], *word;
    int words_amount = 0, contadorDePessoas = 0;
    PESSOA *pessoas;
    
    c -> array = NULL;
    c -> array = (char **)malloc(sizeof(char *) * words_amount);
    if(c -> array == NULL){
        puts("Error allocating memory! 999");
        exit(999);
    }
    while(fgets(texto, 500, f)) {

        texto[strlen(texto) - 1] = '\0';
        word = strtok(texto, ", ");

        while(word){
            c -> array[words_amount] = word;
            word = strtok(NULL, ", ");
            words_amount++;
        }
        contadorDePessoas++;

        pessoas = (PESSOA *)realloc(pessoas, sizeof(PESSOA) * contadorDePessoas);
        strcpy(pessoas[contadorDePessoas - 1].nome, c->array[0]);
        strcpy(pessoas[contadorDePessoas - 1].sexo, c->array[2]);
        pessoas[contadorDePessoas - 1].idade = c->array[1];

        words_amount = 0;
    }
    return pessoas;
}
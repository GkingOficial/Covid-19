#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<../csv lib/csv manipular.h>
#include<../list/Lista encadeada com nó cabeçalho ordenada.h>


int main() {
    ORDERED_LINKED_LIST listOfPeople;
    FILE *novosDoentes;
    CSV ondeTemPessoa;
    PESSOA *pessoas;
    int i;

    novosDoentes = fopen("novosDoentes.csv", "r");
    createList(&listOfPeople);
    pessoas = readCsv(novosDoentes, &ondeTemPessoa);
    for(i=0;1; i++) {
        insertElement(listOfPeople, pessoas[i]);
    }
}

#include<stdio.h>
#include<stdlib.h>
#include<../list/Lista encadeada com nó cabeçalho ordenada.h>

void createList(ORDERED_LINKED_LIST *list) {
    (*list) = (NODO *)malloc(sizeof(NODO));
    if(!(*list)) {
        printf("\nUnfortunately, there is not store enough in list\n");
        exit(1);
    }
    (*list)->next = NULL;
    (*list)->value = 0;
}

int isEmpty(ORDERED_LINKED_LIST list) {
    return (list->value) == 0;
}

int lengthOfList(ORDERED_LINKED_LIST list) {
    return list->value;
}

void insertElement(ORDERED_LINKED_LIST list, int value) {
    NODO *alocado;
    alocado = (NODO *)malloc(sizeof(NODO));
    if(!alocado) {
        printf("\nUnfortunately, there is not store enough in list\n");
        exit(1);
    }
    list->value++;

    while((list->next) && (list->next)->value < value) {
        list = list->next;
    }
    alocado->value = value;
    alocado->next = list->next;
    list->next = alocado;
}

void insertElement2(ORDERED_LINKED_LIST list, int value) {
    insertElementWithRecursion(list, value);
    list->value++;
}

void insertElementWithRecursion(ORDERED_LINKED_LIST list, int value) {

    if((list->next) && (list->next)->value < value) {
        insertElementWithRecursion(list->next, value);
    } else {
        NODO *alocado;
        alocado = (NODO *)malloc(sizeof(NODO));
        if(!alocado) {
            printf("\nUnfortunately, there is not store enough in list\n");
            exit(1);
        }
        alocado->value = value;
        alocado->next = list->next;
        list->next = alocado;
    }
}

void deleteElement(ORDERED_LINKED_LIST list, int position) {
    NODO *aux;
    if(position < 1 || position > lengthOfList(list)) {
        printf("\nIsn't valid\n");
        exit(2);
    }
    list->value--;
    for(; --position; list = list->next);

    aux = (list->next)->next;
    free(list->next);
    list->next = aux;
}

void deleteElement2(ORDERED_LINKED_LIST list, int position) {
    if(position < 1 || position > lengthOfList(list)) {
        printf("\nIsn't valid\n");
        exit(2);
    }
    deleteElementWithRecursion(list, position);
    list->value--;
}

void deleteElementWithRecursion(ORDERED_LINKED_LIST list, int position) {
    if(position == 1) {
        NODO *aux = (list->next)->next;
        free(list->next);
        list->next = aux;
    } else {
        deleteElementWithRecursion(list->next, position - 1);
    }
}

int returnElement(ORDERED_LINKED_LIST list, int position) {
    if(position < 1 || position > lengthOfList(list)) {
        printf("\nIsn't valid\n");
        exit(2);
    }
    for(; position--; list = list->next);
    return list->value;
}

int returnElement2(ORDERED_LINKED_LIST list, int position) {
    if(position < 1 || position > lengthOfList(list)) {
        printf("\nIsn't valid\n");
        exit(2);
    }
    return returnElementWithRecursion(list, position);
}

int returnElementWithRecursion(ORDERED_LINKED_LIST list, int position) {
    if(position == 1) {
        return (list->next)->value;
    } else {
        returnElementWithRecursion(list->next, position - 1);
    }
}

void deleteRepeated(ORDERED_LINKED_LIST list) {
    NODO *aux;
    
    for(list = list->next;list && list->next;) {
        if(list->value == (list->next)->value) {
            aux = (list->next)->next;
            free(list->next);
            list->next = aux;
        } else {
            list = list->next;
        }
    }
}

ORDERED_LINKED_LIST concatenateList(ORDERED_LINKED_LIST list1, ORDERED_LINKED_LIST list2) {
    NODO *aux;
    int i, length2 = lengthOfList(list2);
    for(i=1; i<=length2; i++) {
        insertElement(list1, returnElement(list2, i));
    }
    deleteRepeated(list1);
    return list1;
}

ORDERED_LINKED_LIST concatenateList2(ORDERED_LINKED_LIST list1, ORDERED_LINKED_LIST list2) {
    int i;
    NODO *aux;
    ORDERED_LINKED_LIST newList;
    createList(&newList);
    
    for(i=1; i<=lengthOfList(list1); i++) {
        insertElement(newList, returnElement(list1, i));
    }
    for(i=1; i<=lengthOfList(list2); i++) {
        insertElement(newList, returnElement(list2, i));
    }
    deleteRepeated(newList);
    return newList;
}

void destroyListOtherwise(ORDERED_LINKED_LIST list) {
    NODO *aux = list->next;

    list->next = NULL;
    list->value = 0;

    while(aux) {
        NODO *aux1 = aux->next;
        free(aux);
        aux = aux1;
    }
}

void destroyList(ORDERED_LINKED_LIST list) {
    NODO *aux;
    while(list) {
        aux = list;
        list = list->next;
        free(aux);
    }
}

void destroyListWithRecursion(ORDERED_LINKED_LIST list) {
    if(list) {
        destroyListWithRecursion(list->next);
        free(list);
    }
}

void printList(ORDERED_LINKED_LIST list) {
    for(list = list->next; list; list = list->next) {
        printf("%i...", list->value);
    }
    printf("\n");
}
#include "list enc.h"

void createList(LIST *l){
    *l = NULL;
}

int isEmptyList(LIST l){
    return !l ? 1 : 0;
}

int listLenght(LIST l){
    if(!l){
        return 0;
    } else {
        return listLenght(l -> next) + 1;
    }
}

void insertElement(LIST *l, int position, char **string){
    if(position >= 1 && position <= listLenght(*l) + 1){
        if(position == 1){
            NODE *new_node;
            new_node = (NODE *)malloc(sizeof(NODE));
            if(!new_node){
                puts("Wasn't possible reservate memory!");
                exit(0);
            }
            
            new_node -> string = string;
            new_node -> next = *l;
            *l = new_node;
        } else {
            insertElement(&((*l) -> next), position - 1, string);
        }
    } else {
        puts("Invalid position!");
        exit(1);
    }
}
/*
char ** returnElement(LIST l, int position){
    if(position >= 1 && position <= listLenght(l)){
        if(position == 1){
            return l -> string;
        } else {
            return returnElement(l -> next, position - 1);
        }
    } else {
        puts("Invalid position!");
        exit(2);
    }
}
*/
void destroyList(LIST l){
    if(l){
        destroyList(l -> next);
        free(l);
    }
}

void printList(LIST l){
    LIST i;
    printf("| ");printf("%s, ", i -> string[1]);/*
    for(i = l; i; i = i -> next){
        for(int j; j < sizeof(l -> string); j++){
            
        }
    }*/
    puts("\b\b|");
}

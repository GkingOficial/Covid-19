#include<stdio.h>
#include<stdlib.h>

typedef struct nodo {
    int value;
    struct nodo *next;
}NODO;
typedef NODO *ORDERED_LINKED_LIST;

void insertElement(ORDERED_LINKED_LIST list, int value);
void insertElement2(ORDERED_LINKED_LIST list, int value);
void insertElementWithRecursion(ORDERED_LINKED_LIST list, int value);
int returnElement(ORDERED_LINKED_LIST list, int position);
int returnElement2(ORDERED_LINKED_LIST list, int position);
int returnElementWithRecursion(ORDERED_LINKED_LIST list, int position);
void deleteElement(ORDERED_LINKED_LIST list, int position);
void deleteElement2(ORDERED_LINKED_LIST list, int position);
void deleteElementWithRecursion(ORDERED_LINKED_LIST list, int position);
void destroyList(ORDERED_LINKED_LIST list);
void destroyListWithRecursion(ORDERED_LINKED_LIST list);
void destroyListOtherwise(ORDERED_LINKED_LIST list);
void createList(ORDERED_LINKED_LIST *list);
int isEmpty(ORDERED_LINKED_LIST list);
int lengthOfList(ORDERED_LINKED_LIST list);
void printList(ORDERED_LINKED_LIST list);
ORDERED_LINKED_LIST concatenateList(ORDERED_LINKED_LIST list1, ORDERED_LINKED_LIST list2);
void deleteRepeated(ORDERED_LINKED_LIST list);
ORDERED_LINKED_LIST concatenateList2(ORDERED_LINKED_LIST list1, ORDERED_LINKED_LIST list2);

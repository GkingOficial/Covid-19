#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int value;
    struct node * next;
}NODE;
typedef struct {
    NODE *firstNode;
    NODE *lastNode;
    int length;
}HEAD_NODE;
typedef HEAD_NODE *LINKED_LINE ;

void createLine(LINKED_LINE *line);
int isEmpty(LINKED_LINE line);
void insertElementIntoLine(LINKED_LINE line, int value);
int returnFirstElement(LINKED_LINE line);
void deleteFirstElement(LINKED_LINE line);
int returnAndDeleteElement(LINKED_LINE line);
void destroyLine1(LINKED_LINE line);
void destroyLine2(LINKED_LINE line);

void printLine(LINKED_LINE line);
int lengthOfLine(LINKED_LINE line);

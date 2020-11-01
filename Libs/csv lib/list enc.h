typedef struct node{
    char **string;
    struct node *next;
} NODE;

typedef NODE *LIST;

void createList(LIST *);
int isEmptyList(LIST );
int listLenght(LIST );
void insertElement(LIST *l, int , char **);
int returnElement(LIST l, char **);
void destroyList(LIST l);
void printList(LIST );

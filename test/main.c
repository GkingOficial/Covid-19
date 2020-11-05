#include <stdio.h>
#include <stdlib.h>

int main(){
<<<<<<< HEAD
  FILE *f = fopen('file.csv', 'r');
  int row = 0, column = 0;
  char c;
  
  while(c = getchar(f), !feof(f)){
    if(ch == ","){
      row++;
    }

    if(ch == '\n'){

    }
  }
  printf("Rows: %d\nColumns: %d\n", rows, column);
=======
  FILE *f = fopen("file.csv", "r");
  int rows = 1, columns = 1;
  char c;
  
  while(c = getc(f), c != '\n'){
    if(c == ','){
      columns++;
    }
  }
  
  while(c = getc(f), !feof(f)){
    if(c == '\n'){
      rows++;
    }
  }

  printf("Rows: %d\nColumns: %d\n", rows, columns);
>>>>>>> cdc06cca1c20c69e904825fd6e8ce1b37a6ace6e
}
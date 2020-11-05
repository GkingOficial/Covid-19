#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE *f = fopen("file.csv", "r");
  int rows = 0, columns = 1;
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
    //printf("*%c, ", c);
  }

  printf("\nRows: %d\nColumns: %d\n", rows, columns);
}
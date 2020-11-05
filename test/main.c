#include <stdio.h>
#include <stdlib.h>

int main(){
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
}
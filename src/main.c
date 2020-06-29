#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main ()
{
  char hello[] = "Hello world";
  char *str = hello;

  char array [30];
  while (1)
    {
      char* temp = str;
      List *strings;
      strings = init_history();

      printf("->");
      fgets(array, 29, stdin);
      char *str = &array[0];
      char** tokenizer = tokenize(str);
      print_tokens(tokenizer);
      
      add_history(strings, temp);
    }
}

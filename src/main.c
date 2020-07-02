#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int main ()
{
  char hello[] = "Hello world";
  char *str = hello;
  int id_tracker = 1;

  char array [30];
  while (1)
    {
      char* temp = str;
      List *strings;
      strings = init_history();

      printf("->");
      fgets(array, 29, stdin);
      char *str = &array[0];

      if (*str == 'q') // quit
	{
	  exit(0);
	}

      char** tokenizer = tokenize(str);
      print_tokens(tokenizer);

      List *list = init_history();

      //      char string[29] = *str;
      
      /*if (*str == "!1")
	{
	  print_tokens(tokenize(get_history(list,1)));
	}
      if (strcmp(*str,"!2"))
	{
	  print_tokens(tokenize(get_history(list,2)));
	}
      if (*str == "!3")
	{
	  print_tokens(tokenize(get_history(list,3)));
	}
      if (*str == "!4")
	{
	}
      */
      
      add_history(list, str);

      free_tokens(tokenizer);
      free_history(list);
      id_tracker++;
      get_history(list,1);
      
    }
}

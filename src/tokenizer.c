#include <stdio.h>
#include "tokenizer.h"
//#include "history.h"

int main ()
{
  char f = 'b';
  
  return 0;
}



int space_char(char c)
{
    if (c == ' ' || c == '\t')
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

int non_space_char(char c)
{
  if (space_char(c) == 0)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}


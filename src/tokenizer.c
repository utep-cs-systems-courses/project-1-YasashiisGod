#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if (c == ' ' || c == '\t')
    {
      return 1;
    }
  else
    return 0;
}

int non_space_char(char c)
{
  if (space_char(c))
    {
      return 0;
    }
  else
    return 1;
}

char *word_start(char *str);
{
  
}

char *word_terminator(char *word)
{
  
}

int count_words(char *str)
{
  
}

int count_words(char *str);
{
  
}

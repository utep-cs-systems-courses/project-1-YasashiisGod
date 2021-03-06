

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

char *word_start(char *str)
{
  while (!(non_space_char(*str)))
    {
      if (*str == '\0')
	{
	  return str;
	}
      str++;
    }
  return str;
}

char *word_terminator(char *word)
{
  if (!(non_space_char(*word)))
    {
      return word;
    }
  else
    {
      while (non_space_char(*word))
	{
	  word++;
	}
      return word;
    }
}

int count_words(char *str)
{
  if ((str!=NULL) && (str[0] == '\0'))
    {
      return 0;
    }
  int count = 1;
  while(*str++)
    {
      if (*str == ' ')
	{
	  count++;
	}
    }
  return count;
}


char *copy_str(char *inStr, short len)
{
  char *copy = (char*)malloc((len+1)*sizeof(char));
  short counter = 0;
  for (int i = 0; i < len; i++)
    {
      copy[counter] = inStr[counter];
      counter++;
    }
  copy[counter] = '\0';
  return copy;
}

// helper method getting word length (wasn't used)  
short word_length(char*str)
{
  char* temp = str;
  short size = 0;
  while (non_space_char(*temp))
    {
      temp++;
      size++;
    }
  return size;
}

char** tokenize(char* str)
{
  int count = count_words(str);
  char** tokens = (char**)malloc((count+1) * (sizeof(char*)));
  char* temp = str;
  for (int i = 0; i < count; i++)
    {
      temp = word_start(temp);
      tokens[i] = copy_str(temp, (word_terminator(temp) - word_start(temp)));
      temp = word_terminator(temp);
    }
  tokens[count] = '\0';
  return tokens;
}

int count_tokens(char** tokens)
{
  int counter = 0;
  while (*tokens != NULL)
    {
      counter++;
      tokens++;
    }
  return counter;
}

void print_tokens(char** tokens)
{
  int end = count_tokens(tokens);
  int counter = 0;

  printf("Tokens: %d\n", end+1);
  while (counter < end)
    {
      if (counter == (end-1))
	{
	  printf("token[%d] = %s", counter, *tokens);
	  printf("token[%d] = 0\n", counter+1);
	  counter++;
	}
      else
	{
	  printf("token[%d] = %s\n",counter, *tokens);
	  counter++;
	  tokens++;
	}
    }
  printf("-------------\n");
}



void free_tokens(char **tokens)
{
  for (int i = 0; tokens[i] != 0; i++)
    {
      free(tokens[i]);
    }
  free(tokens);
}

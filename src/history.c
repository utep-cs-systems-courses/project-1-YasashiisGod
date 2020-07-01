#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"
List* init_history()
{
  List *history = (List*)malloc(sizeof(List*));
  history->root = NULL;
  return history;
}



void add_history(List *list, char *str)
{
  char *temp = str;
  char *end = word_terminator(temp);
  char *start = word_start(temp);
  
  int length = end - start;
  //printf("This is a test,%d", len);
  int count = 1;

  if (list->root == NULL)
    {
      char *string_copy = copy_str(str, length);
      Item *newNode = (Item*)malloc(sizeof(Item));
      
}


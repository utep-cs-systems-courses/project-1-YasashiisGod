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
  int len = ((word_terminator(str))-(word_start(str)));
  printf("%d", len);
}


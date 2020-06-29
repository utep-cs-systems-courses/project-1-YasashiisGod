#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List *history = (List*)malloc(sizeof(List*));
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str)
{
  int len = len
}


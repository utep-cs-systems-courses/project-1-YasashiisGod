#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int id_tracker = 1;

List* init_history()
{
  List *history = (List*)malloc(sizeof(List*));
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str)
{
  Item* current;
  current = list -> root;
  
  if (list->root == NULL)
    {
      list-> root = (Item*)malloc(sizeof(Item));
      list-> root -> id = id_tracker++;
      list-> root -> str = str;
      list-> root-> next = NULL;
    }
  else
    {
      while (current->next != NULL)
	{
	  current = current->next;
	}
      current->next = (Item*)malloc(sizeof(Item));
      current->next->id = id_tracker;
      current->next->str = str;
      current->next->next = NULL;
    }
}

char *get_history(List *list, int id)
{
  Item* current = list->root;
  while (current != NULL)
    {
      if (current->id == id)
	{
	  return current->str;
	}
      current = current->next;
    }
}

void print_history(List *list)
{
  Item *current = list->root;
  while(current != NULL)
    {
      printf("%d.- %s", current->id, current->str);
      current = current->next;
    }
}

void free_history(List *list)
{
  Item *current = list->root;
  while (current != NULL)
    {
      free(current);
      current = current->next;
    }
  free(list);
}
/*
int get_input()
{
  int user_input = 0;
  int count = 0;
  while (user_input != 1 && user_input != 2 && user_input != 3)
    {
      if (count > 0)
	{
	  printf("Please Enter 1 - 3 \n");
	  printf("\n");
	}
      printf("User Input History\n");
      printf("--\n");
      printf("1. Search \n");
      printf("2. Print\n");
      printf("3. Quit\n");

      scanf("%d", &user_input);
      printf("\n");
      ++count;
    }
  return user_input;
}

char *search_history(List *list, char *str)
{
  char input[SEARCH_LIM];
  int is_exclamation = 0;
  int int_conv = 0;
  int i = 0;
  int num_words = count_words(str);
  char *found_str;

  while (is_exclamation == 0)
    {
      printf("Enter the command '!(number of string you would like to find)'\n");
      fgets(input, SEARCH_LIM, stdin);
      printf("\n");

      if (input[0] == '!')
	{
	  is_exclamation = 1;
	}
    }
  for (i = 1; input[i] >= '0' && input[i] <= '9'; i++)
    {
      int_conv = 10 * int_conv + (input[i] - '0');
    }
  if (int_conv > 0 && int_conv <= num_words)
    {
      found_str = get_history(list, int_conv);
    }
  else
    {
      printf("That string is not in history\n");
      printf("\n");
      found_str = NULL;
    }
  return found_str;
}

void history_UI(List *list, char *str)
{
  char *search_node;
  int user_input = 0;
  int search = 0;
  int print = 0;
  int quit = 0;

  user_input = get_input();
  printf("\n");

  if (user_input == 3)
    {
      quit = 1;
    }
  while (quit ==0)
    {
      if (user_input == 1)
	{
	  search_node = search_history(list, str);
	  if (search_node == NULL)
	    {
	      ;
	    }
	  else
	    {
	      printf("The string found in history\n");
	      printf("-->");
	      printf("%s", search_node);
	      printf("<---\n");
	      printf("\n");
	    }
	}
      else
	{
	  print_history(list);
	  printf("\n");
	}
      user_input = get_input();
      printf("\n");

      if (user_input == 3)
	{
	  quit = 1;
	}
    }
}
*/

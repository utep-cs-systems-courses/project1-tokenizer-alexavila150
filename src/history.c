#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List *list = (List*)malloc(sizeof(List));

  list->root = (Item*)malloc(sizeof(Item));

  list->root->id = 1;
  list->root->str = "My first message";

  return list;
}

void add_history(List *list, char *str)
{
  //Go to the end of the linked list
  Item *curr = list->root;
  int id = 1;
  while(curr->next != 0){
    curr = curr->next;
    id++;
  }
  
  curr->next = (Item*)malloc(sizeof(Item));
  curr->next->str = str;
  curr->next->id = id;
}

char *get_history(List *list, int id){
  printf("get history");
  return 0;
}

void print_history(List *list){
  Item *curr = list->root;
  while(curr != 0){
    printf("%d) %s\n", curr->id, curr->str);
    curr = curr->next;
  }
}

void free_history(List *list){
  printf("free history");
}

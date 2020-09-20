#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List *list = (List*)malloc(sizeof(List));
  list->root = (Item*)malloc(sizeof(Item));
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
  curr->next->next = 0;
  curr->next->str = str;
  curr->next->id = id;
}


char *get_history(List *list, int id){
  Item *curr = list->root->next;
  while(curr != 0){
    if(curr->id == id){
      return curr->str;
    }
    curr = curr->next;
  }
  return "id not found please choose a valid id";
}

void print_history(List *list){
  Item *curr = list->root->next;
  while(curr != 0){
    printf("%d) %s\n", curr->id, curr->str);
    curr = curr->next;
  }
}

void free_history(List *list){
  Item *curr = list->root->next;
  list->root->next = 0;
  // Case list is emtpy
  if(curr == 0){
    return;
  }

  // Keep track of the previous Item to erase it
  Item *prev = curr;
  curr = curr->next;
  while(curr != 0){
    free(prev->str);
    free(prev);
    prev = curr;
    curr = curr->next;
  }

  free(prev->str);
  free(prev);
}

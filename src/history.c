#include <stdio.h>
#include <stdlib.h>
#include "history.h"


List* init_history(){
  printf("init_history\n");
  List *list = malloc(sizeof(List));
 
  return list;
}

void add_history(List *list, char *str){
  printf("add history");
}

char *get_history(List *list, int id){
  printf("get history");
  return 0;
}

void print_history(List *list){
  printf("print history");
}

void free_history(List *list){
  printf("free history");
}

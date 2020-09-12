#include <stdio.h>
#include <stdlib.h>
#include "history.h"

void scan_sentence(char input[], int n);

int running(List* list);

int main()
{
  // Ask for user input
  printf("Welcome\n");

  List *list = init_history();
  int is_running = 1;
  while(is_running){
    printf("keep running\n");
    is_running = running(list);
  }
  printf("Thank you for coming\n");
}

int running(List* list){
  // Ask and read sentence
  printf("Choose an option ('a',enter sentence to store 'h' to see history, 'q' to quit)\n>");
  char option[2];
  scan_sentence(option, 2);

  // do option according to the user's request
  switch(option[0]){
    case 'q':
      printf("Case q\n");
      return 0;
    case 'h':
      printf("Case h\n");
      print_history(list);
      return 1;
  }

  printf("Case a\n");
  // ask for input
  printf("Enter your sentence:\n>");
  char* input = (char*)malloc(10 * sizeof(char));
  
  scan_sentence(input, 10);
  
  // add letter to the end of the list
  add_history(list, input);
}

// scans sentence from the user
// input-  is where the input will be store
// n-      is the limit of the input
void scan_sentence(char input[], int n){
  char ch;
  int i = 0;

  while((ch = getchar()) != '\n')
    if(i < n - 1)
      input[i++] = ch;

  input[i] = '\0';
}



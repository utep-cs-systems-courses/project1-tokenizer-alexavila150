#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

void scan_sentence(char input[], int n);

int running(List *list);

short is_number(char *str);

int main()
{
  // Ask for user input
  printf("Welcome\n");

  List *list = init_history();
  while(running(list));
  
  printf("Thank you for coming\n");
}

int running(List* list){
  // Ask and read sentence
  printf("Choose an option ('t' tokenize, 'h' see history, 'f', free history 'q' quit)\n>");
  char option[10];
  scan_sentence(option, 10);

  // do option according to the user's request
  switch(option[0]){
  case 'q':
    return 0;
  case 'h':
    print_history(list);
    return 1;
  case 'f':
    free_history(list);
    return 1;
  case '!':
    if(is_number(option + 1)){
      char* history = get_history(list, option[1] - 48);
      char **tokens = tokenize(history);
      print_tokens(tokens);
      
    }
    return 1;
  }

  // ask for input
  printf("Enter your sentence:\n>");
  char *input = (char*)malloc(100 * sizeof(char));
  scan_sentence(input, 100);

  //check if input is asking for history

  if(input[0] == '!' && is_number(input + 1)){
    printf("%s\n", get_history(list, input[1] - 48));
    return 1;
  }
  
  //tokenize the input
  char **tokens = tokenize(input);
  print_tokens(tokens);
  
  free_tokens(tokens);
  // add letter to the end of the list            
  add_history(list, input);
  return 1;
}

short is_number(char* str){
  //check if following chars are numbers
  while(*str != '\0'){
    if(*str < 48 || *str > 57){
      return 0;
    }
    str++;
  }
  
  return 1;
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















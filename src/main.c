#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

void scan_sentence(char input[], int n);

int running(List* list);

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
  printf("Choose an option ('a',enter sentence to store 'h' to see history, 'q' to quit)\n>");
  char option[2];
  scan_sentence(option, 2);

  // do option according to the user's request
  switch(option[0]){
    case 'q':
      return 0;
    case 'h':
      print_history(list);
      return 1;
  }

  // ask for input
  printf("Enter your sentence:\n>");
  char *input = (char*)malloc(100 * sizeof(char));
  scan_sentence(input, 100);
  
  //tokenize the input
  char **tokens = tokenize(input);
  print_tokens(tokens);
  char *token_str = (char*)malloc(100 * sizeof(char));
  char *curr = token_str;

  int word = 0;
  int letter = 0;
  for(int i = 0; i < 100; i++){
    curr[i] = tokens[word][letter];
    letter++;
    if(tokens[word][letter] == '\0'){
      letter = 0;
      word++;
      curr[++i] = ' ';
    }
    if(tokens[word] == 0){
      curr[++i] = '\0';
      break;
    }
  }
  
  
  // add letter to the end of the list            
  add_history(list, token_str);
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




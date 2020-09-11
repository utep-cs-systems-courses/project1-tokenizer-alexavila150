#include <stdio.h>
#include <stdlib.h>
#include "history.h"

void scan_sentence(char input[], int n);


int main()
{
  // Ask for user input
  printf("Enter a sentence to store:\n>");
  char input[10];
  scan_sentence(input, 10);
  printf("%s\n", input);

  List *list = init_history();

  //Ask user for another sentence
  add_history(list, "My second message");
}

// scans sentence from the user
// input is where the input will be store
// n is the limit of the input
void scan_sentence(char input[], int n){
  char ch;
  int i = 0;

  while((ch = getchar()) != '\n')
    if(i < n)
      input[i++] = ch;

  input[i] = '\0';
}




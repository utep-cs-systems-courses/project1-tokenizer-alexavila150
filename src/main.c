#include <stdio.h>
#include <stdlib.h>

int main()
{
  // Ask for user input
  printf("Enter a sentence to store:\n>");
  char input[10];
  scan_sentence(input, 10);
  printf("%s\n", input);
}

void scan_sentence(char input[], int n){
  char ch;
  int i = 0;

  while((ch = getchar()) != '\n')
    if(i < n)
      input[i++] = ch;

  input[i] = '\0';
}




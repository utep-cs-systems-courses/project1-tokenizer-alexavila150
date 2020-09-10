#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("Enter a sentence to store:\n>");

  //Ask user for input
  char input[200];
  scanf("%[^\n]", input);
  printf("%s\n", input);
}

#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if(c == '\t' || c == ' ')
    return 1;
  return 0;
}

int non_space_char(char c)
{
  if(c == '\t' || c == ' ' || c == '\0')
    return 0;
  return 1;
}

char *word_start(char *str)
{
  //if curr is a space keep moving to find a letter
  while(space_char(*str)){
    str++;
  }
  return str;
}

char *word_terminator(char *word)
{
  //if curr is not a space then go forward
  while(non_space_char(*word)){
    word++;
  }
  return word;
}

int count_words(char *str)
{
  int count = 0;

  //increase counter everytime a letter is found
  while(*str != '\0'){
    while(space_char(*str)){
      str++;
    }

    if(non_space_char(*str)){
      count++;
    }
    
    while(non_space_char(*str)){
      str++;
    }
  }
  
  return count;
}

char *copy_str(char *inStr, short len)
{
  // Allocate memory for the new string
  char *copy = (char*)malloc((len + 1) * sizeof(char));
  // Copy inStr into copy until len
  int i = 0;
  for(i = 0; i < len; i++){
    copy[i] = inStr[i];
  }

  // Make last element the zero terminator
  copy[len] = '\0';
  return copy;
}

char **tokenize(char* str)
{
  // get number of word of the str
  int num_words = count_words(str);
  char **tokens = (char**)malloc((num_words + 1) * sizeof(char*));
  
  // Allocate memory for each word and make each pointer in tokens point to one
  int i = 0;
  for(i = 0; i < num_words; i++){
    char* first_letter = word_start(str);
    str = word_terminator(first_letter);
    tokens[i] = copy_str(first_letter, str - first_letter);
  }
  
  tokens[i] = 0;
  return tokens;
}

void print_tokens(char **tokens)
{
  char **curr = tokens;
  while(*curr != 0){
    printf("%s ", *curr);
    curr++;
  }
  printf("\n");
}

void free_tokens(char **tokens)
{
  char **curr = tokens;
  printf("Before while loop\n");
  while(*curr != 0){
    printf("curr: %s\n", *curr);
    free(*curr);
    curr++;
  }
  printf("After while loop\n");
  free(tokens);
}









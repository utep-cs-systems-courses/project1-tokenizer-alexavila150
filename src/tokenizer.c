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
  while(non_space_char(*str)){
    str++;
  }

  while(space_char(*str)){
    str++
  }

  return str;
}

char *word_terminator(char *word){
  char *curr = word;
  int count = 0;
  while(curr != 0){
    curr++;
    count++;
  }

  char *terminated_word = (char*)malloc(++count * sizeof(char));
  int i = 0;
  terminated_word[0] = '\0';
  for(i = 0; i < count - 1; i++){
    terminated_word[i + 1] = word[1];
  }
  return terminated_word;
}

int count_words(char *str){
  int count = 0;

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

char **tokenize(char* str){
  int num_words = count_words(str);
  char **tokens = (char**)malloc((num_words + 1) * sizeof(char*));

  // Allocate memory for each word and make each pointer in tokens point to one
  int i = 0;
  for(i = 0; i < num_words; i++){
    tokens[0] = (char*)malloc(sizeof(char))
  }
  
  return char str**;
}

void print_tokens(char **tokens){
  
}

void free_tokens(char **tokens){

}









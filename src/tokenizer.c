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
    str++;
  }

  return str;
}

char *word_terminator(char *word){
  // make curr point to first char of word
  char *curr = word;

  // count how many letters word has
  int count = 0;
  while(non_space_char(*curr)){
    curr++;
    count++;
  }
  
  // allocate memory to store word
  char *terminated_word = (char*)malloc((count + 1) * sizeof(char));
  int i = 0;
  for(i = 0; i < count; i++){
    terminated_word[i] = word[i];
  }
  terminated_word[count] = '\0';
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
}

char **tokenize(char* str)
{
  // get number of word of the str
  int num_words = count_words(str);
  char **tokens = (char**)malloc((num_words + 1) * sizeof(char*));

  // Allocate memory for each word and make each pointer in tokens point to one
  int i = 0;
  for(i = 0; i < num_words; i++){
    tokens[i] = word_terminator(str);
    str = word_start(str);
  }
  
  return tokens;
}

void print_tokens(char **tokens){
  
}

void free_tokens(char **tokens){

}









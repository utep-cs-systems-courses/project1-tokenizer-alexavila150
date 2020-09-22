Project 1: Tokenizer
====================
# main.c

The main.c file was resposible for taking care of the user interface
functionality. This one will ask the user between many choices

- a: this one will ask the user to input a sentece which then it will store
 into the in the linked list produced they the history.c file.
- !n: the user can choose between to echo one the history stored sentences by
 typing '!' followed by a number which will represent the position of the node
 where the sentence is stored.
- f: this one will free the memory from the linked list and it will allowed
 the user to keep storing new information
- q: this will allow the user to quit and terminate the program

## scan_sentence

made this function in order to handle large input sentences if the user inputs
a large sentence then the array will stop storing chars and then places the
terminator at the end.

## running

I used this function as the main loop that will keep running until the method
returns zero the while loop in the main function will stop everything.

## is_number

Helper function that accepts the a char * and it returns 0 if the char is not
a pointer or returns 1 if it is a number.

# tokenizer.c

The tokenizer.c is used to echo the sentence the the user inputs but this one
deletes the spaces beetween each word and then store each individual word
allocated in memory and pointed by char * then all the char * for each word
will be store into an allocated array which we will call tokens by doing this
we will be able to print each work of the sentence without any extra spaces. 

# history.c

The history.c file is a file that handles the history functionality of that
the user inputs and stores the sentences that the user inputs.

The user also gets to to delete the history which the functions will handle it
by free every node and string allocated into those nodes so the user can start
inputing their sentences from scratch.

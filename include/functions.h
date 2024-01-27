
#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//compares two chars
int comp(char big, char small);
int comp_word(char *A,char *B,int length);
int decipher(int length,char* string);
float decipher_float(char *input,int length);
int word_size(char *A,int start_pos);
int word_pos(char *A,int start_pos,int amount);
int switch_input(int size_of_string_a,char* input,char*a,int*b);
void copy(char* copy_to,char* copy_from,int length);
void empty_str(char* a,int length);
int num_words(char* a);
void copy_textfile(char* name ,FILE* file);

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>




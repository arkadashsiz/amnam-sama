
#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <openssl/md5.h>

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

unsigned char command_detector(int argc,char *argv[],FILE* command_file,int number_commands);
int check_shiz_local_dir(char* file_dir);
int check_shiz_local_dir_rec(char* file_dir,int reverse_depth);
int find_shiz_local_dir(char*output,char* file_dir,int depth);
int check_global_dir();
void create_local_shiz_dir(char* e);
int check_file(char* dir);
int config_glob_name(int argc,char *argv[]);
int config_glob_alias(int argc,char *argv[]);
int config_glob_email(int argc,char *argv[]);
int config_name(int argc,char *argv[],char* current_dir);
int config_alias(int argc,char *argv[],char* current_dir);
int config_email(int argc,char *argv[],char* current_dir);


int comp_file(FILE* file1,FILE* file2);

void hash_file(FILE* file,unsigned char *out);
int send_file_to_stage(char* current_dir,char* file_loc);

int send_dir_to_stage(char* current_dir,char* dir_loc);
#endif






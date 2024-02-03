
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
#include <windowsx.h>
#include <MMsystem.h>
#include <conio.h>
#include <time.h>
#include <direct.h>
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET   "\033[0m"
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
void copy_textfile_withouttxt(char* name ,FILE* file);
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
int all_file_dirs(char* current_loc,char* file_dir_list[]);
int send_rec_to_stage(int size_of_shiz_dir,int size_of_cuurent_dir_string,char* current_dir,char* stage_dir);


void turn_str_to_list(char* string,char* list[]);

void append_str_to_str(char* str3,char* str1,char str2[]);

void listFilesRecursively(char *basePath,char* out_list);
void listFilesRecursively_with_depth(char *current_dir,char* out_list,int depth);
int copy_file(char* copy_to_dir,char* file_dir);
int send_to_storage(int size_of_shiz_dir,int size_of_cuurent_dir_string,char* file_or_dir,char* stage_dir,char* current_dir);

int check_if_staged(char* current_dir,char* stage_dir,char* shiz_dir);
void check_staged_rec(char* current_dir,char* stage_dir,char* shiz_dir,int depth);
void redo_stage(char* stage_dir,char* shiz_dir);
void unstage(char* stage_dir,char* shiz_dir,char* file_or_dir,char* current_dir);
void listFilesRecursively_stage(char *stage_dir,char* out_list);
void status(char* current_dir,char* stage_dir,char* shiz_dir);
void undo(char* stage_dir,char* shiz_dir);
int number_files(char* stage_dir);
int check_if_staged_reverse(char* file_or_dir,char* stage_dir,char* shiz_dir);
void commit(char* previous_branch,int number_files,char* user_name,char* current_branch,char* commit_message,char* stage_dir,char* storage_dir,char* shiz_dir);
void empty_dir(char* dir);
void show_commit_id(char* commit_id);
void logs(int how_many_you_want_you_cute_little_shit_i_hate_you,char* storage_dir);
void listFilesRecursively_noshiz(char* shiz_dir,char *current_dir,char* out_list);

int check_is_real_command(char* command);

void empty_shiz_dir(char* shiz_dir);
void branch(char* branch_name,char* current_branch,char* previous_branch,char* storage_dir);
void show_all_branches(char* storage_dir);
int compare_two_dates(int* a,int* b);
void sort_file_by_date(char* files[],int* nums[6],int length_arrays);

int send_rec_to_shiz(int size_of_shiz_dir,char* current_dir,char* stage_dir);
void check_out(char* branch_name,char* storage_dir,char* shiz_dir);
void n_before_head(char* output,int n,char* storage_dir);
void logs_branch(char* branch_name,char* storage_dir);
void logs_author(char* author_name,char* storage_dir);
void logs_time(int mode,char* time,char* storage_dir);
void logs_word(char* word,char* storage_dir);
void diff(char* file_loc1,char* file_loc2);
void read_file_without_nullspace(char* out,FILE* file);
int line_size(char *A,int start_pos);
int line_pos(char *A,int start_pos,int amount);
void turn_line_to_list(char* string,char* list[]);
void turn_str_to_list2(char* string,char* list[]);
void tree(char* storage_dir);
int dis_to_base(char* commit_name,char* storage_dir);
void diff_commits(char* id1,char* id2,char* storage_dir);
void merge(char* branch_1,char* branch_2,char* storage_dir,char* stage_dir,char* shiz_dir);
void revert_with_out_commit(char* pos_of_wanted_commit_to_revert,char* commit_id,char* storage_dir,char* shiz_dir);

#endif






#ifndef INVERT_H
#define INVERT_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stddef.h>
#include <ctype.h>

#define FAILURE -1
#define SUCCESS 0
#define FILE_EMPTY -2
#define FILE_NOT_AVAILABLE -3
//Structure for making a single linked list
typedef struct file_Name
 {
	char filename[50];
	struct file_Name *link;
 }file_node;
//Structure for sub node
typedef struct sub_node
 {
        int word_count;
	char filename[50];
	struct sub_node *sublink;
 }sub_t;
//Structure for main code
typedef struct main_node
 {
    int file_count;
    char word[20];
    struct main_node *mlink;
    sub_t *slink;
 }main_t;

typedef struct hash_table
 {
    int index;
    main_t *link;
 }hash_t;


//Function prototype
int f_validation(file_node **head, char *argv[]);
int isFileEmpty(char *file_name);
int create_database(file_node *f_head, hash_t *hashtable);
int create_main_node( hash_t  *head,char *data);
int create_subnode( main_t **head);
int update_word_count(main_t **head, char * filename);
int read_file(file_node *file, hash_t *head, char *filename);
int display_file(hash_t *head);
int for_print(main_t * head);
int search_db( hash_t *head,char *word);
int save_database(hash_t *head);
//t update(hash_t hashtable[],file_node **backuplist,file_node **head);
int update(hash_t hashtable[],file_node **bkhead,file_node **head);
int insert_last(file_node **head, char *argv);
int duplicate(file_node *head, char *argv);
#endif


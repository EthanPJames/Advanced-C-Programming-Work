#ifndef __ANSWER09_H__
#define __ANSWER09_H__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>


typedef struct _treenode {
    long int frequency; //Weight or amount of times something appears
    int info; //Whehter it is an ASCII value or not & time
    struct _treenode *left;
    struct _treenode *right;
    
} treenode;

typedef struct _lnode{
    treenode *tree; 
    struct _lnode *next;

} lnode;

int print_a_func1(char *filename, FILE *fp); //Prints out to output 1
int print_a_func2(char *filename, char *filename2, FILE *fp); //Prints out to output 2
int print_a_funct3(char *filename, treenode *tree); //Print out to file 3
lnode *put_back(lnode **pq, treenode *tree); //Insert node back
void pre_print_traversal(FILE *file_open, treenode *tree); //Helper print to output 2
void destroy_tree(treenode *tree); //Free tree
treenode *tree_create(lnode **list); //Create tree
int print_a_func4(char *filename); //Print to output 4
lnode *PQ_enqueue(lnode **pq, int new_object, long frequency); //Order the link nodes essentially

#endif


#ifndef __ANSWER05_H__
#define __ANSWER05_H__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

typedef struct _bFILE {
   FILE *fp;                //File to which I read or write to
   unsigned char buffer;    //How many valid bits in filed buffer
   unsigned char bit_index; //Keeps track of the postion index of the bits so you can supp.y corret bit
   unsigned char mode;      //If file is read or write
} bFILE;

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

//Suggested functions
bFILE *b_fopen(char *filename, char *mode);
int fgetbit(bFILE *bfp);
void fputbit(int bit, bFILE *bfp);
void b_fclose(bFILE *bfp); //????????????????????????? what is this error

//Copied Over from PE09
lnode *PQ_enqueue(lnode **pq, int new_object, long frequency); //Creates the link list here and put it within the tree
treenode *tree_create(lnode **list);
lnode *put_back(lnode **pq, treenode *tree);
void destroy_tree(treenode *tree);
int encode(bFILE *bfp, treenode *tree);
int decode(bFILE *bfp, treenode *tree);
//void pre_print_traversal(FILE *file_open, treenode *tree);
int call_output3_old(char *filename, char *filename2, FILE *fp); //??????????????????????????
void destroy_link_list(lnode *list);

//Functions I write
long *char_count(bFILE *file);
treenode *postorder_rebuild_tree(bFILE *bfp, treenode *tree);







#endif
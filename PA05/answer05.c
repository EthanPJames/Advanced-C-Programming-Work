#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>
#include "answer05.h"
//**********************************************************************************************************************************************
bFILE *b_fopen(char *filename, char *mode)
{
    bFILE *bfp = malloc(sizeof(*bfp));
    if(bfp == NULL)
    {
        
        return(NULL);
    }
    
    bfp->fp = fopen(filename, mode);
     
    if(bfp->fp == NULL)
    {
       
        return(NULL);
    }
     
    bfp->buffer = 0;
    bfp->bit_index = 0;
    bfp->mode = *mode;
    
    
    return(bfp);
}
//**********************************************************************************************************************************************
void fputbit(int bit, bFILE *bfp)
{
    bfp->buffer = (bfp->buffer) >> 1; //Takes it over to the least signifigant bit first
    if(bit == 1) //Might need to add to an or staetmnt with bit == 49?????????????????????????
    {
        bfp->buffer = ((128) | (bfp->buffer)); //Is this syntax correct
        
    }
    bfp->bit_index = bfp->bit_index + 1;

    if(bfp->bit_index == 8)
    {
        fputc(bfp->buffer, bfp->fp); //Insert buffer to the file
        bfp->bit_index = 0; //Reset the index
        bfp->buffer = 0; //Reset the buffer all to zeroes
    }
    return; 

}
//***********************************************************************************************************************************************
int fgetbit(bFILE *bfp)
{
    
    if(bfp->bit_index <= 0)
    {
        bfp->buffer = fgetc(bfp->fp); //Read the byte from bfp->fp
    }
    int bit = (bfp->buffer >> (bfp->bit_index)) & (1); //????Is this the correct mask?????????
    
    bfp->bit_index += 1;

    if(bfp->bit_index == 8)
    {
        bfp->bit_index = 0;
    }
    return(bit);  

}
//*************************************************************************************************************************************************
void b_fclose(bFILE *bfp)
{
    if(bfp->bit_index != 0)
    {
        while(bfp->bit_index != 0)
        {
            //bfp->buffer = ((bfp->buffer) >> (8 - bfp->bit_index)); //Shifts the buffer to include padding
            fputbit(0, bfp);
        }
        //fputbit(bfp->buffer, bfp->fp);
        //fputbit(0, bfp);
    }
    fclose(bfp->fp);
    free(bfp);
    return;

}
//**************************************************************************************************************************************************
lnode *PQ_enqueue(lnode **pq, int new_object, long frequency)
{
    lnode *new_node = malloc(sizeof(*new_node)); //Malloc for listnode
    if(new_node == NULL)
    {
        return(NULL);
    }
   
    treenode *tree_new = malloc(sizeof(*tree_new)); //Malloc for tree node
    if(tree_new == NULL)
    {
        return(NULL);
    }
    new_node->tree = tree_new;
    new_node->tree->info = new_object;
    new_node->tree->frequency = frequency;
    new_node->tree->left = NULL;
    new_node->tree->right = NULL;
   
    lnode dummy = {.next = *pq};
    lnode *prev = &dummy;
    lnode *cur = *pq;

    while(cur != NULL)
    {
   
        if(cur->tree->frequency > frequency) //Should work
        {
            
            break;
        }
        if(cur->tree->frequency == frequency)
        {
           
            if(cur->tree->info >= new_object)
            {
                
                break;
            }

        }
        prev = cur;
        cur = cur->next;
       
    }
    prev->next = new_node;
    new_node->next = cur;
    *pq = dummy.next;
  
   return(new_node);
   
}
//**********************************************************************************************************************************************
//Encoding uses pre order traversal of the tree so I can copy that function from PE09
treenode *tree_create(lnode **list)
{
    lnode *cur = *list; 
    if(cur == NULL)
    {
        
        return(NULL);
    }

    while(cur->next != NULL)
    {
        
        treenode *new = malloc(sizeof(*new));
        if(new == NULL)
        {
            
            return(NULL);
        }
        new->info = 0;
        //POP FUNCTION FROM KOH
        cur = *list;
        new->left = cur->tree;
       
        *list = cur->next;
        new->frequency = cur->tree->frequency;
        
        free(cur);
        cur = *list;

        
        new->right = cur->tree;
        *list = cur->next;
        
        new->frequency += cur->tree->frequency;
        free(cur);
        cur = *list;




        //END OF POP FUNCTION FROM KOH
        
        put_back(list, new);
        cur = *list; //may not require this
        
        //I dont think you need to set info to anything???????????????????????????????

    }
    treenode *new_end = cur->tree;
    
    free(*list); 
    
    return(new_end);

}

lnode *put_back(lnode **pq, treenode *tree)
{
   lnode *new_node = malloc(sizeof(*new_node)); //Malloc for listnode
   if(new_node == NULL)
   {
      return(NULL);
   }
   new_node->tree = tree;

   lnode dummy = {.next = *pq};
   lnode *prev = &dummy;
   lnode *cur = *pq;
    while(cur != NULL)
    {
       
        if(cur->tree->frequency > tree->frequency) //Should work
        {
           break;
        }
        prev = cur;
        cur = cur->next;
        
    }
    prev->next = new_node;
    new_node->next = cur;
    *pq = dummy.next;
  
   return(new_node);


}
//***************************************************************************************************************************************************
//DO I NEED A DEQUE FUNCTION???????????????????????????????????????????????????????????????????????????
long *char_count(bFILE *bfp)
{
    long *count = calloc(256, sizeof(*count));
    if(count == NULL)
    {
        return(NULL);
    }
    fseek(bfp->fp, 0, SEEK_SET); 
    int index = fgetc(bfp->fp);
    while(index != EOF) //Check later to iterate to the file????????????????????????????????????
    {
        count[index] += 1;
        index = fgetc(bfp->fp);

    }
    return(count);
}
//****************************************************************************************************************************************************************
void destroy_tree(treenode *tree)
{
   if (tree == NULL) {
      return;
   }
   destroy_tree(tree->left);
   destroy_tree(tree->right);
   free(tree);
   return;
   
}
//**********************************************************************************************************************************************//
//Need to modify this function at the end of the code
//Print to 3rd output file
//*******************************************************************************************************************************************************
treenode *postorder_rebuild_tree(bFILE *bfp, treenode *tree)
{
    tree = malloc(sizeof(*tree)); //Might have to make a new node
    if(tree == NULL)
    {
        return(NULL);
    }
    tree->left = NULL;
    tree->right = NULL;
    char bit_count = 0;
    if(fgetbit(bfp) == 1)
    {
        bit_count |= (fgetbit(bfp)); 
        bit_count |= (fgetbit(bfp) << 1);
        bit_count |= (fgetbit(bfp) << 2);
        bit_count |= (fgetbit(bfp) << 3);
        bit_count |= (fgetbit(bfp) << 4);
        bit_count |= (fgetbit(bfp) << 5);
        bit_count |= (fgetbit(bfp) << 6);
        bit_count |= (fgetbit(bfp) << 7);
        //Possible reverse order?????????????????????????????????
        tree->info = bit_count;
        return(tree);
    }
    tree->left = postorder_rebuild_tree(bfp, tree->left);
    tree->right = postorder_rebuild_tree(bfp, tree->right);

    return(tree);
}

//************************************************************************************************************************************************
int encode(bFILE *bfp, treenode *tree)
{
    if(tree == NULL)
    {
        return(1);
    }
    if(tree->right == NULL)
    {
        fputbit(1, bfp);
        int i = 0;
        int bit;
        
        while(i < 8)
        {
            bit = tree->info & (1 << i);
            fputbit(bit >> i, bfp);
            i++;
        }
        return(1);
    }
    fputbit(0, bfp);
    encode(bfp, tree->left);
    encode(bfp, tree->right);
    
    
    return(1);



}


//***********************************************************************************************************************************************
//Print to 2nd output File
int decode(bFILE *bfp, treenode *tree)
{
    
    if(tree->right == NULL)
    {
        fputbit(1, bfp);
        int i = 0;
        int bit = 0;
        
        while(i < 8)
        {
            bit = tree->info & (1 << i);
            fputbit(bit >> i, bfp);
            i++;
        }
        return(1);
    }
    
    decode(bfp, tree->left);
    decode(bfp, tree->right);
    fputbit(0, bfp);
    
    return(1);



}
//************************************************************************************************************************************************
void destroy_link_list(lnode *list)
{
    while(list != NULL)
    {
        lnode *temp = list->next;
        destroy_tree(list->tree); //Might not need
        free(list);
        list = temp;
    }
    return;
}
//**********************************************************************************************************************************************
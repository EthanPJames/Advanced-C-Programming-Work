#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>
#include "answer05.h"


int main(int argc, char **argv)
{
    //Make sure there are enough arguments
    if(argc != 4)
    {
        return(EXIT_FAILURE);
    }
    int encoding = strcmp(argv[1], "-e");
    int decoding = strcmp(argv[1], "-d");
    
    
    int i = 0;
    if(encoding == 0)
    {
       
        bFILE *input_open = b_fopen(argv[2], "r");
        
        if(input_open == NULL)
        {
           
            return(EXIT_FAILURE);
        }
        bFILE *output_open = b_fopen(argv[3], "w");
        if(output_open == NULL)
        {
          
            b_fclose(input_open);
            return(EXIT_FAILURE);
        }
        long *array = char_count(input_open);
        lnode *pq = NULL;
        
        while(i < 256)
        {
            if(array[i] != 0)
            {
                PQ_enqueue(&pq, i, array[i]);
            }
            i++;
        }
        
        free(array);

        treenode *tree_original = tree_create(&pq); 
        
        encode(output_open, tree_original);
        

        destroy_tree(tree_original);
        
        b_fclose(input_open);
        
        b_fclose(output_open);
        
    }
    else if(decoding == 0)
    {
        
        bFILE *input_open = b_fopen(argv[2], "r");
        //Check that input file can be opened
        if(input_open == NULL)
        {
            return(EXIT_FAILURE);
        }
        bFILE *output_open = b_fopen(argv[3], "w");
        if(output_open == NULL)
        {
            b_fclose(input_open);
            return(EXIT_FAILURE);
        }
       
        int seek = fseek(input_open->fp, -1l, SEEK_END);
        
        if(seek == -1)
        {
            
            
            fclose(input_open->fp);
            fclose(output_open->fp);
            free(input_open);
            free(output_open);
            return(EXIT_SUCCESS);

        }
        fseek(input_open->fp, 0, SEEK_SET);
         treenode *tree_post = NULL;
         tree_post = postorder_rebuild_tree(input_open, tree_post);
        
         decode(output_open, tree_post);
        
         destroy_tree(tree_post);

        b_fclose(input_open);
        b_fclose(output_open);
    }
    else
    {
        
        return(EXIT_FAILURE);
    }
    
    //How do i free tree and link list and my calloc
    return(EXIT_SUCCESS);
    
}
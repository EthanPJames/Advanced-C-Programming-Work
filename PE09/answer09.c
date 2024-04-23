#include "answer09.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

//*****************************************************************************************************************************************************
//This function creates the priority que for the list nodes
//Do i need to malloc for the tree here or add the entire tree here??????????????????????
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


//*****************************************************************************************************************************************************
//Create tree function - should be a recursive call
treenode *tree_create(lnode **list)
{
    lnode *cur = *list; 
    if(cur == NULL)
    {
        printf("1\n\n");
        return(NULL);
    }

    while(cur->next != NULL)
    {
        printf("2\n\n");
        treenode *new = malloc(sizeof(*new));
        if(new == NULL)
        {
            printf("3\n\n");
            return(NULL);
        }
        new->info = 0;
        //POP FUNCTION FROM KOH
        cur = *list;
        new->left = cur->tree;
        printf("4\n\n");
        *list = cur->next;
        new->frequency = cur->tree->frequency;
        printf("5\n\n");
        free(cur);
        cur = *list;

        
        new->right = cur->tree;
        *list = cur->next;
        printf("6\n\n");
        new->frequency += cur->tree->frequency;
        free(cur);
        cur = *list;




        //END OF POP FUNCTION FROM KOH
        printf("7\n\n");
        put_back(list, new);
        cur = *list; //may not require this
        printf("8\n\n");
        //I dont think you need to set info to anything???????????????????????????????

    }
    treenode *new_end = cur->tree;
    printf("9\n\n");
    free(*list); 
    printf("10\n\n");
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





//********************************************************************************************************************************************************
void destroy_tree(treenode *tree)
{
   if (tree == NULL) {
      return;
   }
   destroy_tree(tree->left);
   destroy_tree(tree->right);
   free(tree);
   
}


//**********************************************************************************************************************************************//
//Print to file one
int print_a_func1(char *filename, FILE *fp)
{
    FILE *open = fopen(filename, "wb");
    if(open == NULL)
    {
        return(0);
    }
    
    long int array[256] = {0}; //???Should be 256 I beleive?????????????
    fseek(fp, 0, SEEK_SET); 
    int index = fgetc(fp);
    while(index != EOF) //Check later to iterate to the file????????????????????????????????????
    {
        array[index] += 1;
        index = fgetc(fp);

    }
    
    fwrite(array, sizeof(array[0]), 256, open); //Write the entire array to the file output
    fclose(open);
    return(1);
    //Debugging
    //run a dif command to debug compare between this and output file
    //print the array and see whats happening

}
//***********************************************************************************************************************************************//
//Print to 2nd output File
int print_a_func2(char *filename, char *filename2, FILE *fp)
{
    FILE *open = fopen(filename, "w");
    if(open == NULL)
    {
        return(0);
    }
    //Create Link lIst start
    //Copied code start
  
    long int array[256] = {0};
    fseek(fp, 0, SEEK_SET); 
    int index = fgetc(fp);
    while(index != EOF) 
    {
        array[index] += 1;
        index = fgetc(fp);

    }
 
    //Copied code end
    lnode *newnode = NULL;
    
    for(int i = 0; i < 256; i++)
    {
        
        //Create link list
        if(array[i] != 0) //changed weight->array
        {
           
            PQ_enqueue(&newnode, i, array[i]); //changed weight to array-> Added new2
            
            
        }
    }
   
    //Create Link list end
    lnode *currently = newnode;
    while(currently != NULL)
    {
      

        fprintf(open, "%c", currently->tree->info); //If i fprintf a character will it automatically bring me down to a new line???????????
        fprintf(open,":");
        fprintf(open, "%ld", currently->tree->frequency);
        fprintf(open, "->");


        currently = currently->next;
        
    }
   
    
    fprintf(open, "NULL");

    treenode *tree_call =  tree_create(&newnode);
   
    int retrun3 = print_a_funct3(filename2, tree_call);
    if(retrun3 == 0)
    {
        fclose(open);
        destroy_tree(tree_call);
        return(0);
    }
    


    

    fclose(open);
    destroy_tree(tree_call);
    return(1);

}
//**********************************************************************************************************************************************//

//Print to 3rd output file
int print_a_funct3(char *filename, treenode *tree)
{
    FILE *open = fopen(filename, "w");
    if(open == NULL)
    {
        return(0);
    }
    

    fseek(open, 0, SEEK_SET);
   
    pre_print_traversal(open, tree);
    
    fclose(open);
    return(1);



}

void pre_print_traversal(FILE *file_open, treenode *tree)
{
    if(tree == NULL)
    {
        printf("Enter 1\n\n");
        return;
    }
    if(tree->info < 32)//Nothing inside the node making a non-leaf node and we want to print 0 Check to see if nothing below 32
    {
        printf("Enter 2\n\n");
        fprintf(file_open, "0");
        
    }
    else
    {
        printf("Enter 3\n\n");;
        fprintf(file_open, "1");
        fprintf(file_open, "%c", tree->info);
    }
    pre_print_traversal(file_open, tree->left);
    pre_print_traversal(file_open, tree->right);
    printf("Enter 4\n\n");

}
//***********************************************************************************************************************************************


//Printf to fourth output file
//Possible Extra credit
int print_a_func4(char *filename)
{
    FILE *open = fopen(filename, "w");
    if(open == NULL)
    {
        return(0);
    }
    fclose(open);
    return(1);
}

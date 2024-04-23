//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "answer06.h"
#include <limits.h>
#include <math.h>

//How do I know the information in the file matches the program inputs???????????

int main(int argc, char **argv)
{
  
  tiling_solution *variables = malloc(sizeof(*variables)); 

  if(argc != 6)
  {
    return(EXIT_FAILURE);
  }
  //Assgining strotl conversions of inputted values
  char *endptr;
  variables->floor_length = strtol(argv[1], &endptr, 10); ///??Should this be string to long conversion or double conversion
  variables->row = strtol(argv[2], &endptr, 10);
  variables->column = strtol(argv[3], &endptr, 10);

  
  
  if(variables->floor_length < 1)
  {
    return(EXIT_FAILURE);
  }
  if(variables->floor_length >= INT_MAX)
  {
    return(EXIT_FAILURE);
  }
  
  if(variables->row < 1)
  {
    return(EXIT_FAILURE);
  }
  if(variables->row >= INT_MAX)
  {
    return(EXIT_FAILURE);
  }
 
  if(variables->column < 1)
  {
    return(EXIT_FAILURE);
  }
  if(variables->column >= INT_MAX)
  {
    return(EXIT_FAILURE);
  }
  variables->floor_content = allocate_2d_array(variables->floor_length); 
  
   

   int det = determine_tiling_solution_category(argv[4], variables); 
   int save = save_tiling_solution(argv[5], variables); 
   

    printf("Enter here");
   if(det != 0)
   {
    fprintf(stdout, "%d\n", det);
   }
   if(save == 1)
   {
    fprintf(stdout, "%d\n", VALID_SOLUTION);
   }
   else
   {
    fprintf(stdout, "%d\n", INVALID_OUTPUT_FILE);
   }
   free_2d_array(variables->floor_content, variables->floor_length);
   free(variables);




  
 
  
  

  //Free the memory
 

  return(EXIT_SUCCESS); 
}
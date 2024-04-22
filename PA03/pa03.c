//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "answer03.h"
#include <limits.h>
#include <math.h>

//How do I know the information in the file matches the program inputs???????????

int main(int argc, char **argv)
{
  
  tiling_solution *variables = malloc(sizeof(*variables)); 
  //tiling_solution variables;
  //tiling_solution *variables = malloc(size(*variables)); //I dont know if I need to malloc 

  if(argc != 6)
  {
    return(EXIT_FAILURE);
  }
  //Assgining strotl conversions of inputted values
  char *endptr;
  variables->floor_length = strtol(argv[2], &endptr, 10); ///??Should this be string to long conversion or double conversion
  variables->row = strtol(argv[3], &endptr, 10);
  variables->column = strtol(argv[4], &endptr, 10);
  char v_arg = strcmp(argv[1], "-v");
  char g_arg = strcmp(argv[1], "-g");

  
  
  if(variables->floor_length < 1)
  {
    free(variables);
    return(EXIT_FAILURE);
  }
  if(variables->floor_length >= INT_MAX)
  {
    free(variables);
    return(EXIT_FAILURE);
  }
  
  if(variables->row < 0)
  {
    free(variables);
    return(EXIT_FAILURE);
  }
  if(variables->row >= INT_MAX)
  {
    free(variables);
    return(EXIT_FAILURE);
  }
 
  if(variables->column < 0)
  {
    free(variables);
    return(EXIT_FAILURE);
  }
  if(variables->column >= INT_MAX)
  {
    free(variables);
    return(EXIT_FAILURE);
  }
  if(variables->row >= variables->floor_length)
  {
    free(variables);
    return(EXIT_FAILURE);

  }
  if(variables->column >= variables->floor_length)
  {
    free(variables);
    return(EXIT_FAILURE);
  }

  variables->floor_content = allocate_2d_array(variables->floor_length); 
  if(v_arg == 0)
  {
    
    int det = determine_tiling_solution_category(argv[5], variables); 
    
   

    
    if(det != 0)
    {
      fprintf(stdout, "%d\n", det);
    }
    else
    {
      
      fprintf(stdout, "%d\n", VALID_SOLUTION);
      //free_2d_array(variables->floor_content, variables->floor_length); //???Should this be here
      //free(variables);
    }

  }
  else if(g_arg == 0)
  {
    /*int det = determine_tiling_solution_category(argv[5], variables); 
    if(det != 0)
    {
      free_2d_array(variables->floor_content, variables->floor_length);
      free(variables);
      return(EXIT_FAILURE);
    }*/
    generate_tiling_solution(variables);
    int save = save_tiling_solution(argv[5], variables); //?????????????DO I call this here even though it is an int??????????????????????????????
    if(!save)
    {
      free_2d_array(variables->floor_content, variables->floor_length);
      free(variables);
      return(EXIT_FAILURE);

    }
    //How do I sasve the tiling solution to the file


  }
  else
  {
    
    free_2d_array(variables->floor_content, variables->floor_length);
    free(variables);
    return(EXIT_FAILURE);
  }
  
   
   free_2d_array(variables->floor_content, variables->floor_length);
   free(variables); //Do i need to free this??????

 

  return(EXIT_SUCCESS); 
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "answer05.h"
#include <limits.h>


      
int main(int argc, char **argv)
{
  int cat; //Categroy function
  if (argc != 2)
  {
    return(EXIT_FAILURE);
  }
  cat = determine_tiling_solution_category(argv[1]);
  fprintf(stdout, "%d\n", cat);

  
  

   

  return(EXIT_SUCCESS); 
}

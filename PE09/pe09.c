//Remeber to check for argv = 6
//Remeber to open fp and make sure input file is openable do it normally

#include <stdlib.h>
#include <stdio.h>
#include "answer09.h"

int main(int argc, char **argv)
{
  if(argc != 6)
  {
    return(EXIT_FAILURE);
  }

  FILE *input_file = fopen(argv[1], "r");
  if(input_file == NULL)
  {
    return(EXIT_FAILURE);
  }
  //int index = 0; //pass into the create tree file it will be update everytime 

  //Print to the output Files
  int out1 = print_a_func1(argv[2], input_file);
  if(out1 != 1)
  {
    //Must free memory here???????????????????
    fclose(input_file);
    return(EXIT_FAILURE);
  }
  int out2 = print_a_func2(argv[3], argv[4], input_file);
  if(out2 != 1)
  {
    //Must free memory here???????????????????
    fclose(input_file);
    return(EXIT_FAILURE);
  }

  
  int out4 = print_a_func4(argv[5]); //Extra credit parameters could be wrong?????????????????????
  if(out4 != 1)
  {
    
    fclose(input_file);
    return(EXIT_FAILURE);
  }

  //Insert Free calls here

    //Must free memory here???????????????????
    fclose(input_file);
    return(EXIT_SUCCESS); 
}
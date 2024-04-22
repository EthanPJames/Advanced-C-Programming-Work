
#include <stdlib.h>
#include <stdio.h>

#include "answer02.h"
#include "aux02.h"
#include "utility02.h"
#include <limits.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
   
   char *endptr;
   integrand variables; //Define intergrand varaibles
   fourier fourier_arg; //Define variables in fourier

   // check for correct number of arguments.  If not, exit and return 
   // exit_failure
    if (argc != 7) 
   {
      
      return(EXIT_FAILURE);
   }

   //DO I NEED THIS
   char one_arg[3] = "1\0"; //1 unknown function
   char two_arg[3] = "2\0"; //2 uknown function
   char three_arg[3] = "3\0"; //3 uknown function //Check to see if the 1 is correct?

   int one_check = strcmp(one_arg, argv[1]); //Will be 0 if 1
   int two_check = strcmp(two_arg, argv[1]); //Will be 0 if 2
   int three_check = strcmp(three_arg, argv[1]); //Will be 0 if 3
   
   

   if ((one_check != 0) && (two_check != 0) && (three_check != 0))
   {
      
      
      return(EXIT_FAILURE); 
   }
   //DO I NEED THIS

   // now, try to parse the arguments and call the correct function
  

   // fill in the correct statements to complete the main function
   // we expect six arguments:
   //
   // the first argument is 1 character from the sets {"1", "2", "3"}
   // it specifies the unknown function for which we are computing
   // the associated Fourier series
   // 1:  unknown_function_1
   // 2:  unknown_function_2
   // 3:  unknown_function_3
   // otherwise: return EXIT_FAILURE
    if (strcmp(argv[1], "1") == 0)
   {
      
      variables.func_to_be_integrated = unknown_function_1;
   }
   else if (strcmp(argv[1], "2") == 0)
   {
     variables.func_to_be_integrated = unknown_function_2;  
   }
   else if (strcmp(argv[1], "3") == 0)
   {
       variables.func_to_be_integrated = unknown_function_3;
      
   }
   else
   {
      return(EXIT_FAILURE);
   }
 
    
   // to compute the Fourier series, specify the range over which we 
   // want to perform the integration, the next two arguments
   // should specify the lower limit (double) and upper limit (double)
   // of the range
   variables.lower_limit = strtod(argv[2], &endptr); //Changing the lower limit to a double 
   variables.upper_limit = strtod(argv[3], &endptr); //Changing the upper limit to a double 
   variables.n_intervals = strtol(argv[4], &endptr, 10); //Changes interval to long

   //
   // see PE03 and PE04 regarding the conversion
   // 
   // if lower limit == upper limit, return EXIT_FAILURE
   if (variables.lower_limit == variables.upper_limit)
   {
      return(EXIT_FAILURE);
   }
    if (isinf(variables.lower_limit) == 1)
   {
      return(EXIT_FAILURE);
   }
   
   if (isinf(variables.upper_limit) == 1)
   {
      return(EXIT_FAILURE);
   }
   if(variables.n_intervals < 1)
   {
      return(EXIT_FAILURE);
   }
   if(variables.n_intervals >= INT_MAX)
   {
      return(EXIT_FAILURE);
   }
   

   fourier_arg.n_terms = strtol(argv[5], &endptr, 10); //Convert N terms to a long
  

   if(fourier_arg.n_terms > INT_MAX)
   {
      return(EXIT_FAILURE);
   }
    if(fourier_arg.n_terms < 1)
   {
      return(EXIT_FAILURE);
   }
   
   fourier_arg.intg = variables;

   // the next argument specifies the number of intervals (int) to be used
   // for integration
   //
   // see PE03 and PE04 regarding the conversion

   // the next argument specifies the number of terms (int) in the
   // Fourier series
   //
   // see similar conversion as in PE03 and PE04

   // the next argument is the name of the file to store the coefficients
 
   // fill in the fields of fourier_arg properly and call the correct
   // functions to compute the coefficients and to save the coefficients

   //fourier_arg.n_terms = 0;  // you should change this, this is initialized
                             // so that the following statements are fine

   // based on fourier_arg.nterms
   // allocate space for fourier_arg.a_i and fourier_arg.b_i;

   fourier_arg.a_i = (double *)malloc(sizeof(*(fourier_arg.a_i))*fourier_arg.n_terms);
   if (fourier_arg.a_i == NULL) {
      return EXIT_FAILURE;
   }
   fourier_arg.b_i = (double *)malloc(sizeof(*(fourier_arg.b_i))*fourier_arg.n_terms);
   if (fourier_arg.b_i == NULL) {
      free(fourier_arg.a_i);
      return EXIT_FAILURE;
   }
////CALL THE COEFFICIENTS FUNCTION


   
   // add code to compute Fourier coefficients and save them in a file

   fourier_coefficients(fourier_arg);
   
   
   //Call the coefficents functions
  
   char* filename = argv[6]; //File its going too DO WE NEED *
   
   save_fourier_coefficients(fourier_arg.a_i, fourier_arg.b_i, fourier_arg.n_terms, filename);

   //Tester function
   //function_plot((unknown_function_1),  variables.lower_limit, variables.upper_limit,fourier_arg.a_i, fourier_arg.b_i, fourier_arg.n_terms, "test.m");

   free(fourier_arg.a_i);
   free(fourier_arg.b_i);

   return EXIT_SUCCESS;
} 



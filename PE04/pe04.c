#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "aux04.h"
#include "answer04.h"
#include <limits.h>

// fill in the correct statements to complete the main function
// we expect four arguments:
//
// the first argument is from the sets {"1", "2", "3"}
// it specifies the unknown function to be integrated
// 1:  unknown_function_1
// 2:  unknown_function_2
// 3:  unknown_function_3
// otherwise: return EXIT_FAILURE

// to integrate any of the three functions, expect the next three 
// arguments to be the lower limit of the integration (double), 
// the upper limit of the integration (double), and the number of 
// intervals for the integration (int)

// use strtod to convert an argument to a double
// use strtol to convert an argument to a long (and then to an int)
// check that the arguments are of the correct format and within range

// You should declare a variable of type integrand.  You should use the four 
// arguments to initialize the structure, and pass the structure to the 
// simpson's method

// after printing the integral, return EXIT_SUCCESS
      
int main(int argc, char **argv)
{
   double integral = 0.0;
   integrand variables; //Variables for the integrand specificed in the my struct
   

   //Checks from last code
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
   
   if (argc != 5) 
   {
      
      return(EXIT_FAILURE);
   }

   //Check to make sure you are integrating one of the unknown fuctions **FIX IT**
   if (strcmp(argv[1], "1") == 0)
   {
      
      variables.func_to_be_integrated = &unknown_function_1;
   }
   else if (strcmp(argv[1], "2") == 0)
   {
     variables.func_to_be_integrated = &unknown_function_2;  
   }
   else if (strcmp(argv[1], "3") == 0)
   {
       variables.func_to_be_integrated = &unknown_function_3;
      
   }
   else
   {
      return(EXIT_FAILURE);
   }



   char *endptr; 
   variables.lower_limit = strtod(argv[2], &endptr); //Changing the lower limit to a double 
   variables.upper_limit = strtod(argv[3], &endptr); //Changing the upper limit to a double 
   variables.n_intervals = strtol(argv[4], &endptr, 10); //Changes interval to long

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

   // you job is to fill in the fields of a variable of type integrand 
   // and pass the variable to simpson_numerical_integration

    if(one_check == 0)
   {
      
      
      integral = simpson_numerical_integration(variables);
   }
   if (two_check == 0)
   {
      
      integral = simpson_numerical_integration(variables);
   }
    if (three_check == 0)
   {
      
      integral = simpson_numerical_integration(variables);
   }
   

   

   fprintf(stdout, "%.10e\n", integral);
   return EXIT_SUCCESS;
}

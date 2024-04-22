#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include "answer03.h"

int main(int argc, char **argv)
{
   double integrand = 0.0;

   //If we don't have right amount of arguments
   if (argc != 5) 
   {
      
      return(EXIT_FAILURE);
   }

   char m_arg[3] = "-m\0"; //midpoint string
   char t_arg[3] = "-t\0"; //trapezoid string

   int m_check = strcmp(m_arg, argv[1]); //Will be 0 if -m
   int t_check = strcmp(t_arg, argv[1]); //Will be 0 if -t


   //If the command line argument was invalid
   if ((m_check != 0) && (t_check != 0))
   {
      
      
      return(EXIT_FAILURE); 
   }
   
   

   
   char *endptr; 

   double lim_low = strtod(argv[2], &endptr); //Changing the lower limit to a double ??
   double lim_up = strtod(argv[3], &endptr); //Changing the upper limit to a double ??
   long interval = strtol(argv[4], &endptr, 10); //Changes interval to long
   

   
   
   //MUST CHECK HERE FOR OUT OF RANGE
   //ALSO IS THIS CHECKING FOR NEGATIVE INFINITY ALSO
   if (isinf(lim_low) == 1)
   {
      return(EXIT_FAILURE);
   }
   
   if (isinf(lim_up) == 1)
   {
      return(EXIT_FAILURE);
   }
   if(interval < 1)
   {
      return(EXIT_FAILURE);
   }
   if(interval >= INT_MAX)
   {
      return(EXIT_FAILURE);
   }



   
   
   
   
   
   
   
   
   
   // fill in the correct statements to complete the main function
   //
   // we expect four arguments:
   //
   // the first argument is from the sets {"-m", "-t"}
   // -m: run mid_point_numerical_integration
   // -t: run trapezoidal_numerical_integration
   // otherwise: return EXIT_FAILURE ----------- DONE
     
   // to run any of the two integration functions, expect the next 
   // three arguments to be the lower limit of the integration (double), 
   // the upper limit of the integration (double), and the number of 
   // intervals for the integration (int)
   //
   // use strtod to convert an argument to a double 
   // use strtol to convert an argument to a long (and then to an int)
   // check that the arguments are of the correct format and within range

   if(m_check == 0)
   {
      
      integrand = mid_point_numerical_integration(lim_low, lim_up, interval);
   }
   if (t_check == 0)
   {
      
      integrand = trapezoidal_numerical_integration(lim_low, lim_up, interval);
   }

   

   fprintf(stdout, "%.10e\n", integrand);
   return EXIT_SUCCESS;
}

#include "answer04.h"
#include "aux04.h"
#include <stdio.h>

// Given intg_arg, this function performs numerical integration of 
// the function intg_arg.func_to_be_integrated over the bounded interval
// intg_arg.lower_limit to intg_arg.upper_limit
// 
// The bounded interval is divided into intg_arg.n_intervals continguous
// uniform intervals
// 
// The Simpson's rule is used to perform the integration for each interval
//
// The integral is the sum of the integration over all intervals
//
// The caller function has to make sure that intg_arg.n_intervals >= 1
// Therefore, this function may assume that intg_arg.n_intervals >= 1
//
double simpson_numerical_integration(integrand variables)
{
   double integral = 0.0;
   int n = 1; //While control variable
   
   // n intervals is essentially the number of boxes

   double bin_num = ((variables.upper_limit - variables.lower_limit) / (variables.n_intervals)); //width of the rectangle
   double midpoint_start1 = 0.0;//upper_limit - ((bin_num) / 2); //Proceeding right to left for each rectangle
   double midpoint_start2 = 0.0; // Other x value for the function
   double area = 0; 
   double vfa = 0;
   double vfm = 0;
   double vfb = 0;
   double constant = 0;
   

      midpoint_start1 = variables.lower_limit; //Essentially lower limit
      midpoint_start2 = variables.lower_limit + bin_num; //Essentially upper limit
       
       while (n <= variables.n_intervals)
       {
         constant = (midpoint_start2 - midpoint_start1) / 6; //(b-a) / 6 portion
         vfa = variables.func_to_be_integrated(midpoint_start2); //F(a) portion
         vfm =  (variables.func_to_be_integrated((midpoint_start1 + midpoint_start2) / 2)); //(f(m)) portion
         vfb = variables.func_to_be_integrated(midpoint_start1); // f(b) portion
         area = constant * (vfa + (4 * vfm) + vfb); //Equation put togeter
        
         
         
         integral = integral + area; //Integral update
         midpoint_start1 = midpoint_start1 + bin_num; //Starting point update
         midpoint_start2 = midpoint_start2 + bin_num; //End point update
         n = n + 1; //While loop update
       }
   
  


   

   return integral;
}

 



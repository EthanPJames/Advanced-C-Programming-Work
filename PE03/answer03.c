#include "answer03.h"
#include "aux03.h"



// the function performs numerical integration of the function
// double function_to_be_integrated(double) over the 
// bounded interval lower_limit to upper_limit
//
// The bounded interval is divided into n_intervals contiguous uniform intervals
// 
// The mid-point rule is used to perform the integration for each interval
// In the mid-point rule, the integration is approximated by using the
// area of a rectangle, where the height of the rectange is obtained by
// function_to_be_integrated(mid-point of the interval).  The width of
// the rectangle is (upper_limit - lower_limit)/n_intervals
// Note that width could be negative if upper_limit < lower_limit ??
//
// The integral is the sum of the integration over all intervals
//
// The caller function has to make sure that n_intervals >= 1
// Therefore, this function may assume that n_intervals >= 1
//

double mid_point_numerical_integration(double lower_limit, double upper_limit, int n_intervals)
{
   double integral = 0.0;
   int n = 1; //While control variable
   // n intervals is essentially the number of boxes
   
   double bin_num = ((upper_limit - lower_limit) / (n_intervals)); //width of the rectangle
   double midpoint_start = 0.0; // upper_limit - ((bin_num) / 2); //Proceeding right to left for each rectangle
   double area = 0; 
   if(upper_limit > lower_limit)
   {
        midpoint_start = upper_limit - ((bin_num) / (2));
        //midpoint_start = lower_limit + ((bin_num) / 2);
       while (n <= n_intervals)
       {
         
         area = (function_to_be_integrated(midpoint_start)) * bin_num;
         
        
         integral = integral + area;
         
         midpoint_start = midpoint_start - bin_num;
         
         
         n = n + 1;
       }
          
   }
   else if (upper_limit < lower_limit)
   {
       midpoint_start = upper_limit - ((bin_num) / (2));
        //midpoint_start = lower_limit + ((bin_num) / 2);
       while (n <= n_intervals)
       {
         
         area = (function_to_be_integrated(midpoint_start)) * bin_num;
         
        
         integral = integral + area;
         
         midpoint_start = midpoint_start - bin_num;
         
         
         n = n + 1;
       }
       
      
  
   }
   else
   {
      integral = 0;
   }
  


   

   return integral;
}










// the function performs numerical integration of the function
// double function_to_be_integrated(double) over the 
// bounded interval lower_limit to upper_limit
//
// The bounded interval is divided into n_intervals contiguous uniform intervals
// 
// The trapezoidal rule is used to perform the integration for each interval
// in the trapezoidal rule, the integration is approximated by the area of 
// a trapezoid, where the heights of the parallel boundaries of the trapezoid
// are obtained by 
// function_to_be_integrated(left boundary of the interval) and 
// function_to_be_integrated(right boundary of the interval).  
// The width of the trapezoid is (upper_limit - lower_limit)/n_intervals
// Note that width could be negative if upper_limit < lower_limit
// the area of a trapezoid is the average of the two heights multiplied by
// the width
//
// The integral is the sum of the integration over all intervals
//
// The caller function has to make sure that n_intervals >= 1
// Therefore, this function may assume that n_intervals >= 1
//
double trapezoidal_numerical_integration(double lower_limit, double upper_limit, int n_intervals)
{
   double integral = 0.0;
   int n = 1; //While control variable
   // n intervals is essentially the number of boxes
   
   double bin_num = ((upper_limit - lower_limit) / (n_intervals)); //width of the rectangle
   double midpoint_start1 = 0.0;//upper_limit - ((bin_num) / 2); //Proceeding right to left for each rectangle
   double midpoint_start2 = 0.0; // Other x value for the function
   double area = 0; 
   if(upper_limit > lower_limit)
   {
      midpoint_start1 = upper_limit;
      midpoint_start2 = upper_limit - bin_num;
       while (n <= n_intervals)
       {
         area = ((function_to_be_integrated(midpoint_start1) + function_to_be_integrated(midpoint_start2)) / 2) * bin_num;
         integral = integral + area;
         midpoint_start1 = midpoint_start1 - bin_num;
         midpoint_start2 = midpoint_start2 - bin_num;
         n = n + 1;
       }
          
   }
   else if (upper_limit < lower_limit)
   {
      midpoint_start1 = upper_limit;
      midpoint_start2 = upper_limit - bin_num;
       while (n <= n_intervals)
       {
         area = ((function_to_be_integrated(midpoint_start1) + function_to_be_integrated(midpoint_start2)) / 2) * bin_num;
         integral = integral + area;
         midpoint_start1 = midpoint_start1 - bin_num;
         midpoint_start2 = midpoint_start2 - bin_num;
         n = n + 1;
       }
      
   }
   else
   {
      integral = 0;
   }
  

   return integral;
}

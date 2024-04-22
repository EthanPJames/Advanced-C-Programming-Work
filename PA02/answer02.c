#include <math.h>

#include "answer02.h"

// Given intg_arg, this function performs numerical integration of 
// the function intg_arg.func_to_be_integrated over the range
// intg_arg.lower_limit to intg_arg.upper_limit
// 
// The bounded interval is divided into intg_arg.n_intervals contiguous
// uniform intervals
// 
// The Simpson's rule is used to perform the integration for each interval
//
// The integral is the sum of the integration over all intervals
//
// The caller function has to make sure that intg_arg.n_intervals >= 1
// Therefore, this function may assume that intg_arg.n_intervals >= 1
//
double simpson_numerical_integration(integrand intg_arg)
{
   double integral = 0.0;
   
   int n = 1; //While control variable
   
   // n intervals is essentially the number of boxes

   double bin_num = ((intg_arg.upper_limit - intg_arg.lower_limit) / (intg_arg.n_intervals)); //width of the rectangle
   double midpoint_start1 = 0.0;//upper_limit - ((bin_num) / 2); //Proceeding right to left for each rectangle
   double midpoint_start2 = 0.0; // Other x value for the function
   double area = 0.0; 
   double vfa = 0.0;
   double vfm = 0.0;
   double vfb = 0.0;
   double constant = 0.0;
   

      midpoint_start1 = intg_arg.lower_limit; //Essentially lower limit
      midpoint_start2 = intg_arg.lower_limit + bin_num; //Essentially upper limit
       
       while (n <= intg_arg.n_intervals)
       {
         constant = (midpoint_start2 - midpoint_start1) / 6; //(b-a) / 6 portion
         vfa = intg_arg.func_to_be_integrated(midpoint_start2); //F(a) portion
         vfm =  (intg_arg.func_to_be_integrated((midpoint_start1 + midpoint_start2) / 2)); //(f(m)) portion
         vfb = intg_arg.func_to_be_integrated(midpoint_start1); // f(b) portion
         area = constant * (vfa + (4 * vfm) + vfb); //Equation put togeter
        
         
         
         integral = integral + area; //Integral update
         midpoint_start1 = midpoint_start1 + bin_num; //Starting point update
         midpoint_start2 = midpoint_start2 + bin_num; //End point update
         n = n + 1; //While loop update
       }
   

   return integral;
}






// Given intg_arg, this function performs numerical integration over the
// range of intg_arg.lower_limit to intg_arg.upper_limit of f(x):
// 
// f(x) = intg_arg.func_to_be_integrated(x) * cos_sin((n * M_PI * x)/L), 
//
// where 2L = intg_arg.upper_limit - intg_arg.lower_limit = period 
// 
// The bounded interval is divided into intg_arg.n_intervals contiguous
// uniform intervals
// 
// The Simpson's rule is used to perform the integration for each interval
//
// The integral is the sum of the integration over all intervals
//
// The caller function has to make sure that intg_arg.n_intervals >= 1
// Therefore, this function may assume that intg_arg.n_intervals >= 1
//
// The caller function should also pass in n >= 0
//
// The caller function should also pass in cos or sin for the function 
// cos_sin.
//
double simpson_numerical_integration_for_fourier(integrand intg_arg, int n, 
                                                 double (*cos_sin)(double))
{
   
    int j = 1; //While control variable
    double integral = 0.0;
   
   // n intervals is essentially the number of boxes

   double bin_num = ((intg_arg.upper_limit - intg_arg.lower_limit) / (intg_arg.n_intervals)); //width of the rectangle
   double midpoint_start1 = 0.0;//upper_limit - ((bin_num) / 2); //Proceeding right to left for each rectangle
   double midpoint_start2 = 0.0; // Other x value for the function
   double area = 0; 
   double vfa = 0;
   double vfm = 0;
   double vfb = 0;
   double constant = 0;
   
   double trigL = 0; //Cosine or sine constant
   double trigM = 0; //Cosine or sine constant
   double trigU = 0; //Cosine or sine constant
   

      midpoint_start1 = intg_arg.lower_limit; //Essentially lower limit
     
      midpoint_start2 = intg_arg.lower_limit + bin_num; //Essentially upper limit
    
       
       
       while (j <= intg_arg.n_intervals)
       {
         
         double L = (midpoint_start2 - midpoint_start1) / 2.0;
         
         trigL = cos_sin((n * M_PI * midpoint_start1) / L);
        
         trigM = cos_sin((n * M_PI * ((midpoint_start1 + midpoint_start2) / 2.0)) / L);
        
         trigU = cos_sin((n * M_PI * midpoint_start2) / L);
         

         constant = (midpoint_start2 - midpoint_start1) / 6.0; //(b-a) / 6 portion
         vfa = intg_arg.func_to_be_integrated(midpoint_start2); //F(a) portion
         
         vfm =  (intg_arg.func_to_be_integrated((midpoint_start1 + midpoint_start2) / 2.0)); //(f(m)) portion
         
         vfb = intg_arg.func_to_be_integrated(midpoint_start1); // f(b) portion
         
         area = constant * ((vfa * trigU) + (4.0 * vfm * trigM) + (vfb * trigL)); //Equation put togeter

          



        
         
         
         integral = integral + area; //Integral update
         midpoint_start1 = midpoint_start1 + bin_num; //Starting point update
         midpoint_start2 = midpoint_start2 + bin_num; //End point update
         j = j + 1; //While loop update
       }
   
      

   
   return integral;
}

// Given fourier_arg, this function computes 
// Fourier coefficients a_0, a_1, ..., a_{fourier_arg.n_terms-1} and stores
// them as fourier_arg.a_i[0], fourier_arg.a_i[1], and so on, and 
// b_1, ..., b_{fourier_arg.n_terms-1} and stores them as fourier_arg.b_i[1],
// fourier_arg.b_i[2], and so on.
//
// The period is defined to be 
//    fourier_arg.intg.upper_limit - fourier_arg.intg.lower_limit
// 
// The function simpson_numerical_integration is used in the process of 
// computing a_0.  fourier_arg.intg should be passed to the function.
//  
// The function simpson_numerical_integration_for_fourier is used in the 
// process of computing a_1, ... and b_1, ...
// fourier_arg.intg should be passed, appropriate n >= 0, and either sin or
// cos function should also be passed.
//
// The caller function should pass into this function fourier_arg.n_terms >= 1
//
// The caller function should also allocate space to store the coefficients
// a_0, a_1, ..., b_1, ...
// 
// The caller function should ensure that the period is not 0.
//
void fourier_coefficients(fourier fourier_arg)  //Debug this fuction
{
   
   //Variables Section
   int i; //Variable update
   double period = (fourier_arg.intg.upper_limit - fourier_arg.intg.lower_limit) / 2.0; //Value for L
   //?? Is this syntax correct???///^ ??Is the upper limit/intervals updating or staying constant?

   fourier_arg.a_i[0] = (1.0 / period) * simpson_numerical_integration(fourier_arg.intg);  //Finidng the a initial coefficient

   
   for(i = 1; i < fourier_arg.n_terms; i++) //Check if i need intervals or terms
   {
      fourier_arg.a_i[i] = (1 / period) * (simpson_numerical_integration_for_fourier(fourier_arg.intg, i, cos)); // ??How do I decided whter cosine function or not
     
      fourier_arg.b_i[i] = (1 / period) * (simpson_numerical_integration_for_fourier(fourier_arg.intg, i, sin)); // ??How do i decided if cos or sin
    
      //??How do i know wheter it should be a cos function or not
     
   }

   return;
}


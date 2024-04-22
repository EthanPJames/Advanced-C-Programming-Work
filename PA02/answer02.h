#ifndef __ANSWER02_H__
#define __ANSWER02_H__

#define M_PI           3.14159265358979323846  /* pi */

/* you have to define the structure integrand as in PE04           */
/*                                                                 */
/* complete your definition of structure integrand below this line */
/* include the following three fields (and nothing else):          */
/* upper_limit, n_intervals, func_to_be_integrated                 */
/* it is important to have the correct types and field names for us*/
/* to evaluate your functions properly                             */

typedef struct _integrand {
   double lower_limit;
   double upper_limit;
   int n_intervals; //Should this be a double
   double(*func_to_be_integrated)(double); 
   



} integrand;

/* define your structure integrand above this line */
/* DO NOT make changes at other locations          */
/* DO NOT declare other functions in this file     */

// structure defined by instructor and used in PA02

typedef struct _fourier {
   integrand intg;
   double *a_i;
   double *b_i;
   int n_terms;
} fourier;

// you have to define the following three functions in answer02.c

double simpson_numerical_integration(integrand intg_arg);

double simpson_numerical_integration_for_fourier(integrand intg_arg, int n, 
                                                 double (*cos_sin)(double));

void fourier_coefficients(fourier fourier_arg);

#endif

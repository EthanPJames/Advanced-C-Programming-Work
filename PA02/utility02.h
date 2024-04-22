#ifndef __UTILITY02_H__
#define __UTILITY02_H__ 

// utility to plot a function, f(x) is original_func
// parameters associated with Fourier series F(x) are:
// lower_limit, upper_limit: range of the period
// a_i: array containing the a_i coefficients
// b_i: array containing the b_i coefficients
// n_terms: number of items in the a_i array a_i[0] ... a_i[n_terms - 1], 
//          there should be n_terms - 1 valid items in the b_i array:
//          b_i[1], ..., b_i[n_terms - 1]
// filename: name of the file to store the plots 
//
// you should be able to pass the first six parameters by using different
// fields of the fourier structure
//
// the plots are printed to the file in the matlab format
// 
void function_plot(double (*original_func)(double), 
                   double lower_limit, double upper_limit,
                   double *a_i, double *b_i, int n_terms, char *filename);

// print fourier coefficients to stderr
// a_i: array containing the a_i coefficients
// b_i: array containing the b_i coefficients
// n_terms: number of items in the a_i array a_i[0] ... a_i[n_terms - 1], 
//          there should be n_terms - 1 valid items in the b_i array:
//          b_i[1], ..., b_i[n_terms - 1]
//
// you should be able to pass these parameters by using different
// fields of the fourier structure
//
// a_i are printed first, then b_i, one coeffient per line
//
void print_fourier_coefficients(double *a_i, double *b_i, int n_terms);

// save fourier coefficients to a file
// a_i: array containing the a_i coefficients
// b_i: array containing the b_i coefficients
// n_terms: number of items in the a_i array a_i[0] ... a_i[n_terms - 1], 
//          there should be n_terms - 1 valid items in the b_i array:
//          b_i[1], ..., b_i[n_terms - 1]
//
// you should be able to pass these three parameters by using different
// fields of the fourier structure
//
// filename contains the name of the file
// the coefficients are saved as a binary file
//
void save_fourier_coefficients(double *a_i, double *b_i, int n_terms, 
                               char *filename);

#endif

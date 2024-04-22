#ifndef __UTILITY01_H__
#define __UTILITY01_H__

// Given a filename (a string), this function reads the entries in the file 
// into an array, and returns the array.  The size of the array is 
// stored in *arraysize
//
// the file is assumed to store only numbers.
// The function first determines the number of numbers in the file,
// then allocates the right array size, 
// and reads all the numbers into the array.
// 
// A file containing only space is considered to be containing 0 numbers,
// it returns a non-NULL address for a 0-size array, and *arraysize is 0
//
// if filename is NULL, if the file is non-existent, or the file contains 
// non-numbers, the function returns a NULL address, and *arraysize is 0
//

int *read_in_array(char *filename, int *arraysize);

#endif

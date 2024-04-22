#ifndef __ANSWER01_H__
#define __ANSWER01_H__

// the contents at the location whose address is stored in
// nptr should not be changed
// the first argument to the function should not be a null pointer
//
long int my_strtol(char const *nptr, char **endptr, int base)
                   __attribute__((nonnull (1)));

#endif

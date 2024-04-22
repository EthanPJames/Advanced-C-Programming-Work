#ifndef __ANSWER02_H__
#define __ANSWER02_H__

#define INV_SYMBOL 36

// convert a char to a number
// '0'..'9' --> 0..9
// 'a'..'z' --> 10..35
// 'A'..'Z' --> 10..35
// other characters --> INV_SYMBOL
//
int char_to_int(char c);

// the argument nptr is expected to be non-NULL 
// nptr stores an address pointing to a constant char
// in other words, you should not change the string
// the string may have leading white space, followed by
// an optional +/- sign, and then valid characters
// for the base.  The conversion terminates whenever
// an invalid character is encountered or when we 
// reach the end of the string.
//
// base 2 to base 36
//
long int str_to_long_int(char const *nptr, int base)
                   __attribute__((nonnull (1)));

#endif

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "answer02.h"

// a sample test function to call char_to_int
//
static void test_char_to_int()
{
   fprintf(stderr, "%d\n", char_to_int('0'));
   fprintf(stderr, "%d\n", char_to_int('1'));
   fprintf(stderr, "%d\n", char_to_int('2'));
}

// a sample test function to call test_str_to_long_int
//
static void test_str_to_long_int()
{
   char *endptr;  // this is for strtol
   int base; 

   // test for a range of base, including an invalid base 37
   // here are some suggestions for additional test, exceeding LONG_MAX, or 
   // going below LONG_MIN, and many others

   for (base = 2; base < 38; base++) {

      // before you call the function str_to_long_int
      // set errno to zero

      errno = 0;
      long int test = str_to_long_int("     +123a4", base);
      
      printf("My test : %ld Base : %d \n", test, base);
      // print errno
      // typically, you want to check errno when the returned value
      // is LONG_MAX or LONG_MIN in a more useful program

      fprintf(stderr, "%ld %d\n", test, errno);

      // call strtol to cross check the results 
      // note that the results should not match when base == 16.
      // before you call the function strtol
      // set errno to zero

      errno = 0;
      test = strtol("     +123a4", &endptr, base);

      printf("Comp: %ld Base: %d \n", test, base);
      fprintf(stderr, "%ld :%s %d\n", test, endptr, errno);
   }
}

int main(int argc, char **argv)
{
   fprintf(stderr, "Welcome to ECE264, we are working on PE02.\n\n");

   // testing the char_to_int function
   // question:  how to do a comprehensive test

   test_char_to_int();

   // testing the str_to_long_int function
   // question:  how to do a comprehensive test

   test_str_to_long_int();

   return EXIT_SUCCESS;
}

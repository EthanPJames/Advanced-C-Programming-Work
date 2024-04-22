#include <errno.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h> 

#include "answer02.h"

// Given a char c, return a numeric value
// '0'..'9' --> 0..9
// 'a'..'z' --> 10..35
// 'A'..'Z' --> 10..35
// for other characters, return INV_SYMBOL (see answer02.h);
//
int char_to_int(char c)
{
   
   // what if c is '0'--'9'
   if (('0' <= c) && (c <= '9'))
   {
      return c - 48;
   }
     
  


   // what if c is 'a'--'z'
   if (('a' <= c) && (c <= 'z'))
   {
      return c - 87;
   }


   // what if c is 'A'--'Z'
  if (('A' <= c) && (c <= 'Z'))
   {
      return c - 55;
   }



   // otherwise

   return INV_SYMBOL;
}

// you are not allowed to change the contents at the location whose address in 
// stored in nptr (the way to interpret the type of nptr is that it is an address
// pointing to a constant char.)
//
// you have to check for whether the base in the valid range 2 through 36
// if not, set errno to EINVAL
// 
// This is a suggestion on how you should process the string
// (1)  skip over all white space
// (2)  if a +/- sign is encountered, set the polarity of the number accordingly
//      By default, the number is assumed to be positive if no sign is given.
// (3)  Convert the string until you encounter an invalid symbol for that 
//      base or when you reach the end of the string.
//
// examples (not exhaustive, of course):
//    "10a:" in base 10 is 10, in base 16 is 266, in base 36 is 1306
//    "   -10a:" in base 10 is -10, in base 16 is -266, and in base 36 is -1306 
//    " +10a:" in base 10 is 10, in base 16 is 266, in base 36 is 1306
//    "922337203685477580710304" in base 10 should return LONG_MAX, and errno 
//    should be set to ERANGE.
//    "-922337203685477580710304" in base 10 should return LONG_MIN, and errno 
//    should be set to ERANGE.
//    "garbage" should be 0 in base 10, 0 in base 16, and 35479055534 in base 36
//
long int str_to_long_int(char const *nptr, int base)
{
   long int ret_value = 0;  // return value
                            // if no conversion happens, return
   int index = 0; //Index variable
   int sign_value = -1; //If negative symbol exists
   // if invalid base, set errno and return immediately
   if ((base < 2) || (base > 36))
   {
      errno = EINVAL;
      return(0);
   }
   else
   {
      while (isspace(nptr[index]) != 0) //Checks if index value is less than the length of the given string
      {
         
            index = index + 1;
      }
      
       if((nptr[index]) == '-') //Checking sign
            {
               
               sign_value = 1;
               
            }
            else
            {
               
               sign_value = -1;
               
            }      
           
         
         index = index + 1;
          
         while (nptr[index] != '\0')
         {
            if(char_to_int(nptr[index]) < (base)) //If the number is valid in the current base
            {
               //printf("Char to int function :%d\n", char_to_int(nptr[index])); //PRINT STATEMTN
               
               /*if(ret_value == 0)
               {
                  ret_value = (ret_value * base + char_to_int((nptr[index]))) ;
                  ret_value = ret_value * sign_value;
                  printf("My return Value : %ld \n", ret_value); //PRINT STATEMTN
                  index = index + 1;
               }
               else if (LONG_MAX / ret_value >= (char_to_int((nptr[index])))) //Not sure if correct
               {
                 errno = ERANGE;
                 return(LONG_MAX);
               }
               else
               {
                  ret_value = (ret_value * base + char_to_int((nptr[index]))) ;
                  ret_value = ret_value * sign_value;
                  index = index + 1;

               } */

               if (ret_value * base > LONG_MAX)
               {
                  errno = ERANGE;
                  return(LONG_MAX);
               }
               else if ((ret_value * base + (char_to_int((nptr[index])))) > LONG_MAX)
               {
                  errno = ERANGE;
                  return(LONG_MAX);
               }
               else if (ret_value * base * sign_value < LONG_MIN)
               {
                  errno = ERANGE;
                  return(LONG_MIN);
               }
               else
               {
                  ret_value = (-ret_value * base - char_to_int((nptr[index]))) ;
                  ret_value = ret_value * sign_value;
                  index = index + 1;


               }

              //ret_value = (ret_value * base + char_to_int((nptr[index]))) ;
              //ret_value = ret_value + 1;
              //index = index + 1;

            }
            else
            {
               break;
            }
            
         }
         //ret_value = ret_value * sign_value;
         
          

   }
   





   // valid base, skip over white space
      
   



   // if encounter a sign, expect a number after that 
   // if a negative sign is encountered, the conversion must
   // produce a negative number
   // now, convert the string to number
   // the conversion has to account for the +/- sign
   // need to check whether you have out-of-range ret_value 
   // clean up before returning
   // need to set errno and ret_value correctly if the converted number 
   // is out of range









   return ret_value;
}

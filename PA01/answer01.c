#include <errno.h>
#include <ctype.h>
#include <limits.h>
#include "answer01.h"




// you should try to re-use a majority of the algorithms in PE02   DONE
// for this programming assignment.  DONE
// However, you have to take care of endptr, base 0, and base 16
// these are the three additional things you have to deal with in
// this assignment, as compared to the str_to_long_int function
// that you wrote for PE02.
//
// it is really IMPORTANT that you extensively try out the function
// strtol on your own.
//

static int char_to_int(char c)  //Function from PE02 converting string to value
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

   return (36);
}

//Seperation between functions


long int my_strtol(char const *nptr, char **endptr, int base)
{
   
   long int ret_value = 0;  // return value
                            // if no conversion happens, return
   int index = 0; //Index variable
   int sign_value = -1; //If negative symbol exists
   // if invalid base, set errno and return immediately
  
   if ((base == 1) || (base > 36)) //LOGIC STATEMENT "1"
   {
      errno = EINVAL;
      return(0);
   }
   
   else if (base == 0) //LOGIC STATEMENT "2"
   {
    
      while (isspace(nptr[index]) != 0) //Checks if index value is less than the length of the given string
      {
            
            index = index + 1;
      }
      //Whitespace checked
               
      if((nptr[index]) == '-') //Checking sign //LOGIC STATEMENT "3"
            {
            
               
               sign_value = -1;
               index = index + 1;
               
            }
            else if((nptr[index]) == '+')
            {
               
               
               sign_value = 1;
               index = index + 1;
               
            }
            else
            {
               sign_value = 1;
            }     
           //sign checked
         
         
      
         
      if ((nptr[index] == '0') && ((nptr[index + 1] == 'x') || (nptr[index + 1] == 'X'))) //Checks to see if base should be set to 16
      {
         
         base = 16;
         index = index + 2;
         if(nptr[index] == '\0') //added code
         {
           
            index--;
         }
      }
      else if ((nptr[index] == '0') && ((nptr[index + 1] != 'x') && (nptr[index + 1] != 'X'))) //Checks to see if base should be set to 8
      {
         base = 8;
      }
      else //Otherwise set base  equal to 10
      {
         base = 10;
      }

      //Base type checked
      //Copied bottom function I assume go about as normal with new base as calculation now

      
        
         while (nptr[index] != '\0')
         {
            
            
            if(char_to_int(nptr[index]) < (base)) //If the number is valid in the current base
            {
               
                
               

               if ((ret_value > (LONG_MAX - char_to_int(nptr[index])) / base ))
               {
                  
                  errno = ERANGE;
                  index = index + 1;
                  *endptr = (char*)&nptr[index];
                  //return(LONG_MAX);
                  ret_value = LONG_MAX;
               }
               else if (ret_value * base * sign_value < LONG_MIN)
               {
                  errno = ERANGE;
                  //index = index + 1;
                  *endptr = (char*)&nptr[index];
                  //return(LONG_MIN);
                  ret_value = LONG_MIN;
               }
               else
               {
                  
                  
                  
                  ret_value = (ret_value * base + char_to_int((nptr[index]))) ;
                
                  //ret_value = ret_value * sign_value;  //******************************************************************************************
                  index = index + 1;


               }

             

            }
            else
            {
               *endptr = (char*)&nptr[index];
               break;
            }
            
         }



      
   }
   
   else if (base == 16)
   {
      
      while (isspace(nptr[index]) != 0) //Checks if index value is less than the length of the given string
      {
            
            index = index + 1;
      }
      //Whitespace checked

      if((nptr[index]) == '-') //Checking sign
            {
              
               
               sign_value = -1;
               index = index + 1;
            }
            else if((nptr[index]) == '+')
            {
               
               sign_value = 1;
               index = index + 1;
            }
            else
            {
               sign_value = 1;
            }          
           //sign checked
         
         

      if ((nptr[index] == '0') && ((nptr[index + 1] == 'x') || (nptr[index + 1] == 'X')))
      {
         index = index + 2;
          while (nptr[index] != '\0')
         {
            if(char_to_int(nptr[index]) < (base)) //If the number is valid in the current base
            {
               
               
               

               if ((ret_value > (LONG_MAX - char_to_int(nptr[index])) / base ))
               {
                
                  errno = ERANGE;
                  index = index + 1;
                  *endptr = (char*)&nptr[index];
                  //return(LONG_MAX);
                  ret_value = LONG_MAX;
               }
               else if (ret_value * base * sign_value < LONG_MIN)
               {
                  errno = ERANGE;
                  index = index + 1;
                  *endptr = (char*)&nptr[index];
                  //return(LONG_MIN);
                  ret_value = LONG_MIN;
               }
               else
               {
                 
                  ret_value = (ret_value * base + char_to_int((nptr[index]))) ;
                  //ret_value = ret_value * sign_value;//*****************************************************************************************
                  index = index + 1;


               }

             

            }
            else
            {
               *endptr = (char*)&nptr[index];
               break;
            }
            
         }


      }

      else
      {
         
          while (nptr[index] != '\0')
         {
            if(char_to_int(nptr[index]) < (base)) //If the number is valid in the current base
            {
               
               
               

               
               if ((ret_value > (LONG_MAX - char_to_int(nptr[index])) / base ))
               {
                  
                  errno = ERANGE;
                  index = index + 1;
                  *endptr = (char*)&nptr[index];
                  ret_value = LONG_MAX;
                  //return(LONG_MAX);
               }
               
               else if ((ret_value > (LONG_MAX - char_to_int(nptr[index])) / base ))
               {
                  errno = ERANGE;
                  index = index + 1;
                  *endptr = (char*)&nptr[index];
                  ret_value = LONG_MAX;
                  //return(LONG_MAX);
               }
               else if (ret_value * base * sign_value < LONG_MIN)
               {
                  errno = ERANGE;
                  index = index + 1;
                  *endptr = (char*)&nptr[index];
                  ret_value = LONG_MIN;
                  //return(LONG_MIN);
               }
               else
               {
                  
                  ret_value = (ret_value * base + char_to_int((nptr[index]))) ;
                  //ret_value = ret_value * sign_value;//***************************************************************************************
                  index = index + 1;


               }

             

            }
            else
            {
               *endptr = (char*)&nptr[index];
               break;
            }
            
         }
      }
   }
   
   
   
   
   else
   {
      
      while (isspace(nptr[index]) != 0) //Checks if index value is less than the length of the given string
      {
            
            index = index + 1;
      }
      
       if((nptr[index]) == '-') //Checking sign
            {
               
               
               sign_value = -1;
               index = index + 1;
            }
            else if((nptr[index]) == '+')
            {
               
               sign_value = 1;
               index = index + 1;
            }
            else
            {
               sign_value = 1;
            }          
           
         
         //index = index + 1;
          
         while (nptr[index] != '\0')
         {
            if(char_to_int(nptr[index]) < (base)) //If the number is valid in the current base
            {
               
               
               

              if ((ret_value > (LONG_MAX - char_to_int(nptr[index])) / base ))
               {
                  
                  errno = ERANGE;
                  index = index + 1;
                  *endptr = (char*)&nptr[index];
                  
                  ret_value = LONG_MAX;
                  //return(LONG_MAX);
               }
               else if (ret_value * base * sign_value < LONG_MIN)
               {
                  
                  errno = ERANGE;
                  index = index + 1;
                  *endptr = (char*)&nptr[index];
                  ret_value = LONG_MIN;
                  //return(LONG_MIN);
               }
               else
               {
                  
              
                  ret_value = (ret_value * base + char_to_int((nptr[index]))) ;
                  //ret_value = ret_value * sign_value; //******************************************************************************************
                  index = index + 1;


               }

             

            }
            else
            {
               
               *endptr = (char*)&nptr[index];
               break;
            }
            
         }
         
         
          

   }
   



   // if invalid base, set errno and return immediately DONE





   // valid base, skip over white space  DONE




   // if encounter a sign, expect a number after that DONE
   // if a negative sign is encountered, change the sign DONE





   
   // the exact algorithm is not given, but these are 
   // the tasks the function has to perform:  
   //
   // determine the actual base if the base is 0  //DONE
   // if it starts with '0', it is octal //DONE
   // if '0' is followed by 'x' or 'X' it is hexadecimal or base 16 DONE
   // otherwise, it is decimal DONE
   // therefore you have to determine the actual base and the starting DONE
   // location to perform conversion DONE
   //
   // for bases 2 to 15, perform conversion as in PE02 DONE 
   //
   // for base 16, you have to decide when the conversion should
   // start: after the optional "0x" or "0X" or immediately
   // question: if you have "0xG", what should be converted?
   //
   // for bases 17 to 36, perform conversion as in PE02 //DONE
   // 
   // after you have determine the real base, and where to start,
   // perform the conversion






















   // clean up, set ret_value properly if the conversion went out of range
   // set errno if necessary
   // set *endptr properly if the endptr is not NULL







   *endptr = (char*)&nptr[index];
  
   return (ret_value * sign_value); //I just changed the return code *************************************************************
   
   
}

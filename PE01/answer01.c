#include "answer01.h"
#include <stdio.h>	
/* Return the smallest partial sum of the array */
/* int array[] = { 1, 4, -1, 6, -5, 4} */
/* the (i,j)-th partial sum is the sum from array[i] through array[j], i<=j */
/* the (0,0)-(0,5)-th partial sums are 1, 5, 4, 10, 5, 9 */
/* the (1,1)-(1,5)-th partial sums are 4, 3, 9, 4, 8 */
/* the (2,2)-(2,5)-th partial sums are -1, 5, 0, 4 */
/* the (3,3)-(3,5)-th partial sums are 6, 1, 5 */
/* the (4,4)-(4,5)-th partial sums are -5, -1 */
/* the (5,5)-th partial sum is 4 */
/* the smallest partial sum of the array is therefore -5 */
/* if the len is 0, the smallest partial sum is 0 */
/* you may call this function only when the array is non-NULL */
/* you may assume that none of the partial sums will cause underflow/overflow */

int smallest_partial_sum(int *array, int len)
{
  int ind; //index variable
  int ind2; //index 2 for the variable in the second for loop
  int cur_sum = 0; //Partial sum tracker
  //  int compare = array[0]; //Comparing to the previous value in the array
  int sum_store = 0; //Stores previous partial sum
  	
  for(ind = 0; ind < len; ++ind) //Start at 0 and goes through entire array
    {
      for(ind2=ind; ind2 < len; ++ind2) //Start at current value and go through end of array
		{
	  		cur_sum = cur_sum + array[ind2]; //update partial sum
			

	  		if(sum_store > cur_sum)//If current partial sum is smaller than current smallest then 
	    		{
	      			sum_store = cur_sum; //Replace current smallest
	    		}
		}
		cur_sum = 0;
       
    }
	     
 return sum_store;
}

/* Return the largest difference of the array */
/* int array[] = { 1, 4, -1, 6, -5, 4} */
/* the largest difference is 6 - (-5) = 11 */
/* if the len is 0, the largest difference is 0 */
/* if the len is 1, the largest difference is also 0 */
/* you may call this function only when the array is non-NULL */
/* you may assume that the largest difference will not cause an overflow */

int largest_difference(int *array, int len)
{
  int ind; //Index value of th array
  int x; //Value place holder for comparison ind
  int y; //value place holder for comparison for ind + 1
  int large = array[0]; //Largest value in array
  int small = array[0]; //Smallest value in array
  int large_dif; //Largest difference
  
  for(ind = 1; ind < len; ++ind)
    {
      x = array[ind];
      y = array[ind - 1];
      if(x > y)
	{
	  if(x > large)
	    {
	      large = x;
	    }
        }
      else
	{
	  if(y > large)
	    {
	      large = y;
	    }
	}
    }
  for(ind = 1; ind < len; ++ind)
    {
      x = array[ind];
      y = array[ind - 1];
	if(x < y)
	  {
	    if (x < small)
	      {
		small = x;
	      }
	  }
	else
	  {
	    if(y < small)
	      {
	       small = y;
	      }
	       
	  }
    }
  large_dif = large - small;
    
      
      
   
  return (large_dif);
}

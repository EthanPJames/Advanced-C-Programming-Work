#ifndef __ANSWER01_H__
#define __ANSWER01_H__

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
/* for the purpose of this exercise, you may assume that none */
/* of the partial sums will cause overflow/underflow */

int smallest_partial_sum(int *array, int len)
		__attribute__((nonnull (1)));

/* Return the largest difference of the array */
/* int array[] = { 1, 4, -1, 6, -5, 4} */
/* the largest difference is 6 - (-5) = 11 */
/* if the len is 0, the largest difference is 0 */
/* if the len is 1, the largest difference is also 0 */

/* you may call this function only when the array is non-NULL */
/* for the purpose of this exercise, you may assume that the */
/* largest difference will not cause an overflow */

int largest_difference(int *array, int len) 
		__attribute__((nonnull (1)));

#endif



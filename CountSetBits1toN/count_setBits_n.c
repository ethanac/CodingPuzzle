#include <stdlib.h>
#include <stdio.h>

/* For any 2^b(b >= 0), like 1, 2, 4, 8..., the result would be b * 2^(b-1) + 1
** And it must be considered that result for lower bits would be affected by the number of 1 in higher bits.
** Just count how many 1s in the integer and the index where these 1s are in the integer.
*/

int
countSetBits( int n ) {
   int counter = 0;
   int a_counter = 0;
   int array[sizeof(int)];
   int result = 0;
   int m = 1;
   while( n > 0 ) {
      if( (n&1) == 1 ) {
         array[a_counter] = counter;
         a_counter++;
      }
      counter++;
      n >>= 1;
   }
   for(int i = a_counter-1; i >= 0; i--) {
      int j = array[i];
      result += m * (j * (1 << (j-1)) + 1); 
      m++;
   }
   return result;
}

int
main( void ) {
   int n = 17;
   printf("Total set bit count is %d\n", countSetBits(n));
}


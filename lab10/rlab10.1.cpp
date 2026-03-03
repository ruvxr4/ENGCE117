#include <stdio.h>

long SumLoop(int n);

long SumRecur(int n);

int main() {

    int n = 1000000000; 
    
    printf("SumLoop(%d) = %ld\n", n, SumLoop(n));

    printf("SumRecur(%d) = %ld\n", n, SumRecur(n));
    
    return 0;
} // end main function

long SumLoop(int n) {

    int i;

    long sum = 0;
    
    for(i = 1; i <= n; i++) {

        sum += i;

    } // end for
    
    return sum;
} // end SumLoop function

long SumRecur(int n) {
    if(n > 1) {
        return n + SumRecur(n - 1);
    } // end if
    
    return 1;
} // end SumRecur function
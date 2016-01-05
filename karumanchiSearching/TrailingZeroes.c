/* 
 * File:   TrailingZeroes.c
 * Author: kurnagar
 *
 * Created on June 18, 2014, 10:53 PM
 * 
 * http://www.programmerinterview.com/index.php/java-questions/find-trailing-zeros-in-factorial/
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int findTrailingZeroes(int n){
    if(n < 0){
        return -1;
    }
    if(n == 5){
        return 1;
    }
    
    int j = 5;
    int trailingCount = 0;
    
    for(j ; n/j >= 1 ; j=j*5){    // 29 --> has 5 factors of five... of which 25 contributes one more...there we count number of five factors...+ if 25 aslo factor add another1
        printf("\n  (%d / %d)",n,j);
        trailingCount += n/j;
    }
    return trailingCount;
}
int mainTrailingZero(int argc, char** argv) {
    
    printf("\nTrailing zeroes : %d",findTrailingZeroes(29));
    return (EXIT_SUCCESS);
}


/* 
 * File:   NumberOccuringOddNumberOfTimes.c
 * Author: kurnagar
 *
 * Created on June 23, 2014, 12:55 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int getNumberOccuringOddTimes(int* ar,int n){
    int i = 0;
    int result = 0;
    for(i ; i < n; i++){
        result ^= ar[i];
    }
    return result;
}
int mainNumberOddTimes(int argc, char** argv) {
    int a[7] = {4,1,5,3,1,5,4};
    int* ar = a;
    
    printf("\n odd number: %d",getNumberOccuringOddTimes(ar,7));
    return (EXIT_SUCCESS);
}


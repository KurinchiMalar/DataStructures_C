/* 
 * File:   MissingNumber.c
 * Author: kurnagar
 *
 * Created on June 23, 2014, 7:29 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int findMissingNumber_XORmethod(int* ar, int n, int range){
    int i = 0;
    int curXOR = 0;
    int actualXOR = 0;
     for(i ; i < n ; i++){
        curXOR ^= ar[i];
    }
    printf("\n curXOR =%d",curXOR);
    
    i = 1;
    for(i; i <= range; i++){
        actualXOR ^= i;
    }
    printf("\n actualXOR  %d",actualXOR);
    return actualXOR ^ curXOR;
}
int findMissingNumber_SumMethod(int* ar,int n,int range){
    int i = 0;
    int curSum = 0;
    for(i ; i < n ; i++){
        curSum+= ar[i];
    }
    printf("\n curSum = %d",curSum);
    return ( ((range*(range+1))/2) - curSum);
        
}
int mainMissingNumber(int argc, char** argv) {

    int ar[7] = {1,2,4,6,3,7,8};
    int *a =ar;
    printf("\n missing :%d",findMissingNumber_XORmethod(ar,7,8));
    return (EXIT_SUCCESS);
            
}


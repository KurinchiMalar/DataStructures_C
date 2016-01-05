/* 
 * File:   maximumRepeatingElement.c
 * Author: kurnagar
 *
 * Created on June 19, 2014, 10:01 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int findMaximumRepeatingElement(int* ar,int n){
   // int* hash = (int*)malloc(sizeof(int)*n);
    int* hash = (int*)calloc(n,sizeof(int));// initializing to zero
    int i = 0;
    int hashMax = INT32_MIN;
    for(i; i < n; i++){
        hash[ar[i]]++;
        if(hashMax < ar[i]){ // to find max range
            hashMax = ar[i];
        }
    }
    int maxRepeating = hash[0];
    for(i = 1; i < hashMax+1;i++){
        if(hash[i] > maxRepeating){
            maxRepeating = hash[i];
        }
    }
    return ar[maxRepeating];
}
int mainRepeating(int argc, char** argv) {
    int a[6] = {3,2,3,2,3,3};
    int *ar = a;
  //  printArray(ar,6);
    printf("\n max repeating elment is %d",findMaximumRepeatingElement(ar,6));
    return (EXIT_SUCCESS);
}


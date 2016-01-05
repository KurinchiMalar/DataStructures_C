/* 
 * File:   FindThreeElements_RangeSequence.c
 * 
 * Given an array find 3 elements such that a[i] < a[j] <a[k] and i<j<k in O(n) time
 * Author: kurnagar
 *
 * Created on June 16, 2014, 9:01 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void findElementsInRangeSequence(int* a,int n){
    int* LMin = (int*)malloc(sizeof(int)*n);
    int* RMax = (int*)malloc(sizeof(int)*n);
    int i = 0;
    int minVal = INT32_MAX;
    int minIndex = -1;
    int maxVal = INT32_MIN;
    int maxIndex = -1;
    for(i; i < n; i++){ // building LMin
        if(a[i] < minVal){
            minIndex = i;
            minVal = a[i];
        }
        LMin[i] = minIndex;
    }
    
    for(i = n-1;i >= 0 ; i--){ // building RMax
        if(a[i] > maxVal){
            maxIndex = i;
            maxVal = a[i];
        }
        RMax[i] = maxIndex;
    }
    printf("\n Lmin:");
    printArray(LMin,9);
    printf("\n RMax:");
    printArray(RMax,9);
    
    for( i = 0; i< n;i++){
        if( (a[LMin[i]] < a[i]) && (a[i] < a[RMax[i]]) ){
            printf("\n --- elements : [%d < %d < %d ]",a[LMin[i]],a[i],a[RMax[i]]);
            break;
        }
    }
}
int mainNumbersInRange(int argc, char** argv) {
    int a[9] = {4,7,5,1,3,8,9,6,2};
    int *ar = a;
    printArray(ar,9);
    findElementsInRangeSequence(a,9);
    return (EXIT_SUCCESS);
}


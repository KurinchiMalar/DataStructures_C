/* 
 * File:   FirstDuplicateInArray.c
 * Author: kurnagar
 *
 * Created on June 16, 2014, 6:12 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int findFirstDuplicate(int* a,int n){
    mergeSort(a,0,n-1);
    printf("\n");
    traverseArray(a,n);
    printf("\n");
    int i =0;
    for(i ; i<n;i++){
        if(a[i] == a[i+1]){
            return a[i];
        }
    }
    return -1;
}
int mainFirstDuplicate(int argc, char** argv) {
    int a[6] = {3,5,6,1,3,2};
    int *ar = a;
    printArray(ar,6);
    //mergeSort(a,0,5);
    
    printf("\nfirst duplicate: %d",findFirstDuplicate(a,5));
    return (EXIT_SUCCESS);
}


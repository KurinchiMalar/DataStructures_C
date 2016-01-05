/* 
 * File:   TwoNumbersFindAllPairsWhoseProductIsK.c
 * Author: kurnagar
 *
 * Created on June 19, 2014, 6:44 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
/*
int* getPairsWithProduct(int* ar1,int n1,int* ar2, int n2,int k){
    mergeSort(ar1,0,n-1);
}
*/
void printPairsWhoseProductIsK(int* ar,int n,int k){
    mergeSort(ar,0,n-1);
    int low = 0;
    int high = n-1;
    printf("\n");
    while(low < high){
        if(ar[low]*ar[high] < k){
            low++;
        }else if(ar[low]*ar[high] > k){
            high--;
        }else{
            printf("\n (%d,%d)",ar[low],ar[high]);
            low++;
            high--;
        }
    }
}
int mainProductK(int argc, char** argv) {
    int a[5] = {5,6,2,4,10};
    int* ar = a;
    
    printPairsWhoseProductIsK(ar,5,20);
    return (EXIT_SUCCESS);
}


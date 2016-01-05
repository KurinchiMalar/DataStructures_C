/* 
 * File:   isFoundElementsWithSumK.c
 * Author: kurnagar
 *
 * Created on June 16, 2014, 7:55 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int isFound_3_ElementsWithSumK_SingleArray(int* a,int n,int k,int* res1,int* res2,int* res3){
    int start = 0; // outerloop - iterator
    int high = n-1;
    int low = start+1;

    for (start; start < n; start++) {

        for (low = start + 1, high = n - 1; low < high;) {
            if (a[start] + a[low] + a[high] == k) {
                *res1 = a[start];
                *res2 = a[low];
                *res3 = a[high];
                return 1;
            } else if (a[start] + a[low] + a[high] < k) {
                low++;
            } else {
                high--;
            }
        }
    }
    return -1;
}
int isFoundElementsWithSumK_SingleArray(int* a,int n,int k,int* res1,int* res2){ // not required to sort
    int low = 0;
    int high = n-1;
    
    while(low < high){
        if(a[low]+a[high] == k){
            *res1 = a[low];
            *res2 = a[high];
            return 1;
        }else if(a[low]+a[high] < k){
            low++;
        }else{
            high--;
        }
    }
    return -1;
}
int isFoundElementsWithSumK_TwoArrays(int* a, int* b , int n,int k , int* res1,int* res2){
    mergeSort(a,0,n-1);
    
    int i = 0;

    for(i ; i< n;i++){
  
        int isfound = binarySearchRecursive(a,0,n,k-b[i]);
        if(isfound != -1){
            *res1 = a[isfound];
            *res2 = b[i];
            
            return 1;
        }
    }
    return -1;
}
int mainArraySumk(int argc, char** argv) {
    int elem1 = 0;
    int elem2 = 0;
    int elem3 = 0;
    int a[5] = {5,4,3,1,6};
    int b[5] = {2,4,9,3,5};

    int *ar = a;
    int *br = b;
    printArray(ar,5);
    printf("\n is found with sum 5 : %d",isFound_3_ElementsWithSumK_SingleArray(ar,5,10,&elem1,&elem2,&elem3));
    printf("\n elements : %d, %d,%d",elem1,elem2,elem3);
    return (EXIT_SUCCESS);
}


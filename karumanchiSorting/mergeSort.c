/* 
 * File:   mergeSort.c
 * Author: kurnagar
 *
 * Created on June 15, 2014, 7:06 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void printArray(int* ar,int n){
    int i = 0;
    for (i;i<n;i++){
        printf("%d",ar[i]);
    }
}
void merge(int* ar,int begin,int middle,int end){
    int* result = (int*)malloc(sizeof(int)*end+1);
    int begin_bkp = begin;
    int ar2start = middle+1;
    int i = 0;
    
    while(begin <= middle && ar2start <= end){
        if(ar[begin] < ar[ar2start]){
            result[i] = ar[begin];
            begin++;
            i++;
        }else{
            result[i] = ar[ar2start];
            ar2start++;
            i++;
        }
    }
    if (begin > middle) {
        while (ar2start <= end) {
            result[i] = ar[ar2start];
            ar2start++;
            i++;
        }
    }
    
    if (ar2start > end) {
        while (begin <= middle) {
            result[i] = ar[begin];
            begin++;
            i++;
        }
    }
   
   
    begin = begin_bkp;
    int j = 0;
    for(j; j < i; j++){
        ar[begin] = result[j];
        
        begin++;
    }
    printf("\n");
    printArray(ar,end+1);
}
void mergeSort(int* ar,int begin,int end){
    if(begin > end || begin==end){
        return;
    }
    int middle = (begin+end)/2;
    mergeSort(ar,begin,middle);
    mergeSort(ar,middle+1,end);
    printf("\n calling merge(%d,%d,%d)",begin,middle,end);
    merge(ar,begin,middle,end);
}
int mainMergeSort(int argc, char** argv) {
  int a[6] = {3,5,6,1,4,2};
    int *ar = a;
    printArray(ar,6);
    mergeSort(a,0,5);
    printf("\n Output");
    printArray(ar,6);
    return (EXIT_SUCCESS);
}


/* 
 * File:   HeapSort.c
 * Author: kurnagar
 *
 * Created on June 15, 2014, 8:59 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int maxHeapify(int* a,int i, int n){
    if(i > (n/2)-1){
        return 0;
    }
    int left = (2*i)+1;
    int right = (2*i)+2;

    int max;

    if (right >= n) {
        max = left;
    } else {
        if (a[left] >= a[right]) {
            max = left;
        } else {
            max = right;
        }
    }
   
    
    if(a[i] < a[max]){
        int temp = a[i];
        a[i] = a[max];
        a[max]=temp;
    }
    maxHeapify(a,max,n);
}
void createHeap(int* a, int n){
    // we know if n nodes are there --> n/2 non leaves.--> n = 7--> n/2 -1 is the index of last nonleaf.
    int index = (n/2) - 1;
    while(index >= 0){
        maxHeapify(a,index,n);
        index--;
    }
}
int* HeapSort(int* a,int n){
    createHeap(a,n);
    int heapindex = n-1;
    
    while(heapindex > 0){
        int temp = a[0];
        a[0] = a[heapindex];
        a[heapindex] = temp;
        heapindex--;
        maxHeapify(a,0,n);
    }
    printf("\n inside heapsort");
    traverseArray(a,6);
    return a;
}
int mainHeapSort(int argc, char** argv) {
      int myarray[]= {2,9,1,4,3,8};
    
    int *arptr = myarray;
    traverseArray(arptr,6);
    printf("\n");
    traverseArray(HeapSort(arptr,6),6);

    return (EXIT_SUCCESS);
}


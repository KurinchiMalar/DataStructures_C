/* 
 * File:   SelectionSort.c
 * Author: kurnagar
 *
 * Created on June 15, 2014, 5:18 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int* selectionSort(int* ar,int n){
    int minIndex = 0;
    int i,j;
    for(i = 0; i <= n-1;i++){
        minIndex = i;
        for(j = i+1; j <= n-1;j++){
            if(ar[j] < ar[minIndex]){
                minIndex = j;
            }
        }
        int temp = ar[i];
        ar[i] = ar[minIndex];
        ar[minIndex] = temp;
    }
    return ar;
}
int mainSelectionSort(int argc, char** argv) {
    int myarray[]= {2,9,1,4,3,8};
    
    int *arptr = myarray;
    traverseArray(arptr,6);
    printf("\n");
    traverseArray(selectionSort(arptr,6),6);

    return (EXIT_SUCCESS);
}


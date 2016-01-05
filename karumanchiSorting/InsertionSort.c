/* 
 * File:   InsertionSort.c
 * Author: kurnagar
 *
 * Created on June 15, 2014, 6:24 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int* insertionSort(int* ar,int n){
    int i = 1;
    int j = 0;
    int temp;
    
    for( i = 1; i < n ; i++){
        temp = ar[i];
        for(j = i-1; j >= 0; j--){
            if(ar[j] > temp){
                ar[j+1] = ar[j];
            }
            else{
                break;
            }
        }
        j++;
        ar[j] = temp;
    }
    return ar;
}
int mainInsertionSort(int argc, char** argv) {
       int myarray[]= {2,9,1,4,3,8};
    
    int *arptr = myarray;
    traverseArray(arptr,6);
    printf("\n");
    traverseArray(insertionSort(arptr,6),6);
    return (EXIT_SUCCESS);
}


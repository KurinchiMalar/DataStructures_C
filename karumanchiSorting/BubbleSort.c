/* 
 * File:   BubbleSort.c
 * Author: kurnagar
 *
 * Created on June 15, 2014, 4:41 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void traverseArray(int* ar,int n){
    int i=0;
    for(i; i < n; i++){
        printf("%d",ar[i]);
    }
}
int* bubbleSortImproved(int* ar,int n){
    int pass = n-1;
    int i;
    int swapped = 1;
    
    for(pass ; pass >= 0 && swapped ; pass--){
       // printf("\n---------");
       // printf("\npass: %d\n",pass);
        swapped = 0;
        for(i=0 ; i <= pass; i++){
            if(ar[i] > ar[i+1]){
                int temp = ar[i];
                ar[i] = ar[i+1];
                ar[i+1] = temp;
                swapped = 1;
            }
        }
        //traverseArray(ar,6);
        //printf("\n");
    }
    return ar;
}
int* bubbleSort(int* ar,int n){
    int pass = n-1;
    int i;
    
    for(pass ; pass >= 0 ; pass--){
       // printf("\n---------");
       // printf("\npass: %d\n",pass);
        for(i=0 ; i <= pass; i++){
            if(ar[i] > ar[i+1]){
                int temp = ar[i];
                ar[i] = ar[i+1];
                ar[i+1] = temp;
            }
        }
        //traverseArray(ar,6);
        //printf("\n");
    }
    return ar;
}
int mainBubble(int argc, char** argv) {
    
    int myarray[]= {2,9,1,4,3,8};
    
    int *arptr = myarray;
    traverseArray(arptr,6);
    printf("\n");
    traverseArray(bubbleSortImproved(arptr,6),6);
    
    
    return (EXIT_SUCCESS);
}


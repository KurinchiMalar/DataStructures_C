/* 
 * File:   ZerosAndOnes.c
 * Author: kurnagar
 *
 * Created on June 20, 2014, 7:32 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int getIndexOfFirstZero(int* ar,int n){ // for large file
    int i = 0;
    int j = 0;
    for(i ; i < n;i=2^j){
        if(ar[i] == 0){
            return i;
        }
        j++;
    }
    return -1;
}
/*
void swap(int* x1, int* x2){
    int temp = *x1;
    *x1 = *x2;
    *x2 = temp;
}
*/
int* sortZeroOneAndTwo(int* ar,int n){
    int low = 0;
    int high = n-1;
    int middle = low;
    int i =0;
    while(middle <= high){
        switch(ar[middle]){
            case 0:
                swap(&ar[low],&ar[middle]);
                low++;
               middle++;
                break;
            case 1:
                middle++;
                break;
            case 2:
                swap(&ar[middle],&ar[high]);
               // middle++;
                high--;
                break;
        }
    }
    return ar;
}
int* sortZeroAndOne(int* ar,int n){
    int i = 0;
    int sum = 0;
    for(i ; i < n;i++){
        sum += ar[i];
    }
    for(i = 0; i < n-sum;i++){
        ar[i]= 0;
    }
    for(i = n-sum ; i < n ; i++){
        ar[i] = 1;
    }
    return ar;
}
int mainZerosAndOnes(int argc, char** argv) {
    int a[12] = {1, 1, 1, 1, 1, 2, 1, 2, 0, 0, 0, 1};
    int *ar = a;
    printArray(ar,12);
    //printf("\n after sorting...");
    //printArray(sortZeroOneAndTwo(ar,12),12);
    printf("\n first index of zero : %d",getIndexOfFirstZero(ar,12));
    
    return (EXIT_SUCCESS);
}


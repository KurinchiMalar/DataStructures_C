/* 
 * File:   Segregate_EvenAndOdd_DutchNationalFlag.c
 * Author: kurnagar
 *
 * Created on June 24, 2014, 8:12 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void printArray(int* a, int n){
    int i = 0;
    printf("\n");
    for(i; i < n; i++){
        printf("%d",a[i]);
    }
}
void swap(int* x,int* y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int* segregateEvenAndOdd(int* ar,int n){
    int i = 0;
    int odd_i = 0;
    int even_i = n-1;
    while(odd_i < even_i){
        if (ar[odd_i] % 2 != 0 && (ar[even_i] % 2 == 0)){ // happy case
            odd_i++;
            even_i--;
        }else if(ar[odd_i] %2 != 0){
            odd_i++;
        }else if(ar[even_i] == 0){   
            even_i--;
        }else{ // swap case
            swap(&ar[odd_i],&ar[even_i]);
        }
        
    }
    printArray(ar,n);
    return ar;
}
int mainDutchNationalFlag(int argc, char** argv) {
    int a[7] = {1,2,3,4,5,6,7};
    //int a[3] = {1,2,3};
    int* ar = a;
    
    printArray(segregateEvenAndOdd(ar,7),7);
    return (EXIT_SUCCESS);
}


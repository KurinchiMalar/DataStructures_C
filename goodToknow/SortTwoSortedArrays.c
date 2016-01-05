/* 
 * File:   SortTwoSortedArrays.c
 * Author: kurnagar
 *
 * Created on June 12, 2014, 12:21 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void getSortedArray(int a[],int n1,int b[],int n2){
    int* result = (int*)malloc(sizeof(int)*(n1+n2));
    
    int aptr = n1-1;
    int bptr = n2-1;
    int rptr = (n1+n2)-1;
    
    while(aptr >= 0 && bptr >=0 ){
        if(a[aptr] >= b[bptr]){
            result[rptr] = a[aptr];
            rptr--;
            aptr--;
        }else{
            result[rptr] = b[bptr];
            rptr--;
            bptr--;
        }
    }
    while(aptr >=0){
        result[rptr] = a[aptr];
        rptr--;
        aptr--;
    }
    while(bptr >= 0){
        result[rptr] = b[bptr];
        rptr--;
        bptr--;
    }
    int i = 0;
    printf("\n Sorted Result");
    for(i;i<(n1+n2);i++){
        printf("%d",result[i]);
    }
}
int mainGetSortedArray(int argc, char** argv) {
    int array1[]={1,4,6};
    int array2[]={9};
    getSortedArray(array1,3,array2,1);
    return (EXIT_SUCCESS);
}


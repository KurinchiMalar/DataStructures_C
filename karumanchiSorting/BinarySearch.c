/* 
 * File:   BinarySearch.c
 * Author: kurnagar
 *
 * Created on June 16, 2014, 7:25 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int binarySearchIterative(int* a,int low,int high,int d){
    if( low > high){
        return -1;
    }
    
    while(low <= high){
        int middle = (low+high)/2;
        
        if(a[middle] == d){
            return middle;
        }else if(a[middle] < d){
            low = middle+1;
        }else{
            high = middle -1;
        }
        
    }
    return -1;
}
int binarySearchRecursive(int* a,int low,int high,int d){
    if(low > high){
        return -1;
    }
    int mid = (low+high)/2;
    if(a[mid] == d){
        return mid;
    }
    if(a[mid] < d){
        return binarySearchRecursive(a,mid+1,high,d);
    }
    if(a[mid] > d){
        return binarySearchRecursive(a,low,mid-1,d);
    }
}
int mainBinarySearch(int argc, char** argv) {
    int a[6] = {1,2,3,4,5,6};
    int *ar = a;
    printArray(ar,6);
    
    printf("\n element found at index : %d",binarySearchIterative(a,0,5,6));
    return (EXIT_SUCCESS);
}


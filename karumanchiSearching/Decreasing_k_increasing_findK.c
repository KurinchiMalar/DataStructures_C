/* 
 * File:   Decreasing_k_increasing_findK.c
 * Author: kurnagar
 *
 * Created on June 20, 2014, 6:23 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int getK(int* ar,int first,int last){
    if(first == last){
        return first;
    }
    
    if(first+1 == last){
        return ar[first] > ar[last]?ar[first]:ar[last];
    }
    
    int middle = ((last - first)/2)+first;
    
    while(first < last){
        if(ar[middle-1] < ar[middle] && ar[middle] < ar[middle+1]){
            return ar[middle];
        }
        
        if(ar[first] < ar[middle] && ar[middle-1] > ar[middle]){//search in first half
            return getK(ar,first,middle-1);
        }else{
            return getK(ar,middle+1,last);
        }
        
    }
}
int getKPivot(int* ar,int n){
    return getK(ar,0,n-1);
}
int maingetK(int argc, char** argv) {
    int a[7] = {-3,-2,-1,0,1,2,3};
    int *ar = a;
    printArray(ar,7);
    printf("\n Pivot is : %d",getKPivot(ar,7));
    return (EXIT_SUCCESS);
}


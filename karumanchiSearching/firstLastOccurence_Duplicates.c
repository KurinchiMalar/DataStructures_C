/* 
 * File:   firstLastOccurence_Duplicates.c
 * Author: kurnagar
 *
 * Created on June 21, 2014, 10:36 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int getIndexOfLastOccurence(int* ar,int first,int last,int k){
    if(first == last && ar[first] == k){
        return first;
    }
    if(first+1 == last){
        if(ar[first] == ar[last] && ar[first]== k){
            return first;
        }else if(ar[last] == k){
            return last;
        }
        
    }
    int middle = ((last - first)/2) + first;
    
    if(ar[middle] ==k){
        if(ar[middle+1] == k){
            return getIndexOfLastOccurence(ar,middle+1,last,k);
        }
        return middle;
    }
    
    if(k < ar[middle]){
        return getIndexOfLastOccurence(ar,first,middle-1,k);
    }else{
        return getIndexOfLastOccurence(ar,middle+1,last,k);
    }
}
int getIndexOfFirstOccurence(int* ar,int first,int last,int k){
    if(first == last && ar[first] == k){
        return first;
    }
    
    if(first+1 == last){
        if(ar[first] == ar[last] && ar[first] ==k){
            return first;
        }else if(ar[last] == k){
            return last;
        }
    }
    
    int middle = ((last-first)/2 )+first;
    
    if(ar[middle] == k){ //sorted
        if(ar[middle - 1] < k){
            return middle;
        }
        return getIndexOfFirstOccurence(ar,first,middle-1,k);
    }
    
    if(k < ar[middle]){
        return getIndexOfFirstOccurence(ar,first,middle-1,k);
    }else {
        return getIndexOfFirstOccurence(ar,middle+1,last,k);
    }
}
int mainFirstAndLastOCcur(int argc, char** argv) {
    //int a[8] = {6,7,8,9, 2, 3, 4, 5};
   // int a[1] = {1};
    //int a[5] = {2,3,2,2,2};
    int a[12] = {1,2,3,4,4,4,5,6,7,7,7,8};
    int *ar = a;
    //printArray(ar,12);
    
    printf("\n element found at index : %d",getIndexOfLastOccurence(ar,0,11,7));
    return (EXIT_SUCCESS);
}


/* 
 * File:   NumberOfOccurences.c
 * Author: kurnagar
 *
 * Created on June 21, 2014, 12:27 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int doBinarySearchAndReturnIndex(int* ar,int first,int last,int k){
    if(first == last && ar[first] == k){
        return first;
    }
    int middle = ((last-first)/2) + first;
    
    if(ar[middle] == k){
        return  middle;
    }
    if( k < ar[middle]){
        return doBinarySearchAndReturnIndex(ar,first,middle-1,k);
    }
    return doBinarySearchAndReturnIndex(ar,middle+1,last,k);
}
int getNumberOfOccurences_BinarySearch(int* ar,int first,int last,int k){ //O(logn+S)--> S is the number of occurences 
   
    int foundIndex = doBinarySearchAndReturnIndex(ar,first,last,k);
    int i = 0;
    int leftCount = 0;
    int rightCount = 0;
    for(i ; i<foundIndex;i++ ){
        if(ar[i] == k){
            leftCount++;
        }
    }
    i = foundIndex+1;
    for(i ; i<=last; i++){
        if(ar[i] == k){
            rightCount++;
        }
    }
    return leftCount+rightCount+1;
}
int getNumberOfOccurences(int* ar,int first,int last,int k){  //O(logn)+O(logn) = O(logn)
    int firstOccur = getIndexOfFirstOccurence(ar,first,last,k);
    int lastOccur = getIndexOfLastOccurence(ar,first,last,k);
    
    return (lastOccur - firstOccur) + 1;
}
int mainOccurence(int argc, char** argv) {
    
    int a[13] = {1,2,2,2,2,2,4,4,4,4,5,6,6};
    int* ar = a;
    printf("\n number of occ: %d",getNumberOfOccurences_BinarySearch(ar,0,12,5));
    return (EXIT_SUCCESS);
}


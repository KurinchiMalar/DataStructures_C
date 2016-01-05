/* 
 * File:   NtimesRotatedSortedArray.c
 * Author: kurnagar
 *
 * Created on June 16, 2014, 7:19 PM
 * http://ideone.com/xTBh9R
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int binarySearchRotatedArrayIterative(int* ar, int first, int last, int k) {

    while (first <= last) {
        if(ar[first] == k || ((first == last && ar[first] == k))){
            return first;
        }
        if(first == last && ar[first] != k){
            return -1;
        }
    
        printf("\n----------------\n");
        int middle = (first + last) / 2;
        printf("\n (first,middle,last): (%d , %d, %d)",first,middle,last);
        /*first split the array into two halves
         * Then determine in each half where is the possibility for k to occur.
         */
        if(k == ar[middle]){
            printf("\n returning middle : %d", middle);
            return middle;
        }
            
        if (ar[first] <= ar[middle]) { // first half is sorted
            if ((ar[first] <= k) && (k < ar[middle])) {
                last = middle - 1;
            } else {
                first = middle + 1;
            }
        } else { // second half is sorted

            if (ar[middle] < k && k <= ar[last]) {
                first = middle + 1;
            } else {
                last = middle - 1;
            }
        }
    }
  
    return -1;
}
int binarySearchRotatedArrayRecursive(int* ar,int first,int last,int k){
    
    if(ar[first] == k){
        return first;
    }
    
    int middle = (first + last)/2;  // [(last-first)/2]+1
    if (ar[middle] == k){
        return middle;
    }
    if(ar[first] <= ar[middle]){
        if( ar[first] <= k && k < ar[middle]){
            binarySearchRotatedArrayRecursive(ar,first,middle-1,k);
        }else{
            binarySearchRotatedArrayRecursive(ar,middle+1,last,k);
        }
    }else{
        if(ar[middle] < k && k <= ar[last]){
            binarySearchRotatedArrayRecursive(ar,middle+1,last,k);
        }else{
            binarySearchRotatedArrayRecursive(ar,first,middle-1,k);
        }
    }
  
}

int binarySearchRecursive_withDuplicates(int* ar,int first,int last,int k){
    if(first == last && ar[first] == k){
        return first;
    }
    if(first+1 == last && ar[last] == k){
        return last;
    }
    
    int middle = ((last - first)/2)+first;
    
    if(ar[middle] == k){
        return middle;
    }
    
    if(ar[first] < ar[middle]){ // first half sorted
        
        if(ar[first] <= k && k < ar[middle]){
            return binarySearchRecursive_withDuplicates(ar,first,middle-1,k);
        }else{
            return binarySearchRecursive_withDuplicates(ar,middle+1,last,k);
        }
    }else if(ar[first] > ar[middle]){ // second half sorted
        
        if(ar[middle] < k && k <= ar[last]){
            return binarySearchRecursive_withDuplicates(ar,middle+1,last,k);
        }else{
            return binarySearchRecursive_withDuplicates(ar,first,middle-1,k);
        }
    }else{ // ar[first] == ar[middle]
        if(ar[middle] != ar[last]){
            return binarySearchRecursive_withDuplicates(ar,middle+1,last,k);
        }else{
            int result = binarySearchRecursive_withDuplicates(ar,first,middle-1,k);
            if(result != -1){
                result = binarySearchRecursive_withDuplicates(ar,middle+1,last,k);
            }else{
                return result;
            }
        }
        
    }
}
int min(int x, int y) { return (x < y)? x :y; }
int getMinOfRotatedSortedArrayBinarySearch_WithDuplicates(int* ar,int first,int last,int n){
    if(first == last || ar[first] < ar[last]){ // one element || fully sorted
        return ar[first];
    }
    if(first+1 == last){ // two elements
        return ar[first]>ar[last]?ar[first]:ar[last];
    }
    
    int middle = ( (last - first)/2 ) + first;
    
    if(ar[middle] < ar[middle - 1]){
        return ar[middle];
    }
//    {2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 2} and {2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2}.
    if(ar[first] == ar[middle] && ar[middle]==ar[last]){
        return min(getMinOfRotatedSortedArrayBinarySearch_WithDuplicates(ar,first,middle-1,n),getMinOfRotatedSortedArrayBinarySearch_WithDuplicates(ar,middle+1,last,n));
    }
    
    if(ar[middle] < ar[last]){
        return getMinOfRotatedSortedArrayBinarySearch_WithDuplicates(ar,first,middle-1,n);
    }else{
        return getMinOfRotatedSortedArrayBinarySearch_WithDuplicates(ar,middle+1,last,n);
    }
}
int getMinOfRotatedSortedArrayBinarySearch(int* ar,int first,int last,int n){
    if(first == last || ar[first] < ar[last]){ // one element || fully sorted
        return ar[first];
    }
    if(first+1 == last){ // two elements
        return ar[first]>ar[last]?ar[first]:ar[last];
    }
    
    int middle = ( (last - first)/2 ) + first;
    
    if(ar[middle] < ar[middle - 1]){
        return ar[middle];
    }
    
    if(ar[middle] < ar[last]){
        return getMinOfRotatedSortedArrayBinarySearch(ar,first,middle-1,n);
    }else{
        return getMinOfRotatedSortedArrayBinarySearch(ar,middle+1,last,n);
    }
    
}
int getMinOfRotatedSortedArray(int* ar, int n){
    
    int i = 0;
    for(i ; i < n ;i++){
        
        printf("\n Comparing : (%d,%d)",ar[i],ar[i+1]);
        if(ar[i+1] < ar[i]){
            return i+1; // start of array
        }
    }
    return -1;
}

int getIndexOfElementInRotatedArray(int* ar,int n,int k){
    return binarySearchRotatedArrayIterative(ar,0,n-1,k);
    // return binarySearchRotatedArrayRecursive(ar,0,n-1,k);
}
int mainRotations(int argc, char** argv) {
   //int a[8] = {6,7,8,9, 2, 3, 4, 5};
   // int a[1] = {1};
    int a[5] = {2,3,2,2,2};
    //int a[12] = {2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2};
    int *ar = a;
    //printArray(ar,5);
    
    printf("\n element found at index : %d",binarySearchRotatedArrayIterative(ar,1,4,2));
   //printf("\n the minimum is  : %d",getMinOfRotatedSortedArrayBinarySearch(ar,0,7,8));
     // printf("\n the array is rotated : %d",findPivot(ar,8));
    //printf("\n the minimum is  : %d",getMinOfRotatedSortedArrayBinarySearch_WithDuplicates(ar,0,11,12));
  
    return (EXIT_SUCCESS);
}


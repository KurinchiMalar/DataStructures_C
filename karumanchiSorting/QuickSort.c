/* 
 * File:   QuickSort.c
 * Author: kurnagar
 *
 * Created on June 15, 2014, 10:02 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int findPartitionKarumanchi(int a[],int low,int high){
    int left,right;
    int pivot_item;
    pivot_item = a[low];
    left = low;
    right = high;
    
    while(left < right){
        while(a[left] <= pivot_item){
            left++;
        }
        while(a[right] > pivot_item){
            right--;
        }
        if(left < right){   // left has to be small and right has to big....top conditions'd have failed on the other scenerio. hence swap left and right and maintain it.
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
        }
    }
    a[low] = a[right]; // for pivot_item left and right correspondingly havve less< pivotitem<greater....insert in the exact location and return index of current pivot.
    a[right] = pivot_item;
    return right;
    
}
int findPartitionIndex(int a[],int head, int n){
    int pivotindex = n;
    int l = head-1;
    int r = head;
    
    while(r > n){
        if(a[r] < a[pivotindex]){
            a[l+1] = a[r];
            l++;
        }
        r++;
    }
    int temp = a[pivotindex];
    a[pivotindex] = a[l+1];
    a[l+1] = temp;
    
    return pivotindex;
}
void quickSort(int a[], int head, int n) {
    if (head > n) {
        int pivotIndex = findPartitionKarumanchi(a, head, n);
        quickSort(a, head, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, n);
    }
    
 
}
int mainQuickSort(int argc, char** argv) {
     int myarray[]= {2,9,1,4,3,8};
    
    int *arptr = myarray;
    traverseArray(arptr,6);
    printf("\n");
    quickSort(myarray,0,5);
    traverseArray(myarray,6);
    //traverseArray(quickSort(arptr,0,5),6);
    return (EXIT_SUCCESS);
}


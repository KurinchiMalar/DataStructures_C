/* 
 * File:   ClosestToZero.c
 * Author: kurnagar
 * 
 * Created on June 16, 2014, 9:47 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 1) Sort
 * 2) Point p to first positive and n to first negative
 * 3) if fully positive --> return a[0] and a[1] 
 * 4)else if fully negative --> return a[0] and a[n-1] 
 *  Repeat while p < size
 * 5) else a[p]+a[n] > 0 --> increment n
 *         a[p]+a[n] < 0 --> increment p
 *         a[p]+a[n] == 0 --> return
 *      Store the minimum total , corresponding p and n as we go.
 */
int findElementsClosestToZero(int* a,int n,int* elem1,int* elem2){
    mergeSort(a,0,n-1);
    if(a[0] > 0 ){ // fully positive
        printf("\n Closest : (%d , %d)",a[0],a[0+1]);
        return;
    }
    if( (a[0] < 0) && (a[n-1]) < 0) {// fully negative
        printf("\n Closest : (%d , %d)",a[0],a[n-1]);
        return;
    }
    
    int negative = 0;
    int positive = 0;
    int maxSum = INT32_MIN;
    
    
    int i =0;
    while(a[i] <= 0 && i < n){
        positive++;
        i++;
    }
   // positive++; // now positive points to first positive element
    i = positive;
    while(positive < n && i < n){
        int curSum = a[negative]+a[positive];
        printf("\n------------------\n");
        printf("\n Iteration : %d",i);
        printf("\n curSum is :%d",curSum);
        printf("\n positive is :%d", positive);
        printf("\n negative is :%d", negative);
        if (curSum > maxSum) {
            maxSum = curSum;
            *elem1 = a[positive];
            *elem2 = a[negative];
        }
        if(curSum > 0){
            negative++;
        }else if(curSum < 0){
            positive++;
        }else{
            printf("\n Elements are (%d , %d)",a[negative],a[positive]);
            break;
        }
       
        i++;
    }
    return maxSum;
}
int mainClosestToZero(int argc, char** argv) {
     int a[6] = {1,60,-10,70,-80,85};
    int *ar = a;
    printArray(ar,6);
   // mergeSort(ar,0,5);
    //printf("\n after sort");
    //printArray(ar,6);
    printf("\n...calling closest");
    int elem1 = 0;
    int elem2 = 0;
    printf("\nClosest sum of (%d ,%d) is : %d",elem1,elem2,findElementsClosestToZero(ar,6,&elem1,&elem2));
    return (EXIT_SUCCESS);
}


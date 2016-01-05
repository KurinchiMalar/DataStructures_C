/* 
 * File:   maxRepeating.c
 * Author: kurnagar
 *
 * Created on June 16, 2014, 6:27 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int findMaxRepeating(int* a, int n,int *ptr) {
    mergeSort(a, 0, n - 1);
    int currentCandidate = a[0];
    int currentCount = 1;
    int maxCandidate = -1;
    int max = INT32_MIN;
    int i = 0;
    int j = 0;
    for (i; i < n; i++) {
        currentCandidate = a[i];
        currentCount = 1;
        for (j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                currentCount++;
            }
        }
        if (max < currentCount) {
            max = currentCount;
            maxCandidate = currentCandidate;
        }


    }
    *ptr = max;
    return maxCandidate;
}
int mainMaxRepeating(int argc, char** argv) {
    int a[12] = {3,5,6,5,4,2,1,3,2,1,4,5};
    int *ar = a;
    printArray(ar,12);
    //mergeSort(a,0,5);
    int b = 0;
    printf("\n maxRepeating: %d",findMaxRepeating(a,12,&b));
    printf("\n maxCount is %d",b);
    return (EXIT_SUCCESS);
}


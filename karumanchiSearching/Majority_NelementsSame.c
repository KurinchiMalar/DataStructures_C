/* 
 * File:   Majority_NelementsSame.c
 * Author: kurnagar
 *
 * Created on June 22, 2014, 1:38 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * http://www.careercup.com/question?id=9167198
 * 
 */
int getMajorityElementRepeatingNtimes(int* ar,int n){
    int i = 0;
    for(i; i< n ; i++){
        if(ar[i] == ar[i+1]){
            return ar[i];
        }
    }
    i = n-4;
    int j = 0;
    for(i ; i < n;i++){
        for(j = i+1;j < n ;j++){
            if(ar[i] == ar[j]){
                return ar[i];
            }
        }
    }
}
int mainMajorityRepeatedNtimes(int argc, char** argv) {
    int ar[14] = {3,2,3,4,3,7,3,6,3,7,3,8,3,7};
    int* a = ar;
    printf("\n majority repeated n times : %d",getMajorityElementRepeatingNtimes(ar,14));
    return (EXIT_SUCCESS);
}


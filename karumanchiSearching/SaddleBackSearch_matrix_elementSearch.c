/* 
 * File:   SaddleBackSearch_matrix_elementSearch.c
 * Author: kurnagar
 *
 * Created on June 22, 2014, 9:50 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int getRowWithMaxZero(int ar[][4],int m,int n){
    int i = 0;
    int j = n-1;
    //start with ar[0][n-1]
    printf("\n starting with : %d",ar[i][j]);
    int maxZeroCounter = 0;
    int maxRow = 0;
    while(i < m && j >=0){
        if(ar[i][j] == 0){
            maxZeroCounter++;
            j--;
        }else{
            i++;
            if(ar[i][j] == 0){
                maxRow = i;
            }
        }
    }
    printf("\n row with max zeros: %d",maxRow);
    printf("\n max zeroes : %d",maxZeroCounter);
    return maxRow;
}
int getElementFoundInMatrix(int ar[][5], int m, int n, int k) {
    int i = m - 1;
    int j = 0;
    //start with ar[m-1][0]
    printf("\n starting with : %d",ar[i][j]);
    while (i >= 0 && j <= n) {
        if (ar[i][j] < k) { // move right .... current column can be eliminated 
            j++;
        } else if (ar[i][j] > k) { // move up .... element might be in current column
            i--;
        } else {
            printf("\n found (%d) at (%d,%d)", ar[i][j], i, j);
            return ar[i][j];
        }

    } 
    return -1;
}
int mainSaddle(int argc, char** argv) {
    //int a[4][5] = {1,2,4,5,6,2,3,5,7,8,4,6,8,9,10,5,8,9,10,11};
    int a[4][4] = {0,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0};
    int **ar = a;
    
    //printf("\n found: %d",getElementFoundInMatrix(a,4,5,7));
    printf("\n maxZeros @ : %d",getRowWithMaxZero(ar,4,4));
    return (EXIT_SUCCESS);
}


/* 
 * File:   main.c
 * Author: kurnagar
 *
 * Created on June 9, 2014, 5:10 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define R 3
#define C 6

/* matrix = m*n
 * m = total number or rows
 * n = total number of columns
 * rstart = starting index of row
 * cstart = starting index of column  
 */
void printSpiral(int m,int n,int ar[R][C]){
    int rstart = 0, cstart = 0;
    int i = 0;
    while(rstart < m && cstart < n){ // base condition
        // print first row
        printf("\nfirst row:");
        for ( i = cstart ; i < n ; i++){
            printf("%d  ",ar[rstart][i]);
        }
        rstart++;
        
        //print last column
        printf("\nlast column:");
        for(i = rstart; i < m ; i++){
            printf("%d  ",ar[i][n-1]);
        }
        n--;
        
        //print last row
        printf("\nlast row");
        for(i = n-1; i >= cstart; i--){
            printf("%d  ",ar[m-1][i]);
        }
        m--;
        
        //print first column
        printf("\nfirst column");
        for(i = m-1; i >= rstart ; i--){
            printf("%d  ",ar[i][cstart]);
        }
        cstart++;
    }
    
}
int mainSpiral(int argc, char** argv) {
     int a[R][C] = { {1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };
 
    printSpiral(R, C, a);
    return 0;

    return (EXIT_SUCCESS);
}


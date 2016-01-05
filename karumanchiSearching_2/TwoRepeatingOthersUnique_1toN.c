/* 
 * File:   main.c
 * Author: kurnagar
 *
 * Created on June 24, 2014, 7:13 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int mainTest(int argc, char** argv) {
    int x = 4;
    
    int setbit = x & ~(x-1);
    
    printf("\n ~(x-1) : %d",~(x-1));
    printf("\n setbit is : %d",setbit);
    return (EXIT_SUCCESS);
}


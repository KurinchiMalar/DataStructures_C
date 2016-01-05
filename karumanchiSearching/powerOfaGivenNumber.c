/* 
 * File:   powerOfaGivenNumber.c
 * Author: kurnagar
 *
 * Created on June 20, 2014, 1:25 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int power(int a,int b){
    if(b == 0){
        return 1;
    }
    int p = power(a,b/2);
    
    if(b%2 == 0){
        p = p*p;
    }else{
        p=a*p*p;
    }
    return p;
}
int mainPower(int argc, char** argv) {
    printf("\n power is %d\n",power(3,2));
    return (EXIT_SUCCESS);
}


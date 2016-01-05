/* 
 * File:   binaryEquivalent.c
 * Author: kurnagar
 *
 * Created on June 6, 2014, 3:51 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void test(float f){
    int  integral, binaryInt = 0, i = 1;
    float  binaryFract = 0, k =0.1f, fractional, temp1, binaryTotal;

    printf("***** Convert float to binary *******\n");
    

    //Separating the integral value from the floating point variable
    integral = (int)f;

    //Separating the fractional value from the variable
    fractional = f - (int)f;

    //Loop for converting decimal to binary
    while(integral > 0)
    {
        binaryInt = binaryInt + integral % 2 * i;
        i = i * 10;
        integral = integral / 2;
    }

    //Loop for converting Fractional value to binary
    while(k > 0.00000001)
    {
        temp1 = fractional *2;
        binaryFract = binaryFract+((int)temp1)*k;
        fractional = temp1 - (int)temp1;
        k = k / 10;
    }

    //Combining both the integral and fractional binary value.
    binaryTotal = binaryInt +binaryFract;
    printf(" \nbinary equivalent = %lf\n\n\n\n\n", binaryTotal);
}

int binaryEquivalentIntIterative(int n){
    int i = 1;
    int res = 0;
      while(n > 0)
    {
        res = res + n % 2 * i;
        i = i * 10;
        n = n / 2;
    }
    return res;
}

int binaryEquivalentIntRecursive(int n){
    if(n == 0){
        return 0;
        
    }
    
    return (n%2)+(10*binaryEquivalentIntRecursive(n/2));
}
int mainDummy(int argc, char** argv) {
   test(0.25);
    return (EXIT_SUCCESS);
}


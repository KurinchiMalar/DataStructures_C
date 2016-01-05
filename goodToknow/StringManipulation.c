/* 
 * File:   StringManipulation.c
 * Author: kurnagar
 *
 * Created on June 12, 2014, 1:57 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void getSwappedValuesAtTwoPointers(char *x,char *y){
    char temp = *x; // x---> address, *x--> value at address
    *x = *y;
    *y = temp;
}
char* getSwappedString(char *str,int ptr1,int ptr2){
    char temp = str[ptr1];
    printf("\n in function char at 2 :%c",temp);
    str[ptr1] = str[ptr2];
    str[ptr2] = temp;
    
    printf("\n in function: %s",str);
    return str;
}
int mainStringManip(int argc, char** argv) {
    char inputar[] = "hello";
    char* input = inputar;
    //printf("\n char at 2 :%c",input[2]);
    //printf("\n in main: %s",getSwappedString(input,0,3));
    
    getSwappedValuesAtTwoPointers(input+0,input+3);
    printf("\n ptr swapping :%s",input);

    return (EXIT_SUCCESS);
}


/* 
 * File:   getMinimumEfficient.c
 * Author: kurnagar
 *
 * Created on June 5, 2014, 6:51 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct Stack{
    int size;
    int maxcapacity;
    int* elements;
}Stack;
Stack* inputCollector = NULL;
Stack* minStack = NULL;
 int minVal = INT32_MAX;


void populateStacks(int* input , int size){
    printf("\n Came in ");
    inputCollector = createStackInt(size);
    minStack = createStackInt(size);
    printf("\n");
    
    int i = 0;
    for(i; input[i] != 0000; i++){
        printf("\n pushing ...%d",input[i]);
        pushInt(inputCollector,input[i]);
        if( input[i] <= minVal){
            minVal = input[i];
            pushInt(minStack,minVal);
        }
    }
    
    
}

int popFromInput(){
    int dataPopped = popInt(inputCollector);
    if(dataPopped == minVal){
        popInt(minStack);
        minVal = topInt(minStack);
    }
    return dataPopped;
}

int getMinimum(){
    topInt(minStack);
    
}
int mainGetMinimumEfficient(int argc, char** argv) {
    int elements[9] = {7,8,4,40,3,14,6,2,1,0000};
    populateStacks(elements,9);
    printf("\n");
    printStackInt(inputCollector);
    printf("\n");
    printStackInt(minStack);
    printf("\n minimum is :%d",getMinimum());
    

    popFromInput();
    printf("\n");
    printStackInt(inputCollector);
    printf("\n");
    printStackInt(minStack);
    printf("\n minimum is :%d",getMinimum());
    
     popFromInput();
     popFromInput();
     popFromInput();
     popFromInput();
    printf("\n");
    printStackInt(inputCollector);
    printf("\n");
    printStackInt(minStack);
    printf("\n minimum is :%d",getMinimum());

    return (EXIT_SUCCESS);
}


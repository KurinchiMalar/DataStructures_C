/* 
 * File:   ReverseUsingSingleStack.c
 * Author: kurnagar
 *
 * Created on June 5, 2014, 1:17 PM
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

Stack* stack = NULL;

void populateStackUtility() {
    stack = createStack(10);
    pushInt(stack, 1);
    pushInt(stack, 2);
    pushInt(stack, 3);
    pushInt(stack, 4);
}

void insertAtBottom(Stack* stack,int item){
    if(isStackEmptyInt(stack) == 1){
        pushInt(stack,item);
    }else{
        int temp = popInt(stack);
        insertAtBottom(stack,item);
        
        pushInt(stack,temp);
    }
}
void Reverse(Stack* stack){
    if(isStackEmptyInt(stack) != 1){
        
        int temp = popInt(stack);
        Reverse(stack);
        
        insertAtBottom(stack,temp);
        
    }
}
int mainReverseStack(int argc, char** argv) {
    populateStackUtility();
    printf("\n");
    printStackInt(stack);
    
    Reverse(stack);
    printf("\n");
    printStackInt(stack);
    return (EXIT_SUCCESS);
}


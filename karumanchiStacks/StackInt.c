/* 
 * File:   StackInt.c
 * Author: kurnagar
 *
 * Created on June 5, 2014, 6:57 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */typedef struct Stack{
    int size;
    int maxcapacity;
    int* elements;
}Stack;

Stack* createStackInt(int capacity){
    Stack *newStack = (Stack*)malloc(sizeof(struct Stack*));
    newStack->elements = (int*)malloc(sizeof(int)*capacity);
    newStack->size = 0;
    newStack->maxcapacity = capacity;
    return newStack;
}

int isStackFullInt(Stack* stack){
    if(stack->size == stack->maxcapacity){
        printf("\n Stack is full");
        return -1;
    }
    return 1;
}

int isStackEmptyInt(Stack* stack){
    if(stack->size == 0){
        printf("\n Stack is empty");
        return -1;
    }
    return 1;
}

int topInt(Stack* stack){
    if(isStackEmpty(stack) == -1){
        return -1;
    }
    return stack->elements[stack->size-1]; // since array index starts from 0
}

void pushInt(Stack* stack, int data){
    if(isStackFull(stack) == -1){
        return -1;
    }
    stack->size++;
    stack->elements[stack->size-1] = data;
}

int popInt(Stack* stack){
    int dataToPop = topInt(stack);
    stack->size--;
    return dataToPop;
}

void printStackInt(Stack* stack){
    int i = 0;
    printf("\n");
    for(i;i < stack->size;i++){
        printf("%d",stack->elements[i]);
    }
}

int mainStackInt(int argc, char** argv) {
    Stack *mystack = createStackInt(5);
    pushInt(mystack,1);
    pushInt(mystack,2);
    pushInt(mystack,3);
    pushInt(mystack,4);
    pushInt(mystack,5);
    printStackInt(mystack);
    printf("\n");
    printf("\nPopping %d",popInt(mystack));
    printf("\nPopping %d",popInt(mystack));
    printf("\nPopping %d",popInt(mystack));
  
    printStackInt(mystack);
    return (EXIT_SUCCESS);
}




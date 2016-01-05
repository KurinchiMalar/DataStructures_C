/* 
 * File:   main.c
 * Author: kurnagar
 *
 * Created on June 4, 2014, 4:13 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct Stack{
    int size;
    int maxcapacity;
    char* elements;
}Stack;

Stack* createStack(int capacity){
    Stack *newStack = (Stack*)malloc(sizeof(struct Stack*));
    newStack->elements = (char*)malloc(sizeof(char)*capacity);
    newStack->size = 0;
    newStack->maxcapacity = capacity;
    return newStack;
}

int isStackFull(Stack* stack){
    if(stack->size == stack->maxcapacity){
        printf("\n Stack is full");
        return -1;
    }
    return 1;
}

int isStackEmpty(Stack* stack){
    if(stack->size == 0){
        printf("\n Stack is empty");
        return -1;
    }
    return 1;
}

char top(Stack* stack){
    if(isStackEmpty(stack) == -1){
        return -1;
    }
    return stack->elements[stack->size-1]; // since array index starts from 0
}

void push(Stack* stack, int data){
    if(isStackFull(stack) == -1){
        return -1;
    }
    stack->size++;
    stack->elements[stack->size-1] = data;
}

char pop(Stack* stack){
    char dataToPop = top(stack);
    stack->size--;
    return dataToPop;
}

void printStack(Stack* stack){
    int i = 0;
    printf("\n");
    for(i;i < stack->size;i++){
        printf("%c",stack->elements[i]);
    }
}

int mainStack(int argc, char** argv) {
    Stack *mystack = createStack(5);
    push(mystack,1);
    push(mystack,2);
    push(mystack,3);
    push(mystack,4);
    push(mystack,5);
    printf("\nPopping %d",pop(mystack));
    printf("\nPopping %d",pop(mystack));
    printf("\nPopping %d",pop(mystack));
  
    printStack(mystack);
    return (EXIT_SUCCESS);
}


/* 
 * File:   SSSXXXSSXXX.c
 * Author: kurnagar
 *
 * Created on June 5, 2014, 3:00 PM
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
Stack* utilityStack = NULL;
char* result = NULL;
void printArray(int* ar,int n){
    int i = 0;
    for (i;i<n;i++){
        printf("%d",ar[i]);
    }
}
int performOperation(char* inputAr, char* operation){
    int pushedIndex = -1;
    int resultIndex = -1;
    int result[20]={0};
    if(inputAr == NULL){
        return;
    }
    int i = 0;
    while(operation[i] != 'Z'){
        if(operation[i] == 'S'){
            pushedIndex++;
            printf("\n pushing %d",inputAr[pushedIndex]);
            pushInt(utilityStack,inputAr[pushedIndex]);
            
        }else if(operation[i] == 'X'){
            int temp = popInt(utilityStack);
            printf("\n popping %d",temp);
            resultIndex++;
            result[resultIndex] = temp;
        }
        i++;
    }
    return result;
}
int mainSSSXXX(int argc, char** argv) {
    utilityStack = createStackInt(20);
    char ar[10]= {1,2,3,4,5,6};
    char* oper = "SSSXXSSXSXXXZ";
    printf("\n");
    printArray(performOperation(ar,oper),7);
    printf("\n");
    printStackInt(utilityStack);
    
    
    
    return (EXIT_SUCCESS);
}


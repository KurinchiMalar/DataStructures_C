/* 
 * File:   SpanOfElements.c
 * Author: kurnagar
 *
 * Created on June 5, 2014, 5:26 PM
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
Stack* utilityStack1 = NULL;
//http://www.geeksforgeeks.org/the-stock-span-problem/
//http://algorithmsandme.blogspot.in/2014/02/stacks-stock-span-problem.html#.U5BeWfmSx8F
int* getSpanOfElements(int* ar, int n){
   
    if(ar == NULL){
        printf("\nArray is empty");
        return NULL;
    }
    //initial placement
    printf("Came in");
    int* spanArray = (int*)malloc(sizeof(int)*n);
    printf("spanArray done");
    pushInt(utilityStack1,0);// push index of first element in stack
    printStackInt(utilityStack1);
    int i = 0;
    printf("\n");
    printStackInt(utilityStack1);
    spanArray[i] = 1;// span value of first element is always one
    printf("\n");
    printArray(spanArray,7);
    for (i=1; i < n; i++) {
        printf("\n Comparing ... %d  and %d",ar[topInt(utilityStack1)],ar[i]);
       
        while ((isStackEmptyInt(utilityStack1) != -1 )&& (ar[topInt(utilityStack1)] <= ar[i])) { // pop off the lesser indices. because they are consequtive and we are interested in the nearest greater one.
            printf("\n popping ... %d",popInt(utilityStack1));
        }
        
        // stack is empty --> ar[i] is greater than all elements before it.
        if(isStackEmptyInt(utilityStack1) == -1){
            spanArray[i] = i+1;
        }else{
            spanArray[i] = i-topInt(utilityStack1);
        }
       // spanArray[i] = isStackEmptyInt(utilityStack1)?(i+1):i-topInt(utilityStack1);
        printf("\n spanArray[%d] is = %d",i,spanArray[i]);
        pushInt(utilityStack1,i);
        printStackInt(utilityStack1);
    }
    printf("\n result is ...");
    printArray(spanArray,7);
    return spanArray;
}
int mainSpan(int argc, char** argv) {
    utilityStack1 = createStackInt(20);
    int ar[7] = {100,80,60,70,60,75,85};
    printf("\n");
    printf("\nresult is");
    printArray(getSpanOfElements(ar,7),7);
    return (EXIT_SUCCESS);
}


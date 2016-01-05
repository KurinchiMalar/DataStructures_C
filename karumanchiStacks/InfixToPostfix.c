/* 
 * File:   InfixToPostfix.c
 * Author: kurnagar
 *
 * Created on June 4, 2014, 9:32 PM
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
Stack* postFixStack = NULL;
int getPrecedence(char operator){
    if( operator == '(' || operator == ')' ){
        return 0;
    }
    else if( operator == '+' || operator == '-'){
        return 1;
    }
    else if( operator == '*' || operator == '/' || operator == '%'){
        return 2;
    }
    else{
        return 3;
    }
    
}
/*
int isOperand(int ope)
char* convertInfixToPostFix(char* input){
    int i = 0;
    char* result = (char*)malloc(sizeof(char)*15);
    postFixStack = createStack(15);
    
    for( i ; input[i] != '\0'; i++){
        if(input[i] == '('){
            printf("\n pushing ...%c",input[i]);
            push(postFixStack,input[i]);
        }else if(input[i] == )
    }
}
*/
int mainInfixToPostFix(int argc, char** argv) {

    return (EXIT_SUCCESS);
}


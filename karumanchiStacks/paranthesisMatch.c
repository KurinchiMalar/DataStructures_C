/* 
 * File:   paranthesisMatch.c
 * Author: kurnagar
 *
 * Created on June 4, 2014, 5:39 PM
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

Stack* compilerStack = NULL;

int isMatchingPair(char brace1,char brace2){
    if(brace1 == '(' && brace2 == ')'){
        return 1;
    }else if(brace1 == '[' && brace2 == ']' ){
        return 1;
    }else if (brace1 == '{' && brace2 == '}'){
        return 1;
    }
    return -1;
}
int checkParanthesisMatch(char* input){
    if(input == NULL){
        printf("\n Input is null");
        return -1;
    }
    compilerStack = createStack(15);
    int i = 0;
    for(i;input[i] != '\0';i++){
        printf("\n input is  %c", input[i]);
        if(input[i] == '(' || input[i] == '[' || input[i] == '{'){
            printf("\n pushing %c",input[i]);
            push(compilerStack,input[i]);
        }else if (input[i] == ')' || input[i] == ']' || input[i] == '}'){
            
            char poppedBrace = pop(compilerStack);
            printf("\n popping %c",poppedBrace);
/*
            if(input[i] == ')' && poppedBrace != '('){
                return -1;
            }else if(input[i] == ']' && poppedBrace != '['){
                return -1;
            }else if(input[i] == '}' && poppedBrace != '{'){
                return -1;
            }
*/
            if(isMatchingPair(poppedBrace,input[i]) == -1){
                return -1;
            }
        }else{
            printf("Invalid symbol %d", input[i]);
            return -1;
        }
    }
   return 1;
    
}
int mainMatchParanthesis(int argc, char** argv) {
    char *inp = "[()]{}{[()()]()}"; 
    printf("\n paranthesis ouput:%d",checkParanthesisMatch(inp));
    return (EXIT_SUCCESS);
}


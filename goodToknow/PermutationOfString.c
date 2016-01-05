/* 
 * File:   PermutationOfString.c
 * Author: kurnagar
 *
 * Created on June 12, 2014, 3:05 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int findStringLength(char* str){
    int count = 0;
    int i = 0;
    for(i ; str[i] != '\0';i++){
        count++;
    }
    return count;
}
void swap(char* str,int ptr1,int ptr2){
    if(str == NULL){
        printf("\n nothing to swap");
        return NULL;
    }
    char temp = str[ptr1];
    str[ptr1] = str[ptr2];
    str[ptr2] = temp;
    //return str;
}

void permute(char* str, int i, int n) {
    int j;

    if (i == n) {
        printf("\n %s", str);
    } else {
        //for (i; i < n; i++) {

            for (j = i; j < n; j++) {
                swap(str, i, j);
                permute(str, i + 1, n);
                swap(str, i, j);
            }
        //}

    }

}
int mainPermutations(int argc, char** argv) {
    
    char input[] = "ABC";
    permute(input,0,3);

    return (EXIT_SUCCESS);
}


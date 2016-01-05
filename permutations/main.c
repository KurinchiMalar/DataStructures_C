/* 
 * File:   main.c
 * Author: kurnagar
 *
 * Created on March 28, 2014, 4:10 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void swap(char* x, char* y){
    char temp;
    temp = *x;
    *x   = *y;
    *y   = temp;
}
//i --> start index
//n --> end index
void permute(char* a,int i,int n){
    if(i == n){
        printf("\n%s",a);
    }else{
        int j = i;
        for( ; j <= n ; j++){
            printf("\n---------------------------");
            printf("\nBefore SWAP(%c,%c): %s",*(a+i),*(a+j),a);
            swap(a+i,a+j);
            printf("\nAfter SWAP(%c,%c): %s",*(a+i),*(a+j),a);
            permute(a,i+1,n);
            //swap(a+i,a+j);
        }
       
    }
    
}
int main(int argc, char** argv) {
    char a[] = "ABC";  
    permute(a, 0, 2);
    getchar();
    return (EXIT_SUCCESS);
}


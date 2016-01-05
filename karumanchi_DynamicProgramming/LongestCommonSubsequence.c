/* 
 * File:   LongestCommonSubsequence.c
 * Author: kurnagar
 *
 * Created on July 2, 2014, 12:24 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int max(int x,int y){
    return x > y ?x:y; 
}
int LCS(char* X,char* Y,int m, int n,int* LCSptr){
    int LCS[m+1][n+1];
    int i = 0;
     int j = 0;
/*
    for( i ; i <= m ; i++){
        LCS[i][0] = 0;
    }
    
    int j = 0;
    for(j ; j <= n; j++){
        LCS[0][j] = 0;
    }
    
*/
/*
        for(i = 1; i <= m; i++){
            for(j = 1; j <= n ; j++){
                if(X[i] == Y[j]){
                    LCS[i][j] = 1 + LCS[i-1][j-1];
                }else{
                    LCS[i][j] = max(LCS[i-1][j] ,LCS[i][j-1]);
                }
            }
        }
     */
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;

            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }
    
    
    for(i= 0 ; i <= m; i++){
        for(j= 0 ;j <= n; j++){
            printf("%d ",LCS[i][j]);
        }
        printf("\n");
    }
     *LCSptr = LCS;
    return LCS[m][n];
}

void printLCS(char* X,char* Y,int m, int n){
    
    int i = 0;
    int j = 0;
    
    int LCS[m+1][n+1];
    
     for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;

            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }
    
    //LCS[m][n] --> contains the desired result
    
    int lcsResult = LCS[m][n];
    
    i = m;
    j = n;
    char result[lcsResult+1]; // including \0
   // char* r = result;
    
    while( i >=0 && j >= 0){
         if(X[i-1] == Y[j-1]){ // should be added to result
                result[lcsResult] = X[i-1];
                lcsResult--;
            }else{
                if(max(LCS[i-1][j],LCS[i][j-1]) == LCS[i-1][j] ){
                    i = i-1;
                }else{
                    j  = j-1;
                }
            }
    }
  
    result[LCS[m][n]+1]= '\0';
    i = 0;
    for(i; result[i] != '\0'; i++){
        printf("%c",result[i]);
    }
}
int mainLCS(int argc, char** argv) {

    char* str1 = "ABA";
    char* str2 = "ACBA";
    char* str3 = "ABACEB";
    char* str4 = "ADBAVCEB";
/*
    printf("\n LCS(%s,%s) is : %d",str3,str4,LCS(str3,str4,6,8));
    printf("\n");
    printf("\n LCS(%s,%s) is : %d",str1,str2,LCS(str1,str2,3,4));
*/
    //printLCS(str1,str2,3,4);
    printLCS(str3,str4,6,8);
    return (EXIT_SUCCESS);
}


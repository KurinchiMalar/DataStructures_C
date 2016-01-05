/* 
 * File:   maxBenifitOfShares.c
 * Author: kurnagar
 *
 * Created on June 5, 2014, 9:18 AM
 */

#include <stdio.h>
#include <stdlib.h>

//http://www.careercup.com/question?id=22491681
/*
 * 
 */
int getMax(int param1, int param2){
    return (param1 > param2)?param1:param2;
}
int getMin(int param1, int param2){
    return (param1 < param2)?param1:param2;
}
// maxbenefit = bought at least price and sold at higher price. provided bought before selling.
int getMaxBenefit(int* input){
    
    int maxBenefit = INT32_MIN;
    int minVal = INT32_MAX;
  
    int i = 0;
    for(i ; input[i]!=0000;i++){
        printf("\n maxBenefit is : %d",maxBenefit);
        maxBenefit = getMax(maxBenefit,input[i]-minVal);
        minVal = getMin(minVal,input[i]);
    }
        
    return maxBenefit;
}
int mainShares(int argc, char** argv) {
    int shares[11] = {5,1,4,6,7,8,4,3,7,9,0000};
    
    printf("\n maxBenefit is : %d",getMaxBenefit(shares));
    
/*
    int _shares[] = {5,1,4,6,7,8,4,3,7,9,0000};
    int *shares = _shares;
 
    printf("\n maxBenefit is : %d",getMaxBenefit(shares));
*/
    return (EXIT_SUCCESS);
}


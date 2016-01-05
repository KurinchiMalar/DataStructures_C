/* 
 * File:   main.c
 * Author: kurnagar
 *
 * Created on November 9, 2013, 12:01 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, ",");

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, ",");
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

/*
int find_max(int* inputar,int size){
    int max = *(inputar+0);
    int iter = 1;
    for(;iter < size; iter++){
        if(max < *(inputar+iter)){
            max = *(inputar + iter);
        }
    }
    return max;
}
*/
int* getPrimeNumberSieve(int range){
    int min_prime = 2;
    int* sieve = (int*)malloc(sizeof(int)*range);
   // int sieve[range];
    int index;
    for(index = 0 ; index < range; index++){
        sieve[index] = 1;
    }
    while(min_prime < range ){
        if((min_prime * min_prime) > range){
            break;
        }
        int mul = 1;
        int i = min_prime;
        for(; i < range; i = min_prime*mul){
            if(i != min_prime && ((i % min_prime)==0) ){
                sieve[i] = 0;
            }
            mul++;
        }
        min_prime++;
    }
    sieve[0] = 0;
    sieve[1] = 0;
    return sieve;
}

int* getResultAfterLookUp(int start,int end,int* sieve){
    
    int* resultbuff = (int*)malloc(sizeof(sieve));
    int i_res = 0;
    while(start <= end){
        if(sieve[start] == 1){ //prime
            *(resultbuff + i_res) = start;
            i_res++;
        }
        start++;
    }
    *(resultbuff + i_res) = 0; // Adding delimiter for array
/*
    printf("\n***Result***");
    int j;
    for(j = 0 ;j <i_res;j++){
        printf("\n result[%d] = %d",j,*(resultbuff+j));
    }
*/
    return resultbuff;
}
int main(int argc, char** argv) {

    char input[] = "1,20";
    char** tokens;
    printf("input=[%s]\n\n", input);
    tokens = str_split(input, ',');
    int start_range = atoi(*(tokens+0));
    int end_range = atoi(*(tokens+1));
    printf("startRange : %d , endRange = %d\n",start_range,end_range);
    int integer_inp[] = {start_range,end_range};

    int* sieve = getPrimeNumberSieve(end_range+1);
/*
    printf("***Actual sieve for range = %d***",end_range);
    int iter;
    for(iter = 0 ;iter <end_range+1;iter++){
        printf("\n sieve[%d] = %d",iter,*(sieve+iter));
    }
*/
    int* result = getResultAfterLookUp(start_range,end_range,sieve);
    printf("\n***Result***");
    int i = 0;
    for(;*(result+i)!= 0;i++){
         printf("\n result[%d] = %d",i,*(result+i));
    }
    
    return (EXIT_SUCCESS);
}


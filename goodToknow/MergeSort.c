
#include <stdlib.h>

void printArray(int* ar,int n){
    int i = 0;
    for (i;i<n;i++){
        printf("%d",ar[i]);
    }
}
void merge(int *ar,int begin,int middle,int end){
    int* temp = (int*)malloc (sizeof(int)*(end+1));
    int begin_bkp = begin; 
    int temp_i = 0;
    int nextArrayStart = middle+1;
    while(begin <= middle && nextArrayStart <= end){
        if(ar[begin] < ar[nextArrayStart] ){
            temp[temp_i] = ar[begin];
            begin++;
            temp_i++;
        }else{ // ar[middle+1] is greater
            temp[temp_i] = ar[nextArrayStart];
            nextArrayStart++;
            temp_i++;
        }
    }
    if(begin > middle){ // second array is big and contents have to be copied
        while( nextArrayStart <= end){
            temp[temp_i]= ar[nextArrayStart];
            nextArrayStart++;
            temp_i++;
        }
    }
    if(nextArrayStart > end){ // first array is big and contents have to be copied
        while(begin <= middle){
            temp[temp_i] = ar[begin];
            temp_i++;
            begin++;
        }
    }
    //temp_i = 0000; // indicating terminal
    begin = begin_bkp;
    int i;
    for(i = 0 ; i < temp_i ; i++){
        ar[begin] = temp[i];
        begin++;
    }
    printf("\n");
    printArray(ar,end+1);
 
}
 
void mergeSort(int* ar,int begin,int end){
    if(begin == end || begin > end){
        return;
    }
    int middle = (begin+end)/2;
    mergeSort(ar,begin,middle);
    mergeSort(ar,middle+1,end);
    printf("\n calling merge(%d,%d,%d)",begin,middle,end);
    merge(ar,begin,middle,end);
}
int main(int argc, char** argv) {
 
    int a[6] = {3,5,6,1,4,2};
    int *ar = a;
    mergeSort(a,0,5);
    printf("\n Output");
    printArray(ar,6);
    return (EXIT_SUCCESS);
}
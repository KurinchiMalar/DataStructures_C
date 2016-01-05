/* 
 * File:   main.c
 * Author: kurnagar
 *
 * Created on June 17, 2014, 7:40 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct Heap{
    int* elements;
    int capacity;
    int size;
    int heap_type;
}Heap;

Heap* createHeap(int n){
    Heap* heap = (Heap*)malloc(sizeof(struct Heap));
    heap->elements = (int*)malloc(sizeof(int)*n);
    
    heap->size = 0;
    heap->capacity = n;
    heap->heap_type = 1;// maxHeap. 
    return heap;
}

int getParentIndex(Heap* h,int i){
    if(i > h->size || i <= 0){
        return -1;
    }
    return (i-1)/2;
}

int getLeftChild(Heap* h,int i){

    if(i >= h->size || i < 0){
        return -1;
    }
    
    return 2*i+1;
}

int getRightChild(Heap* h,int i){
     if(i >= h->size || i < 0){
        return -1;
    }

     return 2*i+2;
}

int getMaximum(Heap* h){
    if(h == NULL){
        return -1;
    }
    return h->elements[0];
}

//Heapifying element at index i
void swap(int *x,int *y){
    printf("\n swap(%d , %d)",*x,*y);
    int temp = *x;
    *x = *y;
    *y = temp;
}

void PercolateUp(Heap* h ,int i){
    
    if(i <= 0 || i > h->size){
        return;
    }
    int parent = getParentIndex(h,i);
    if(parent == -1){
        return;
    }
    printf("\n (%d ,parent=%d)",i,parent);
    int max = -1;
    if(h->elements[i] > h->elements[parent]){
        printf("\n swap (%d,%d)",i,parent);
        swap(&h->elements[i],&h->elements[parent]);
    }
    max = parent;
    printf("\n max is %d",max);
     
     PercolateUp(h,max);
    
}
void PercolateDown(Heap* h, int i){
    if(i < 0 || i >= h->size){
        return;
    }
    if( i > (h->size-1)/2){ //leaf
        return;
    }
    printf("\n ----------\n");
    printf("\n get leftRight of : %d",i);
    int left = getLeftChild(h,i);
    int right = getRightChild(h,i);
    
    if(left > h->size){
        left = -1;
    }
    if(right > h->size){
        right = -1;
    }
    printf("\n(left,right) : (%d,%d)",left,right);
    int max = -1;
    if (left != -1 && right != -1) {
        if (h->elements[left] >= h->elements[right]) {
            max = left;
        } else {
            max = right;
        }

    }else if(left == -1){
        max = right;
    }else{
        max = left;
    }
    
    
    if(h->elements[i] < h->elements[max]){
        swap(&h->elements[i],&h->elements[max]);
      //  max = i;
    }
    PercolateDown(h,max);
}

int ExtractMax(Heap* h){
    int returnValue = h->elements[0];
    
    h->elements[0] =  h->elements[h->size];
    h->size--;
    PercolateDown(h,0);
    return returnValue;
}

void buildHeap(Heap* h,int* ar,int n){ 
    if(h == NULL){
        return;
    }
    if(n > h->capacity){
        //
    }
 
    h->elements = ar;
     h->size = n - 1;
   

    int i = (h->size-1)/2;// last nonleaf
 
    
    for(i ; i >= 0 ; i--){
       
        PercolateDown(h,i);
    }
   
}
int deleteMax(Heap* h){
    if(h == NULL){
        return;
    }
    int temp = h->elements[0];
    h->elements[0] = h->elements[h->size];
    
    h->size--;
    PercolateDown(h,0);
    return temp;
}
void insert(Heap* h, int data){
    if(h->size == h->capacity){
        //
    }
    
    int i = h->size+1;
    h->elements[i] = data;
    h->size++;
    printf("\n printing in insert....\n");
    int j = 0;
    for(j ; j<= h->size; j++){
        printf("%d",h->elements[j]);
    }
    for(i ; i >= 0 ; i--){
        printf("\n PercolateUp(h,%d)",i);
        PercolateUp(h,i);
        printf("\n------------\n");
    }
}
void HeapSort(int* ar,int n){
    Heap *tempheap = createHeap(n);
    buildHeap(tempheap,ar,n);
    
    int sizebkp = tempheap->size;
    int i = n-1; // starting from last leaf
    for(i ;i >= 0; i--){
        printf("\n------------\n");
        printf("\n HeapSort : %d",i);
        swap(&tempheap->elements[0],&tempheap->elements[tempheap->size]);
        tempheap->size--;
        printf("\nfirst elem now: %d",tempheap->elements[0]);
        PercolateDown(tempheap,0);
    }
    tempheap->size = sizebkp;
}
int mainHeapBasics(int argc, char** argv) {
    Heap *h = createHeap(10);
    //int a[7] = {1,2,3,4,5,6,7};
    int a[6] = {3,6,1,2,4,5};
    int* ar = a;
     int j = 0;
    printf("\nBefore heapify : heap->size: %d\n",h->size);
    for(j ; j < 6; j++){
        printf("%d",h->elements[j]);
    }
    buildHeap(h,ar,6);
    printf("\nAfter heapify");
    j = 0;
    for(j ; j< 6; j++){
        printf("%d",h->elements[j]);
    }
    
    printf("\n first max: %d",ExtractMax(h));
    printf("\n second max: %d",ExtractMax(h));
/*
    insert(h,8);
    printf("\n After insert");
     j = 0;
    for(j ; j< 8; j++){
        printf("%d",h->elements[j]);
    }
     printf("\n deleted : %d",deleteMax(h));
     printf("\n After delete");
     j = 0;
    for(j ; j< h->size+1; j++){
        printf("%d",h->elements[j]);
    }
     HeapSort(ar,7);
     printf("\nAfter HeapSort...");
      j = 0;
    for(j ; j< h->size+1; j++){
        printf("%d",h->elements[j]);
    }
*/
    return (EXIT_SUCCESS);
}


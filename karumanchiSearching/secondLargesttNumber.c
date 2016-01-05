/* 
 * File:   secondLargestNumber.c
 * Author: kurnagar
 *
 * Created on June 21, 2014, 8:02 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct Heap{
    int* elements;
    int size;
    int capacity;
    int heaptype;
}Heap;

Heap* createHeap(int n){
    Heap* heap = (Heap*)malloc(sizeof(struct Heap));
    heap->elements = (int*)malloc(sizeof(int)*n);
    
    heap->size = 0;
    heap->capacity = n;
    heap->heaptype = 1;// maxHeap. 
    return heap;
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
void swap(int* x1, int* x2){
    int temp = *x1;
    *x1 = *x2;
    *x2 = temp;
}

void PercolateDown(Heap* h,int i) {
    if (h == NULL) {
        return;
    }
      int max = -1;
    if (i < 0 || i >= h->size) {
        return;
    }
    if (i > (h->size - 1) / 2) { //leaf
        return;
    }
  
    int left = getLeftChild(h,i);
    int right = getRightChild(h,i);
    
    if(left > h->size){
        left = -1;
    }
    if(right > h->size){
        right = -1;
    }
    if(left != -1 && right != -1){
        if(h->elements[left] >= h->elements[right]){
            max = left;
        }else{
            max = right;
        }
    }else if(left != -1){
        max = left;
    }else{
        max = right;
    }
    
    if(h->elements[i] < h->elements[max]){
        swap(&h->elements[i],&h->elements[max]);
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
int getMaximum(Heap* h){
    if(h == NULL){
        return -1;
    }
    return h->elements[0];
}



int getSecondLargestNumber(int* ar,int n){
    Heap* myheap = createHeap(n);
    buildHeap(myheap,ar,n);
  
    //int firstMax = getMaximum(myheap);
    printf("\n first max: %d",ExtractMax(myheap));
    return ExtractMax(myheap);
   

}
int mainSecondLargest(int argc, char** argv) {
    int a[6] = {3,6,1,2,4,5};
    int* ar = a;
    
     printf("\n second max: %d",getSecondLargestNumber(ar,6));
    return (EXIT_SUCCESS);
}


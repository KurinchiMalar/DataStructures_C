#include <stdio.h>
#include <stdlib.h>
typedef struct QueueStruct{
    
    int capacity;
    int size;
    int front;
    int rear;
    int* elements;
}Queue;

Queue* createQueue(int maxElements){
    Queue *newQueue = (Queue*)malloc(sizeof(struct QueueStruct*));
    if(newQueue != NULL){
    newQueue->elements = (int*)malloc((sizeof(int)*maxElements));
    
        newQueue->capacity = maxElements;
        newQueue->size = 0;
        newQueue->front = 0;
        newQueue->rear = -1;  
    }
    return newQueue;
}

int front(Queue* queue){
    if(queue->size == 0){
        printf("Queue is Empty. Cannot print front");
        return;
    }
    return(queue->elements[queue->front]);
}

int rear(Queue* queue){
    if(queue->size == 0){
        printf("Queue is Empty. Cannot print rear");
        return;
    }
    return(queue->elements[queue->rear]);
}

void EnQueue(Queue* queue,int data){
    if(queue->size == queue->capacity){
        printf("Queue is full. Cannot EnQueue");
        return;
    }
   
    queue->size = queue->size +1;
    queue->rear = queue->rear+1;
    queue->elements[queue->rear] = data;
   // printf("%d\n",queue->elements[queue->rear]);
     if(queue->rear == queue->capacity){
        queue->rear = 0;
    }
    
}

void deQueue(Queue* queue){
    if(queue->size == 0){
        printf("Queue is empty. Cannot DeQueue");
        return;
    }
    queue->size = queue->size-1;
    queue->front = queue->front + 1;
    if(queue->front == queue->capacity){
        queue->front = 0;
    }
}

void printQueue(Queue* queue){
    int count = 0;
    while(count <= queue->rear){
        printf("%d",queue->elements[count]);
        count++;
        
    }
}

int mainQueue(int argc, char** argv) {
    
    Queue *myqueue = createQueue(5);  
    EnQueue(myqueue,1);
    printf("%d\n",myqueue->elements[0]);
    EnQueue(myqueue,2);
    //printf("%d\n",front(myqueue));
    //printf("%d",rear(myqueue));
    //EnQueue(myqueue,3);
    //EnQueue(myqueue,4);
    //EnQueue(myqueue,5);
    //printQueue(myqueue);
    return (EXIT_SUCCESS);
}
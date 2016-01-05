/* 
 * File:   QueueInt.c
 * Author: kurnagar
 *
 * Created on June 10, 2014, 2:51 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct List{
    int data;
    struct List* link;
}Node;
Node* head = NULL;

typedef struct Queue{
    Node* front;
    Node* rear;
}queue;

queue* createQ(){
    queue* newQ =(queue*)malloc(sizeof(struct Queue*));
    newQ->front = NULL;
    newQ->rear = NULL;
}
Node* createNodeQ(int d){
    Node* newNode = (Node*)malloc(sizeof(struct List*));
    newNode->data = d;
    newNode->link = NULL;
    return newNode;
}
void EnQ(queue* queue,int d){
    if(head == NULL){
        head = createNodeQ(d);
        queue->front = head;
        queue->rear = head;
        return;
    }
    queue->rear->link = createNodeQ(d);
  //  queue->rear = queue->rear->link;
     printf("\nTesting...");
    printf("\n front: %d",queue->front->data);
     printf("\n rear: %d",queue->rear->data);
     if(queue->front->link == NULL){
         printf("\n front->link is null");
     }
     
    queue->rear = queue->rear->link;
    
   
   
}
int mainQueueInt(int argc, char** argv) {
    queue *myqueue = createQ();
    EnQ(myqueue,1);
    EnQ(myqueue,3);
    return (EXIT_SUCCESS);
}


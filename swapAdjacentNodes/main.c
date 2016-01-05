/* 
 * File:   main.c
 * Author: kurnagar
 *
 * Created on April 7, 2014, 4:37 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct LinkNode{
    int data;
    struct LinkNode* link;
}node;

node* createNode(int d){
    node* newNode = (node*)malloc(sizeof(struct LinkNode));
    if(newNode != NULL){
        newNode ->data = d;
        newNode ->link = NULL;
        return newNode;
    }else{
        printf("newNode creation failed!!");
        return NULL;
    }
}

void printNodes(node* head){
    while(head != NULL){
        printf("\nList is :%d",head->data,"->");
        head = head->link;
    }
}
node* swapAdjNodes(node* head){
    
    node* prev = NULL;
    node* curr = NULL;
    node* next = NULL;
    node* backup = NULL;
    
    prev = head;
    curr = prev ->link;
    head = curr; // for first step
    int isFirst = 0;
    while(curr !=NULL && curr->link !=NULL){
         if(isFirst == 0){
             isFirst = 1;
        }else{
             backup ->link = curr;
        }
        next = curr->link;
        curr->link = prev;
        if(next!=NULL){
            prev ->link = next ->link;
        }
        backup = prev;
        prev = next;
        curr = prev->link;
       
    }
    if(curr == NULL){
        backup->link = prev;
    }
    if(curr ->link == NULL){
        printf("cur->data: %d",curr->data);
        printf("prev->data: %d",prev->data);
        printf("backup->data: %d",backup->data);
        curr->link = prev;
        prev ->link = NULL;
        backup ->link = curr;
    }
    
    printNodes(head);
    
    return head;
}


int main(int argc, char** argv) {
    node* head = createNode(1);
    node* two = createNode(2);
    node* three = createNode(3);
    node* four = createNode(4);
    node* five = createNode(5);
    node* six = createNode(6);
   node* seven = createNode(7);
    head ->link = two;
    two ->link = three;
    three ->link = four;
    four ->link = five;
    five ->link = six;
    six ->link = seven;

    printNodes(head);
    printf("==========");
    node* result = swapAdjNodes(head);
    printf("=========");
    printNodes(result);
    return (EXIT_SUCCESS);
}


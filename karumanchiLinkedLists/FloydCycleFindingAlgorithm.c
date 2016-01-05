/* 
 * File:   FloydCycleFindingAlgorithm.c
 * Author: kurnagar
 *
 * Created on June 1, 2014, 5:14 PM
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


Node* getLoopNode(Node* head){
    Node* hare = head;
    Node* tort = head;
    while (hare != NULL && hare->link != NULL) {
        hare = hare->link->link;
        tort = tort->link;
        if (hare == tort) {
            break;
        }
    }
    tort = head;
    while(hare != tort){
        hare = hare->link;
        tort = tort ->link;
    }
    return hare;
}

Node* findMiddle(Node* head){
    if(head == NULL){
        printf("\nList is empty");
        return NULL;
    }
    Node* hare = head;
    Node* tort = head;
    
    while(hare->link != NULL && hare->link->link != NULL){
        hare = hare->link->link;
        tort = tort->link;
    }
    
/*
    if(hare->link == NULL){//list is odd
        
    }
    if(hare->link->link == NULL){//list is even.
        
    }
*/
    return tort;
}
int getLoopLength(Node* head){
    
    int loopLength = 0;
    Node* loopNode = getLoopNode(head);
   
    Node* hare = loopNode;
    Node* tort = loopNode;
   
    do{
        loopLength++;
        hare = hare->link;
        
    }while(hare != tort);
    return loopLength;
}

int getListLength(Node* head){
    int loopLength = getLoopLength(head);
    int lengthUptoLoopNode = 0;
    Node* loopNode = getLoopNode(head);
    Node* current = head;
    while(current != loopNode){
        lengthUptoLoopNode++;
        current = current->link;
    }
    return loopLength+lengthUptoLoopNode;
}

int isLoop(Node* head){
    Node* hare = head;
    Node* tort = head;
    
    while(hare != NULL && hare->link != NULL){
        hare = hare->link->link;
        tort = tort->link;
        if(hare == tort){
            printf("loop exists");
            return 1;
        }
        
    }
    return -1;
}
int mainFloyd(int argc, char** argv) {
    Node* one = createListNode(1);
    Node* two = createListNode(2);
    Node* three = createListNode(3);
    Node* four = createListNode(4);
    Node* five = createListNode(5);
    Node* six = createListNode(6);
    
    one->link =two;
   // two->link = three;
    //three->link = four;
    //four->link = five;
    //five->link = six;
    //six->link = two;
    traverseList(one);
   // printf("Loop exist or not:%d\n",isLoop(one));
     //printf("Loop Node is :%d\n",getLoopNode(one)->data);
    // printf("Loop Length is %d\n",getLoopLength(one));
     //printf("List Length is %d\n",getListLength(one));
    printf("\n Middle node is : %d\n",findMiddle(one)->data);
    printf("\n");
    return (EXIT_SUCCESS);
}


/* 
 * File:   SplitCircularList.c
 * Author: kurnagar
 *
 * Created on June 3, 2014, 10:28 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct CircularList{
    int data;
    struct CircularList* link;
}CNode;
CNode* L1head=NULL;
CNode* L2head= NULL;
void SplitCircularList(CNode* head){
    if(head == NULL){
        printf("List is empty");
        return head;
    }
    
    CNode* tort = head;
    CNode* hare = head;
    
    while(hare->link != head && hare->link->link != head){
        hare = hare->link->link;
        tort = tort->link;
    }
    
    if(hare->link == head){ // odd list
        L1head = head;
        L2head = tort->link;
        
        tort->link = L1head;
        hare->link = L2head;
    }else if(hare->link->link == head){ //even list
        L1head = head;
        L2head = tort->link;
        
        tort->link = L1head;
        hare->link->link = L2head;
        
    }
}

int mainSplitCircularList(int argc, char** argv) {
     CNode* one = createCircularListNode(1);
    CNode* two = createCircularListNode(2);
    CNode* three = createCircularListNode(3);
    CNode* four = createCircularListNode(4);
    CNode* five = createCircularListNode(5);
    //CNode* six = createCircularListNode(6);
    
    one->link =two;
    two->link = three;
    three->link = four;
    four->link = five;
    five->link = one;
    //six->link = one; // making it Circular
    traverseCList(one);
    printf("\n");
    SplitCircularList(one);
    traverseCList(L1head);
    printf("\n");
    traverseCList(L2head);
    return (EXIT_SUCCESS);
}


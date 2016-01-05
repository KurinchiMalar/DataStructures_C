/* 
 * File:   MergePointOfLists.c
 * Author: kurnagar
 *
 * Created on June 1, 2014, 8:30 PM
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

Node* findMergePoint(Node* head1,Node* head2){
    Node* L1 = head1;
    Node* L2 = head2;
    
    while(L1 != NULL && L2 != NULL){
        L1 = L1->link;
        L2 = L2->link;
    }
    
    if(L1 == NULL){ //L1 is the shorter list
        L1 = head2;
        while(L2 != NULL){
            L1 = L1->link;
            L2 = L2->link;
        }
        L2 = head1;
        
        while(L1 != NULL && L2 != NULL){
            if(L1 == L2){
                printf("\nfound mergepoint");
                return L1;
            }
            L1 = L1->link;
            L2 = L2->link;
        }
        
    }else if(L2 == NULL){ //L2 is the shorter list
        L2 = head1;
        while(L1 != NULL){
            L1 = L1->link;
            L2 = L2->link;
        }
        L1 = head2;
        
        while(L1 != NULL && L2 != NULL ){
             if(L1 == L2){
                printf("\nfound mergepoint");
                return L1;
            }
            L1 = L1->link;
            L2 = L2->link;
        }
        
    }
    printf("\nNo merge point");
    return NULL;
}
int mainMergePoint(int argc, char** argv) {
    Node* L1one = createListNode(1);
    Node* L1two = createListNode(2);
    Node* L1three = createListNode(3);
    Node* L1four = createListNode(4);
    
    Node* L2five = createListNode(5);
    Node* L2six = createListNode(6);
    Node* L2seven = createListNode(7);
    Node* L2eight = createListNode(8);
    Node* L2nine = createListNode(9);
    
/*
    L1one->link =L1two;
    L1two->link = L1three;
    L1three->link = L1four;
*/
    L2five->link = L1one;
/*
    L2five->link = L2six;
    L2six->link = L2seven;
    L2seven->link = L2eight;
    L2eight->link = L2nine;
    //L2nine->link = L1two;
*/
 
    traverseList(L1one);
    printf("\n");
    traverseList(L2five);
    Node* mergepoint = findMergePoint(L1one,L2five);
    if(mergepoint){
        printf("\nMergeNode is : %d",mergepoint->data);
    }
    //printf("\nMergeNode is : %d",findMergePoint(L1one,L2five)->data);

    return (EXIT_SUCCESS);
}


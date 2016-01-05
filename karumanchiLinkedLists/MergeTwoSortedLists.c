/* 
 * File:   MergeTwoSortedLists.c
 * Author: kurnagar
 *
 * Created on June 3, 2014, 7:40 AM
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

Node* mergeTwoSortedLists(Node* head1,Node* head2){
    if(head1 == NULL){
        printf("\nL2 is null");
        return head1;
    }
    if(head2 == NULL){
        printf("\nL1 is null");
        return head2;
    }
    Node* resultHead = NULL;
    Node* p = NULL;
    Node* q = NULL;
    Node* r = NULL;
    // (head1 and head2 ) != NULL
    //initial placement
    if(head1->data <= head2->data){
        resultHead = head1;
        p = head1;
        r = head2;
        
    }else{
        resultHead = head2;
        p = head2;
        r = head1;
    }
    q = p->link;
    while(q != NULL && r != NULL){
        if(q->data >= r->data){
            p->link = r;
            p = r;
            //if(r){
                r = r->link;
            //}
            
        }else{
            p->link = q;
            p = q;
            q = q->link;
        }
        
    }
    
    if(r == NULL && q != NULL){
        p->link = q;
        return resultHead;
    }else{ // r!=NULL  q==NULL
        p->link = r;
        return resultHead;
        
    }
}
int mainMergeTwoSorted(int argc, char** argv) {
    Node* L1one = createListNode(1);
    Node* L1two = createListNode(4);
    Node* L1three = createListNode(5);
    Node* L1four = createListNode(8);
    
    Node* L2five = createListNode(2);
    Node* L2six = createListNode(6);
    Node* L2seven = createListNode(9);
   // Node* L2eight = createListNode(8);
    //Node* L2nine = createListNode(9);
    

    //L1one->link =L1two;
   // L1two->link = L1three;
    //L1three->link = L1four;

   // L2five->link = L2six;
    //L2six->link = L2seven;
   // L2seven->link = L2eight;
    //L2eight->link = L2nine;

 
    traverseList(L1one);
    printf("\n");
    traverseList(L2five);
    printf("\n");
    traverseList(mergeTwoSortedLists(L1one,L2five));

    return (EXIT_SUCCESS);
}


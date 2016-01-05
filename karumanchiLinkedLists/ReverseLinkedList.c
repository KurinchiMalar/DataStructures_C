/* 
 * File:   ReverseLinkedList.c
 * Author: kurnagar
 *
 * Created on June 1, 2014, 8:02 PM
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

Node* reverseListRecursive(Node* head){
    if(head == NULL){
        return NULL;
    }
    if(head->link == NULL){
        return head;
    }
    
    Node* secondaryNode = head->link;
    
    //unlink the header
    head->link = NULL;
    
    //recursivecall
    Node* revNode = reverseListRecursive(secondaryNode);
    
    secondaryNode->link = head;
    
    return revNode;
}

Node* reverseListIterative(Node* head){
    Node* p = NULL;
    Node* q = head;
    Node* r = head->link;
    while(q != NULL){
        q->link = p;
        p = q;
        q = r;
        if(r){
            r = r->link;
        }
        
    }
    head = p;
    return head;
}
int mainReverse(int argc, char** argv) {
      Node* one = createListNode(1);
    Node* two = createListNode(2);
    Node* three = createListNode(3);
    Node* four = createListNode(4);
    Node* five = createListNode(5);
    Node* six = createListNode(6);
    
/*
    one->link =two;

    two->link = three;
    three->link = four;
    four->link = five;
    five->link = six;
*/
    //six->link = two;
    traverseList(one);
    printf("\n");
   // traverseList(reverseListIterative(one));
    traverseList(reverseListRecursive(one));
    return (EXIT_SUCCESS);
}


/* 
 * File:   Palindrome.c
 * Author: kurnagar
 *
 * Created on June 4, 2014, 7:44 AM
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

int paliComparator(Node* p,Node* q,Node* r,Node* hare,Node* headOfTempRevList,Node* middle){
    while(q != NULL && hare != NULL){
            if(q->data != hare->data){
                // not palindrome
                //reorder the list
                while(q != NULL){
                    q->link = p;
                    p = q;
                    q = r;
                    if(r){
                        r = r->link;
                    }
                }
                headOfTempRevList->link = middle;
                return -1;
            } else if (q->data == hare->data) {
                q->link = p;
                p = q;
                q = r;
                if (r) {
                    r = r->link;
                }
                hare = hare->link;
            }
            headOfTempRevList->link = middle;
            return 1;
        }
}
int isPalindrome(Node* head){
    Node* hare = head;
    Node* p = NULL, *r= NULL;
    Node* q = head; // lets use this as tort also.
    r = q->link;
    
    if(head == NULL){
        return NULL;
    }
    
    if(head->link == NULL){
        return 1;
    }
    while(hare != NULL && hare->link != NULL){
        hare = hare->link->link;
        q->link = p;
        p = q;
        q = r;
        if(r){
            r = r->link;
        }
    }
    
    if(hare != NULL && hare->link == NULL){// odd list
        printf("\n odd list");
        // q will be pointing to middle node.
        // p will be pointing to head of reversed list.
        // mark "hare" to point to node next to middle node--> second half of list to be compared with.
        Node* middle = q;
        printf("\n middle node is :%d",middle->data);
        hare = q->link;
        Node* headOfTempRevList = p;
        printf("\n headOfTempRevList is :%d",headOfTempRevList->data);
        printf("\n");
        traverseList(headOfTempRevList);
        printf("\n");
        q = p;
        p = NULL;
        r = q->link;
        return paliComparator(p,q,r,hare,headOfTempRevList,middle);        
    }else{ // even list
          printf("\n even list");
        // q will be pointing to middle node.
        // p will be pointing to head of reversed list.
        // mark "hare" to point to middle node--> second half of list to be compared with.
        Node* middle = q;
        printf("\n middle node is :%d",middle->data);
        hare = q;
        Node* headOfTempRevList = p;
        printf("\n headOfTempRevList is :%d",headOfTempRevList->data);
        printf("\n");
        traverseList(headOfTempRevList);
        printf("\n");
        q = p;
        p = NULL;
        r = q->link;
        return paliComparator(p,q,r,hare,headOfTempRevList,middle);
        
    }
}



int mainPali(int argc, char** argv) {
    Node* one = createListNode(1);
    Node* two = createListNode(2);
    Node* three = createListNode(3);
    Node* four = createListNode(4);
    Node* five = createListNode(3);
    Node* six = createListNode(2);
    Node* seven = createListNode(1);
    one->link =two;

    two->link = three;
    three->link = four;
    four->link = five;
    five->link = six;
    six->link = seven;
    traverseList(one);
    printf("\n isPalindrome : %d\n",isPalindrome(one));
    return (EXIT_SUCCESS);
}


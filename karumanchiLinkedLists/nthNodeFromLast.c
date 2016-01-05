/* 
 * File:   nthNodeFromLast.c
 * Author: kurnagar
 *
 * Created on June 1, 2014, 4:02 PM
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
/**
 * 
 * @param head
 * @return Node*
 * 
 * logic --> 1) Move n nodes using ptr1.
 *           2) Start ptr1 from head and move until ptr1 == NULL.
 * 
 *           total# of nodes - n ==> number of nodes from head to reach desired node.
 */
Node* nthNodeFromLast(Node* head, int n){
    if(head == NULL){
        printf("List is empty");
        return NULL;
    }
    if(n <= 0){
        printf("Invalid postion");
        return NULL;
    }
    if(n > listLength(head)){
        printf("n > listLength --> Invalid");
        return NULL;
    }
    Node* ptr1 = head;
    Node* ptr2 = head;
    while(n--){
        ptr1 = ptr1->link;
    }
    while(ptr1 != NULL){
        ptr2 = ptr2->link;
        ptr1 = ptr1->link;
    }
    return ptr2;
}
int mainNthNodeFromLast(int argc, char** argv) {
     Node* one = createListNode(1);
    Node* two = createListNode(2);
    Node* three = createListNode(3);
    Node* four = createListNode(4);
    Node* five = createListNode(5);
    Node* six = createListNode(6);
    
    one->link =two;
    two->link = three;
    three->link = four;
    four->link = five;
    five->link = six;
    traverseList(one);
    
    Node* result = nthNodeFromLast(one,6);
    if(result){
        printf("\n%d",result->data);
    }
    //printf("\n%d",nthNodeFromLast(one,7)->data);
    return (EXIT_SUCCESS);
}


/* 
 * File:   test.c
 * Author: kurnagar
 *
 * Created on June 8, 2014, 6:52 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct node
{
int val;
struct node *next;
}Node;

Node* createListNode(int data){
    Node* newNode =(Node*)malloc(sizeof(struct node*));
    if(NULL != newNode){
        newNode->val = data;
        newNode->next = NULL;
    }
    return newNode;
}
struct node* sortList(struct node *head){

    if(head == NULL){
        return NULL;
    }
    struct node* L1head = head;
    struct node* L2head = L1head->next;
    while((L2head->val >= L1head->val) && (L2head != NULL)){
        L2head = L2head->next;
        L1head = L1head->next;
    }
    
    if(L2head != NULL){
        L1head->next = NULL;
    }
    L1head = head;
    printf("\n L1head: %d",L1head->val);
    printf("\n L2head: %d",L2head->val);
    struct node* move1 = NULL;
    struct node* move2 = NULL;
    struct node* prev = NULL;
    
    if(L1head->val <= L2head->val){
        prev = L1head;
        move1 = L1head->next;
        move2 = L2head->next;
    }
/*
    }else{
        L1head = L2head;
        prev = 
    }
*/
    while(L2head != NULL && move1 != NULL){
       if(L2head->val <= move1->val){
           prev->next = L2head;
           prev = L2head;
           L2head = L2head->next;
           if(move2){
                move2 = move2->next;
           }
          
       }else{
           prev->next = move1;
           prev = move1;
           if(move1){
               move1 = move1->next;
           }
       }
    }
    if(L2head == NULL && move1 != NULL){
        prev->next = move1;
        return L1head;
    }
    if(L2head != NULL && move1 == NULL){
        prev->next = L2head;
        return L1head;
    }
    return L1head;
}
void traverseListMY(struct node* head){
    if(head == NULL){
        printf("Empty list");
    }
    while(head!=NULL){
        printf("%d",head->val);
        head=head->next;
    }
}
int mainTested(int argc, char** argv) {
    Node* one = createListNode(1);
    Node* two = createListNode(2);
    Node* three = createListNode(3);
    Node* four = createListNode(4);
    Node* five = createListNode(5);
    Node* one1 = createListNode(1);
    Node* two1 = createListNode(2);
    //Node* six = createListNode(6);
    
    one->next =two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = one1;
    one1->next = two1;
   // traverseListMY(one);
    printf("\n");
    traverseListMY(sortList(one));//sortList(one);
    
    return (EXIT_SUCCESS);
}


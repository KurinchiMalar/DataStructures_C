/* 
 * File:   main.c
 * Author: kurnagar
 *
 * Created on May 31, 2014, 7:33 PM
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

Node* createListNode(int data){
    Node* newNode =(Node*)malloc(sizeof(struct List*));
    if(NULL != newNode){
        newNode->data = data;
        newNode->link = NULL;
    }
    return newNode;
}
Node* delete(Node* head,int position){
    if(head == NULL){
        return NULL;
    }
    Node* current = head;
    Node* prev = current;
    Node* lastbutone = NULL;
    if(position == 1){
        head = current->link;
        free(current);
        return head;
    }
    int count = 1;
    current = current->link;
    while(current != NULL){
        count++;
        if(count == position){
            prev->link = current->link;
            free(current);
            return head;
        }
        lastbutone = prev;
        prev = current;
        current = current->link;
    }
    if(current == NULL && count < position){//delete last node
        if(position >= count+1){
            printf("Invalid position");
            return head;
        }
        printf("Count:%d\n",count);
        lastbutone->link = NULL;
        free(prev);
        return head;
    }
}
Node* insert(Node* head,int data,int position){
    if(head==NULL){
        return NULL;
    }
    Node* current = head;
    Node* prev = NULL;
    Node* newNode = NULL;
    if(position == 1){
        newNode = createListNode(data);
        newNode->link = current;
        head = newNode;
        return head;
    }
    int count = 1;
    while(current!=NULL){
        count++;
        if(count == position){// have to be inserted here
            newNode = createListNode(data);
            newNode->link = current->link;
            current->link = newNode;
            return head;
        }
        prev=current;
        current=current->link;
    }
    if(current == NULL && count < position){// have to insert at end
        
        newNode = createListNode(data);
        prev->link = newNode;
        return head;
    }
}
Node* deleteList(Node* head){
    if(head == NULL){
        printf("List is already NULL");
        return NULL;
    }
    Node* current = head;
    while(current != NULL){
       // current = head;
        current = current->link;
        free(head);
        head = current;
    }
    return head;
}
int listLength(Node* head){
    Node* current = head;
    int count = 0;
    if(current == NULL){
        printf("Empty list");
    }
    while(current!=NULL){
        count++;
        current=current->link;
    }
    return count;
}
void displayListFromEnd(Node* head){
    if(head == NULL){
        return NULL;
    }
    displayListFromEnd(head->link);
    printf("%d",head->data);
    
}
void traverseList(Node* head){
    if(head == NULL){
        printf("Empty list");
    }
    while(head!=NULL){
        printf("%d",head->data);
        head=head->link;
    }
}
int mainSingle(int argc, char** argv) {
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
    printf("\n");
    displayListFromEnd(one);
/*
    //traverseList(insert(one,7,1));
    //traverseList(delete(one,1));
   // traverseList(delete(one,2));
    printf("\n");
    //traverseList(insert(one,7,8));
    traverseList(delete(one,7));
    traverseList(deleteList(one));
*/
    return (EXIT_SUCCESS);
}


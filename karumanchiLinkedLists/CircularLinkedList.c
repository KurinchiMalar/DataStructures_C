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
typedef struct CircularList{
    int data;
    struct CircularList* link;
}CNode;

CNode* createCircularListNode(int data){
    CNode* newNode =(CNode*)malloc(sizeof(struct CircularList*));
    if(NULL != newNode){
        newNode->data = data;
        newNode->link = newNode;
    }
    return newNode;
}
CNode* deleteCNode(CNode* head,int position){
    if(head == NULL){
        return NULL;
    }
    CNode* current= head;
    CNode* lastbutone = NULL;
    CNode* nodebeforetail = NULL;
    int count = 0;
    if (position == 1) {
        while (current->link != head) {
            current = current->link;
        }
        //now current will be pointing to last node.
        current->link = head->link;
        current = head;
        head = head->link;
        free(current);
        return head;
    }
    count = 1;
    lastbutone = current;
    current = head->link;
    do{
        if(current->link->link == head){
            nodebeforetail = current;
        }
        count++;
        if(count == position){ //delete middle node
            lastbutone->link = current->link;
            free(current);
            return head;
        }
        lastbutone = current;
        current = current->link;
        
    }while((current != head));
    
    // now lastbutone is pointing to lastnode
    if(position < count+1){
        nodebeforetail->link = lastbutone->link;
        free(lastbutone);
        return head;
    }else{
        printf("invalid position");
        return head;
    }
}
CNode* insertCNode(CNode* head,int data,int position){
    if(head == NULL){
        printf("List is NULL");
        return NULL;
    }
    CNode* newNode = NULL;
    CNode* current = head;
    CNode* lastbutone = NULL;
    int count = 0;
    if(position == 1){ // insert at beginning
        newNode = createCircularListNode(data);
        newNode->link = head;
        while(current->link != head){
            current = current->link;
        }
        //after loop current = lastnode;
        head = newNode;
        current->link=head;
        return head;
    }
    lastbutone = head;
    current = head->link;
    count = 1;
    do{
        count++;
        if(count == position){ // insert at middle
            newNode = createCircularListNode(data);
            lastbutone->link = newNode;
            newNode->link = current;
            return head;
        }
        lastbutone = current;
        current = current->link;
    }while(current!=head);
    //now lastbutone is the last node
    printf("\nCount is :%d\n",count);
    if(position <= count+1){ //plug in as lastnode
       newNode = createCircularListNode(data);
       newNode->link = head;
       lastbutone->link = newNode;
       return head;
    }else{
        printf("invalid position");
        return head;
    }
}
CNode* deleteCList(CNode* head){
    if(head == NULL){
        printf("List is already NULL");
        return NULL;
    }
    CNode* current = head;
    
    while(current->link != head){
         current = current->link;
    }
    current->link = NULL; //make it singly linked.
    return deleteList(head);
    //return head;
}

void traverseCList(CNode* head){
    CNode* current = head;
    if(head == NULL){
        printf("Empty list");
    }
    int count = 0;
    do{
        printf("%d",current->data);
        count++;
        current=current->link;
    }while(current != head);
    printf("\nNumber of nodes:%d",count);
}
int mainCircular(int argc, char** argv) {
    CNode* one = createCircularListNode(1);
    CNode* two = createCircularListNode(2);
    CNode* three = createCircularListNode(3);
    CNode* four = createCircularListNode(4);
    CNode* five = createCircularListNode(5);
    CNode* six = createCircularListNode(6);
    
    one->link =two;
    two->link = three;
    three->link = four;
    four->link = five;
    five->link = six;
    six->link = one; // making it Circular
    traverseCList(one);
    printf("\n");
    //traverseCList(insertCNode(one,9,8));
    //traverseCList(deleteCNode(one,7));
    //traverseList(insert(one,7,1));
    //traverseList(delete(one,1));
   // traverseList(delete(one,2));
   // printf("\n");
    //traverseList(insert(one,7,8));
    //traverseList(delete(one,7));
    traverseCList(deleteCList(one));
    
    return (EXIT_SUCCESS);
}



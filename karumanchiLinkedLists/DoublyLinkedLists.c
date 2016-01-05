
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
typedef struct DoublyLinkedList{
    int data;
    struct DoublyLinkedList* prev;
    struct DoublyLinkedList* next;
}DNode;

DNode* createDoublyListNode(int data){
    DNode* newNode =(DNode*)malloc(sizeof(struct DoublyLinkedList*));
    if(NULL != newNode){
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    return newNode;
}
DNode* deleteDNode(DNode* head,int position){
    if(head == NULL){
        return NULL;
    }
    DNode* current = head;;
    if(position == 1){
        DNode* temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        return head;
    }
    int count = 1;
    current = current->next;
    while(current->next != NULL){
        count++;
        if(count == position){
            DNode* temp = current->next;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            return head;
        }
        current = current->next;
    }
    if(current->next == NULL ){//lastnode
        printf("\ncurrent:%d",current->data);
        if(position > count+1){
            printf("Invalid positon");
            return head;
        }
        current->prev->next= NULL;
        free(current);
        return head;
    }
}
DNode* insertDNode(DNode* head,int data,int position){
    if(head==NULL){
        return NULL;
    }
    DNode* newNode = NULL;
    DNode* current = head;
    DNode* lastbutone = current;
    if(position == 1){
        newNode = createDoublyListNode(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }
    int count = 1;
    current=current->next;
    while(current != NULL){
        count++;
        if(count == position){
            newNode = createDoublyListNode(data);
            newNode->prev=current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;
            
            return head;
        }
        lastbutone = current;
        current = current->next;
    }
    if(current == NULL && count < position){
        printf("Count is %d\n",count);
        if(count+1 < position){
            printf("Invalid position ");
            return head;
        }
        newNode = createDoublyListNode(data);
        lastbutone->next = newNode;
        newNode->prev = lastbutone;
        return head;
    }

}
DNode* deleteDoublyList(DNode* head){
    if(head == NULL){
        printf("List is already NULL");
        return NULL;
    }
    DNode* current = head;
    while(current != NULL){
       // current = head;
        current = current->next;
        if(current == NULL){
            return NULL;
        }
        current->prev = NULL;
        head->next = NULL;
        free(head);
        head = current;
    }
    return head;
}
void traverseDoublyList(DNode* head){
    if(head == NULL){
        printf("Empty list");
    }
    while(head!=NULL){
        printf("%d",head->data);
        head=head->next;
    }
}
int mainDouble(int argc, char** argv) {
    DNode* one = createDoublyListNode(1);
    DNode* two = createDoublyListNode(2);
    DNode* three = createDoublyListNode(3);
    DNode* four = createDoublyListNode(4);
    DNode* five = createDoublyListNode(5);
    DNode* six = createDoublyListNode(6);
    
    one->next =two;
    
    two->prev = one;
    two->next = three;
    
    three->prev = two;
    three->next = four;
    
    four->prev = three;
    four->next = five;
    
    five->prev = four;
    five->next = six;
    
    six->prev = five;
    six->next = NULL;
    traverseDoublyList(one);
    printf("\n");
    //traverseDoublyList(deleteDNode(one,6));
    //traverseDoublyList(insertDNode(one,7,1));
    //printf("\n");
    //traverseDoublyList(insertDNode(one,9,3));
    //printf("\n");
    //traverseDoublyList(insertDNode(one,9,6));
 
    //traverseDoublyList(insertDNode(one,7,7));
    //traverseDoublyList(deleteDNode(one,7));
/*    //traverseList(delete(one,1));
   // traverseList(delete(one,2));
    printf("\n");
    //traverseList(insert(one,7,8));
    traverseList(delete(one,7));
    traverseList(deleteList(one));
*/
    traverseList(deleteDoublyList(one));
    return (EXIT_SUCCESS);
}


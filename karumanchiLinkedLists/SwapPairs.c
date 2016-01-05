/* 
 * File:   SwapPairs.cpp
 * Author: kurnagar
 *
 * Created on June 3, 2014, 9:14 AM
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

//http://crackinterviewtoday.wordpress.com/2010/03/28/k-reverse-linked-list/
Node* swapNodesByBlock(Node* head, int k){
      Node* nextNode = head;
        Node* startNode = NULL;
        Node* endNode = NULL;
        head = NULL;
 
        while (nextNode != NULL)
        {
            //  startNode and endNode points to nextNode
            startNode = nextNode;
            endNode = nextNode;
 
            //  Move endNode pointing towards node after k elements from startNode
            int i = 0;
            for (i = 1; i < k; i++)
            {
                endNode = endNode->link;
 
                if (endNode == NULL)
                {
                    break;
                }
            }
 
            // If endNode is not null, then reverse the list starting from startNode to endNode
            // eles if endNode is null, then there is nothing to reverse
 
            if (endNode != NULL)
            {
                // Save the node next to endNode
                nextNode = endNode->link;
 
                //  Unlink the endNode
                endNode->link = NULL;
 
                // Reverse the list starting from startNode
                
                startNode = reverseListIterative(startNode);
            }
            else
            {
                nextNode = NULL;
            }
 
            //  Point headerNode to the startNode of the first iteration.
            //  If the headerNode is set, append the list startNode to the headerNode
            if (head == NULL)
            {
                head = startNode;
            }
            else
            {
                //loop to get the last node of list
                //SingleLinkedList.getLastNode(headerNode).next = startNode;
                Node* temp = head;
                while(temp->link != NULL){
                    temp = temp->link;
                }
                temp->link = startNode;
                
            }
        }
 
        return head;
    
    

}
/*
//http://stackoverflow.com/questions/7138128/reverse-every-k-nodes-of-a-linked-list

Node* recrev(Node* head, int c) {
    Node* root = head, *temp, *final, *prev = NULL;
    int count = 0;
    while (root != NULL && count < c) {
        count++;
        temp = root->link;
        root->link = prev;
        prev = root;
        root = temp;
    }
    if (temp != NULL) {
        head->link = recrev(temp, c);

    }
    return prev;
}
*/

Node* swapBlocksRecursive(Node* head, int k){
    if(head == NULL){
        return NULL;
    }
 
    Node* p = NULL;
    Node* q = head;
    Node* r = q->link;
    int count = 0;
    while(q !=NULL && count < k){
        count++;
        q->link = p;
        p = q;
        q = r;
        if(r){
          r = r->link;  
        }
        
        
    }
    head->link = swapBlocksRecursive(q,k);
    return p;
}

Node* swapPairsPerfect(Node* head){
    if(head == NULL){
        printf("\nList is empty");
        return NULL;
    }
    if(head->link == NULL){
        return head;
    }
    // initial placement
    Node* resultHead = head->link;
    Node* q = resultHead;
    Node* prev = NULL, *temp = head;
    
    // q will be 2nd node of a pair., temp will be first node of pair
    
    while(q->link != NULL && q->link->link != NULL){
        temp->link = q->link->link;
        prev = temp;
        temp = q->link;
        q->link = prev;
        q = temp->link;
    }
    
    if(q->link == NULL){ // even
        q->link = temp;
        temp->link = NULL;
        return resultHead;
        
    }else if(q->link->link == NULL){ //odd
        temp->link = q->link;
        q->link = temp;
        return resultHead;
    }
}


int main(int argc, char** argv) {
    Node* one = createListNode(1);
    Node* two = createListNode(2);
    Node* three = createListNode(3);
    Node* four = createListNode(4);
    Node* five = createListNode(5);
    Node* six = createListNode(6);
    Node* seven = createListNode(7);
    Node* eight = createListNode(8);
    Node* nine = createListNode(9);
    
    


    one->link =two;

    two->link = three;
    three->link = four;
    four->link = five;
    five->link = six;
    six->link = seven;
    //seven->link = eight;
    //eight->link = nine;
    //six->link = two;
    traverseList(one);
    printf("\n");
    traverseList(swapPairsPerfect(one));
    //(swapBlocksRecursive(one,4));
    return 0;
}


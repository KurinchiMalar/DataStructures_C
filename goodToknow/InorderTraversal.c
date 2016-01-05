/* 
 * File:   main.c
 * Author: kurnagar
 *
 * Created on May 30, 2014, 1:48 PM
 */

#include <stdio.h>
#include <stdlib.h>


/*
 * 
 */

    typedef struct TreeNode{
        int data;
        struct TreeNode* left;
        struct TreeNode* right;
    }Node;
    
    typedef struct StackStruct{
    int capacity;
    int size;
    Node** elements;
    
}Stack;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(struct TreeNode*));
    if(newNode != NULL){
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}
Node* computeInOrderRecursive(Node* root){
    if(root == NULL){
        return NULL;
    }
    computeInOrderRecursive(root->left);
    printf("%d",root->data);
    computeInOrderRecursive(root->right);
    
}
/*****************************************************************************/
Node* computeInOrderIterativeEasier(Node* root){
    Stack *mystack = createStack(11);
    while(1){
        while(root != NULL){
            push(mystack,root);
            root = root->left;
        }
        
        root = popWithoutPrint(mystack);
        printf("%d",root->data);
        root = root->right;
           
        
    }
}


Node* computeInOrderIterative(Node* root){
    Node* rootbkp = root;
    Stack* mystack = createStack(11);
    while(root != NULL){
        push(mystack,root);
        root = root->left;
    }
    
    Node* temp = NULL;
    while(temp = pop(mystack)){
        if(temp == NULL){
            return;
        }
        if(temp->right != NULL){
            temp = temp->right;
            while(temp != NULL){
                push(mystack,temp);
                temp = temp->left; 
            }
            
        }
    }
}
int main1(int argc, char** argv) {
    Node* zero = createNode(0);
    Node* one = createNode(1);
    Node* two = createNode(2);
    Node* three = createNode(3);
    Node* four = createNode(4);
    Node* five = createNode(5);
    Node* six = createNode(6);
    Node* seven = createNode(7);
    Node* eight = createNode(8);
    Node* nine = createNode(9);
    Node* ten = createNode(10);
    
    /*Node* root = seven;
    root->left = one;
    one->left = zero;
    one->right = three;
    
    three->left = two;
    three->right = five;
    
    five->left = four;
    five->right = six;
    
    root->right = nine;
    nine->left = eight;
    nine->right = ten;*/
    
    Node* root = one;
    
    one->left = two;
    one->right = three;
    
    two->left = four;
    two->right = five;
    
    three->left = six;
    three->right = seven;
    //computeInOrderRecursive(root);
    //computeInOrderIterative(root);
    computeInOrderIterativeEasier(root);
    return (EXIT_SUCCESS);
}


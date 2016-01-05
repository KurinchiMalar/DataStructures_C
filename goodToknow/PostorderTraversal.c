
/* 
 * File:   main.c
 * Author: kurnagar
 *
 * Created on May 31, 2014, 1:48 PM
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

/*Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(struct TreeNode*));
    if(newNode != NULL){
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}*/
Node* computePostOrderRecursive(Node* root){
    if(root == NULL){
        return NULL;
    }
    computePostOrderRecursive(root->left);
    computePostOrderRecursive(root->right);
    printf("%d",root->data);
    
}
/*****************************************************************************/



Node* computePostOrderIterative(Node* root){
    Node* rootbkp = root;
    Stack* mystack = createStack(11);
    while (1) {
        while (root != NULL) {
            root->data = -root->data;
            push(mystack, root);
            root = root->left;
        }

        // Node* temp = NULL;
        root = popWithoutPrint(mystack);
       

        if (root->data < 0) { // only left subtree has been visited
            root->data = -root->data;
            push(mystack, root);
            root = root->right;
        } else {
            printf("%d",root->data);
            root = NULL;
        }

    }
    
       
    
}
int main3(int argc, char** argv) {
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
    
    Node* root = one;
    
    one->left = two;
    one->right = three;
    
    two->left = four;
    two->right = five;
    
    three->left = six;
    three->right = seven;
    
    //computePostOrderRecursive(root);
    printf("\n");
    computePostOrderIterative(root);
    return (EXIT_SUCCESS);
}



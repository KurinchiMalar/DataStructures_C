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
Node* computePreOrderRecursive(Node* root){
    if(root == NULL){
        return NULL;
    }
    printf("%d",root->data);
    computePreOrderRecursive(root->left);
    computePreOrderRecursive(root->right);
    
}
/*****************************************************************************/

Node* computePreOrderIterativeEasier(Node* root) {
    Stack* mystack = createStack(11);
    while (1) {
        while (root != NULL) {
            printf("%d", root->data);
            push(mystack, root);
            root = root->left;
        }

        root = popWithoutPrint(mystack);
        root = root->right;
    }

}

Node* computePreOrderIterative(Node* root){
    Node* rootbkp = root;
    Stack* mystack = createStack(11);
    while(root != NULL){
        printf("%d",root->data);
        push(mystack,root);
        root = root->left;
    }
    
    Node* temp = NULL;
    while(temp = popWithoutPrint(mystack)){
        if(temp == NULL){
            return;
        }
        if(temp->right != NULL){
            temp = temp->right;
            while(temp != NULL){
                printf("%d",temp->data);
                push(mystack,temp);
                temp = temp->left; 
            }
            
        }
    }
}
int main2(int argc, char** argv) {
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
    
    computePreOrderRecursive(root);
    printf("\n");
    computePreOrderIterativeEasier(root);
    return (EXIT_SUCCESS);
}



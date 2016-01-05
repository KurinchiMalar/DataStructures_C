/* 
 * File:   SumOfElementsBT.c
 * Author: kurnagar
 *
 * Created on June 12, 2014, 7:28 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} Node,TreeNode;

typedef struct ListNode{
    TreeNode* data;
    struct ListNode* link;
}ListNode;

typedef struct Queue{
    ListNode* front;
    ListNode* rear;
}Queue;

Queue* queueSum = NULL;
int sum = 0;
int sumOfElementsIterative(Node* root){
    if(root == NULL){
        return 0;
    }
    queueSum = createQueue();
    EnQueue(queueSum,root);
    
    while(isQueueEmpty(queueSum) != 1){
        Node* temp = DeQueue(queueSum);
        sum+=temp->data;
        
        if(temp->left != NULL){
            EnQueue(queueSum,temp->left);
        }
        
        if(temp->right != NULL){
            EnQueue(queueSum,temp->right);
        }
    }
    return sum;
}
int sumOfElementsRecursion(Node* root){
    if(root == NULL){
        return 0;
    }
    return root->data+sumOfElementsRecursion(root->left)+sumOfElementsRecursion(root->right);
}
int mainSumOfBTelements(int argc, char** argv) {
    Node* root = createTreeNode(1);
    root->left = createTreeNode(6);
    root->right = createTreeNode(3);
    
    root->left->left = createTreeNode(7);
    root->left->right = createTreeNode(13);
    
    root->right->left = createTreeNode(4);
    root->right->right = createTreeNode(2);
    
    printf("\n Sum of elements in BT Recursive:  %d",sumOfElementsRecursion(root));
    printf("\n Sum of elements in BT Iterative:  %d",sumOfElementsIterative(root));

    return (EXIT_SUCCESS);
}


/* 
 * File:   FindMaxNode.c
 * Author: kurnagar
 *
 * Created on June 9, 2014, 9:15 PM
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
} Node;

Node* createTreeNode(int data){
    Node* newNode = (Node*)malloc(sizeof(struct TreeNode*));
    if(newNode != NULL){
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

int findMax(Node* root,int max){
    if(root == NULL){
        return 0;
    }
    
    
    int leftMax = findMax(root->left,max);
    int rightMax = findMax(root->right,max);
    
    if(leftMax >= rightMax){
        max = leftMax;
    }else{
        max = rightMax;
    }
    
    if(root->data > max){
        max = root->data;
    }
    
    return max;
}
int mainFindMax(int argc, char** argv) {
    int MAX = INT32_MIN;
    
    Node* root = createTreeNode(1);
    root->left = createTreeNode(6);
    root->right = createTreeNode(3);
    root->right->left = createTreeNode(4);
    printf("max is: %d",findMax(root,MAX));
    return (EXIT_SUCCESS);
}


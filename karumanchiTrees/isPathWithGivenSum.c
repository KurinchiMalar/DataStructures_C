/* 
 * File:   isPathWithGivenSum.c
 * Author: kurnagar
 *
 * Created on June 11, 2014, 11:47 PM
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
int isPathWithGivenSum(Node* root,int sum){
    if(root == NULL){
        return (sum == 0);
    }
    
    return isPathWithGivenSum(root->left,sum-root->data)||
    isPathWithGivenSum(root->right,sum-root->data);
    
    
}
int mainPathSum(int argc, char** argv) {
    Node* root = createTreeNode(1);
    root->left = createTreeNode(6);
    root->right = createTreeNode(3);
    
    root->left->left = createTreeNode(7);
    root->left->right = createTreeNode(13);
    
    root->right->left = createTreeNode(4);
    root->right->right = createTreeNode(2);
    
    printf("\n isPath exists with given sum : %d",isPathWithGivenSum(root,6));
    return (EXIT_SUCCESS);
}


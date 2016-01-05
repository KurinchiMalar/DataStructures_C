/* 
 * File:   deepestNode.c
 * Author: kurnagar
 *
 * Created on June 11, 2014, 4:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode,Node;

typedef struct DEEPRESULT{
    TreeNode* node;
    int level;
}RESULT;

RESULT* getDeepestNode(TreeNode* root){
    RESULT* result = (RESULT*)malloc(sizeof(struct DEEPRESULT));
    
    if(root == NULL){
       result->node = NULL; // level will be zero and return a null node.
       result->level = 0;
       return result;
    }
    
    RESULT* leftResult = getDeepestNode(root->left);
    RESULT* rightResult = getDeepestNode(root->right);
    
    result = leftResult?leftResult:rightResult;
    result->level++;
    
    if(result->node == NULL){
        result->node = root;
    }
    return result;
}
int mainDeepestNode(int argc, char** argv) {
    
    Node* one = createTreeNode(1);
    Node* two = createTreeNode(2);
    Node* three = createTreeNode(3);
    Node* four = createTreeNode(4);
    Node* five = createTreeNode(5);
    Node* six = createTreeNode(6);
    Node* seven = createTreeNode(7);
    Node* eight = createTreeNode(8);
    Node* nine = createTreeNode(9);
    Node* ten = createTreeNode(10);
    Node* eleven = createTreeNode(11);
    Node* twelve = createTreeNode(12);
    Node* thirteen = createTreeNode(13);
    Node* fourteen = createTreeNode(14);
    Node* fifteen = createTreeNode(15);
    
    one->left = two;
    one->right = three;
    
    two->left = four;
    two->right = five;
    
    three->left = six;
    three->right = seven;
    
    seven->left = eight;
    
    printf("\n Deepest Node is : %d",getDeepestNode(one)->node->data);
    
    return (EXIT_SUCCESS);
}


/* 
 * File:   heightOfBT.c
 * Author: kurnagar
 *
 * Created on June 10, 2014, 5:41 PM
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

int heightOfBT(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){ //leaf
        return 0;
    }
    int leftHeight = heightOfBT(root->left);
    int rightHeight = heightOfBT(root->right);
    
    return (leftHeight > rightHeight) ? (1+leftHeight):(1+rightHeight);
}
int heightOfNode(Node* root,Node* n1){

    if(root == NULL){
        return 0;
    }
    if(root->data == n1->data){
        printf("\n found");
        printf("\n heightOfBT: %d",heightOfBT(n1));
        return heightOfBT(n1);
    }
    heightOfNode(root->left,n1);
    heightOfNode(root->right,n1);
  
}

int mainHeight(int argc, char** argv) {
    //Node* zero = createTreeNode(0);
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
    Node* root = five;
    root->left = seven;
    root->right = three;
    root->right->left = two;
    root->right->left->left = four;
    printf("\n Height is : %d\n",heightOfNode(root,root->right));
    return (EXIT_SUCCESS);
}


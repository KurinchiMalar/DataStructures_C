/* 
 * File:   isStructurallyIdentical.c
 * Author: kurnagar
 *
 * Created on June 10, 2014, 10:46 PM
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
int isStructurallyIdentical(Node* root1,Node* root2){
    if(root1 == NULL && root2 == NULL){
        return 1;
    }
    if(root1 == NULL && root2 != NULL){
        return 0;
    }
    if(root1 != NULL && root2 == NULL){
        return 0;
    }
    
    return ((root1->data == root2->data) && (isStructurallyIdentical(root1->left,root2->left)) && isStructurallyIdentical(root1->right,root2->right));
}
int mainStructurallyIdentical(int argc, char** argv) {
    Node* root1 = createTreeNode(1);
    root1->left = createTreeNode(7);
    root1->right = createTreeNode(3);
    root1->right->left = createTreeNode(4);
    
    Node* root2 = createTreeNode(1);
    root2->left = createTreeNode(7);
    root2->right = createTreeNode(3);
    root2->right->left = createTreeNode(4);
    
    printf("\nisIdentical : %d",isStructurallyIdentical(root1,root2));
    return (EXIT_SUCCESS);
}


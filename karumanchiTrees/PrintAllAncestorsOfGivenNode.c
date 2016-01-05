/* 
 * File:   PrintAllAncestorsOfGivenNode.c
 * Author: kurnagar
 *
 * Created on June 13, 2014, 10:47 PM
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
int pathlen = 0;
int path[200] = {0};
void printAncestors(Node* root, Node* n1,int path[],int pathlen){
    
    if(root == NULL){
        return;
    }
    
    path[pathlen] = root->data;
    pathlen++;
    
    if(root->left == n1 || root->right == n1){
        printArray(path,pathlen);
    }
    else{
        printAncestors(root->left,n1,path,pathlen);
        printAncestors(root->right,n1,path,pathlen);
    }
    

}
int mainAncestors(int argc, char** argv) {
    Node* root = createTreeNode(1);
    root->left = createTreeNode(6);
    root->right = createTreeNode(3);
    
    root->left->left = createTreeNode(7);
    root->left->right = createTreeNode(13);
    
    root->right->left = createTreeNode(4);
    root->right->right = createTreeNode(2);
    
    //printAncestors(root,root,path,pathlen);
    printAncestors(root,root->right->right,path,pathlen);
    return (EXIT_SUCCESS);
}


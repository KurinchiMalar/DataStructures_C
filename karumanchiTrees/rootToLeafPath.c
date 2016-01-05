/* 
 * File:   rootToLeafPath.c
 * Author: kurnagar
 *
 * Created on June 11, 2014, 11:16 PM
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
int isLeafNode(Node* node){
    if(node->left == NULL && node->right == NULL){
        return 1;
    }
    return 0;
}

int pathLen = 0;
int pathArray[200]={0};

void printArray(int path[],int len){
    int i = 0;
    for(i ; i<len;i++){
        printf("%d",path[i]);
    }
    printf("\n");
}

void PrintRootToLeafPath(Node *root,int path[],int pathLen){
        
    if(root == NULL){
        return;
    }
    pathArray[pathLen] = root->data;
    pathLen++;
    if(isLeafNode(root) == 1){
        printArray(pathArray,pathLen);
    }
    else{
         PrintRootToLeafPath(root->left,pathArray,pathLen);
        PrintRootToLeafPath(root->right,pathArray,pathLen);
    }
   
}



int mainRootToLeafPath(int argc, char** argv) {
    Node* root = createTreeNode(1);
    root->left = createTreeNode(6);
    root->right = createTreeNode(3);
    
    root->left->left = createTreeNode(7);
    root->left->right = createTreeNode(13);
    
    root->right->left = createTreeNode(4);
    root->right->right = createTreeNode(2);
    
    PrintRootToLeafPath(root,pathArray,pathLen);
    return (EXIT_SUCCESS);
}


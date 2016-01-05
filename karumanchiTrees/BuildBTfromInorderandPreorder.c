/* 
 * File:   BuildBTfromInorderandPreorder.c
 * Author: kurnagar
 *
 * Created on June 13, 2014, 7:16 AM
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

int searchInorderForRoot(int *inorder,int start,int end,int data){
    if(inorder == NULL){
        return NULL;
    }
    while(start <= end){
        if(inorder[start] == data){
            return start;
        }
        start++;
    }
    return -1;
}
Node* buildTreeFromInorderAndPreOrder(int inorder[],int preorder[],int instart,int inend){
    static int prestart = 0;
    
    if(instart > inend){
        return NULL;
    }
    Node *newNode = (Node*)malloc(sizeof(struct TreeNode));
    newNode->data = preorder[prestart];
    prestart++;
    
    if(instart == inend){
        return newNode;
    }
    
    
    int inIndex = searchInorderForRoot(inorder,instart,inend,newNode->data);
    //printf("\nIndex is %d",inIndex);
    newNode->left = buildTreeFromInorderAndPreOrder(inorder,preorder,instart,inIndex-1);
    newNode->right = buildTreeFromInorderAndPreOrder(inorder,preorder,inIndex+1,inend); 
    
    return newNode;
    
    
}
void traverseTreeBuild(Node* root){
    if(root == NULL){
        return NULL;
    }
    printf("%d",root->data);
    traverseTreeBuild(root->left);
    traverseTreeBuild(root->right);
}
int mainBuildTree(int argc, char** argv) {
    int inorder[]={4,2,5,1,6,3};
    int preorder[] = {1,2,4,5,3,6};
    
    //printf("\nindex is :%d",searchInorderForRoot(inorder,0,5,1));
    printf("\n");
    traverseTreeBuild(buildTreeFromInorderAndPreOrder(inorder,preorder,0,5));
    
    return (EXIT_SUCCESS);
}


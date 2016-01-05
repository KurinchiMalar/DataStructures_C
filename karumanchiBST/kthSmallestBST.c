/* 
 * File:   kthSmallestBST.c
 * Author: kurnagar
 *
 * Created on June 15, 2014, 10:10 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct BSTNode{
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
}bstNode;

bstNode* kthSmallest(bstNode* root,int k,int* currentCount){
   // int cur = 0;
    if(root == NULL){
        return NULL;
    }
    bstNode* leftSubtree = kthSmallest(root->left,k,currentCount);
    if( leftSubtree != NULL){
        return leftSubtree;
    }
    *currentCount = *currentCount + 1;
    if(*currentCount == k){
        return root;
    }
    
    return kthSmallest(root->right,k,currentCount);
}
int mainKthSmallBst(int argc, char** argv) {
    
     bstNode *one = createBSTNode(1);
    bstNode *two = createBSTNode(2);
    bstNode *three = createBSTNode(3);
    bstNode *four = createBSTNode(4);
    bstNode *five = createBSTNode(5);
    bstNode *six = createBSTNode(6);
    bstNode *seven = createBSTNode(7);
    bstNode *eight = createBSTNode(8);
    bstNode *nine = createBSTNode(9);
    
    bstNode *twenty = createBSTNode(20);
    bstNode* twelve = createBSTNode(12);
    bstNode* ten = createBSTNode(10);
    bstNode* fourteen = createBSTNode(14);
    bstNode* twentytwo = createBSTNode(22);
   
    bstNode *root = twenty;
    
    twenty->left = eight;
    twenty->right = twentytwo;
    
    eight->left = four;
    eight->right = twelve;
    
    twelve->left = ten;
    twelve->right = fourteen;
    
    //traverseBst(root);
    
    int temp = 0;
    //int *ptr = temp;
    
    printf("\n 4th smallest  is : %d",kthSmallest(root,1,&temp)->data);

    return (EXIT_SUCCESS);
}


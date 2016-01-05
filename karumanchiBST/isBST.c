/* 
 * File:   isBST.c
 * Author: kurnagar
 *
 * Created on June 15, 2014, 9:28 AM
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

int isBST(bstNode* root,int min,int max){
    if(root == NULL){
        return 1;
    }
    
    return ( ((root->data > min)&&(root->data < max)) && (isBST(root->left,min,root->data)) && (isBST(root->right,root->data,max)) );
}
int mainIsBST(int argc, char** argv) {
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
    
    traverseBst(root);
    
    printf("\n isBST: %d",isBST(root,INT32_MIN,INT32_MAX));
    return (EXIT_SUCCESS);
}


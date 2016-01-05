/* 
 * File:   FloorAndCeilingBST.c
 * Author: kurnagar
 *
 * Created on June 15, 2014, 11:45 AM
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

bstNode* getCeil(bstNode* root,bstNode* prev, int d){
    if(root == NULL){
        return NULL;
    }
    
    bstNode* right = getCeil(root->right,prev,d);
    if(right != NULL){
        return right;
    }
    if(root->data == d){
        return root;
    }
    if(root->data < d){ // right --> larger values... Once yu encounter a small value --> that is the smallest of larger ones.
        return prev;
    }
    prev = root;
    return getCeil(root->left,prev,d);
}



bstNode* getFloor(bstNode* root,bstNode* prev,int d){
    if(root == NULL){
        return NULL;
    }
    
    bstNode* left = getFloor(root->left,prev,d);
    
    if( left != NULL){
        return left;
    }
    if(root->data == d){
        return root;
    }
    if(root->data > d){ // left --> goin thru small values once yu find a larger one return prev.That is the largest value among smaller ones
        return prev;
    }
    prev = root;
    
    return getFloor(root->right,prev,d);
}
int mainFloorCeil(int argc, char** argv) {
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
    
    bstNode *p = NULL;
   // printf("\nfloor is :%d",getFloor(root,&p,21)->data);
    printf("\nCeil is :%d",getFloor(root,&p,21)->data);

    return (EXIT_SUCCESS);
}


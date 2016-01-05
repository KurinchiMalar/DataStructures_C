/* 
 * File:   LCABst.c
 * Author: kurnagar
 *
 * Created on June 14, 2014, 10:29 PM
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

bstNode* getLCAIterative(bstNode* root,bstNode* n1,bstNode* n2){
    if(root == NULL){
        return NULL;
    }
    while(root != NULL){
        if(root->data > n1->data && root->data >n2->data){
            root = root->left;
        }else if(root->data < n1->data && root->data < n2->data){
            root = root->right;
        }else{
            break;
        }
    }
    return root;
}
bstNode* getLCARecursive(bstNode* root,bstNode* n1,bstNode* n2){
    if(root == NULL){
        return NULL;
    }
    
   if( (root->data > n1->data) && (root->data >n2->data) ){
       return getLCARecursive(root->left,n1,n2);
   }
   
   if( (root->data < n1->data) && (root->data < n2->data) ){
       return getLCARecursive(root->right,n1,n2);
   }
    return root;
}
int mainLCABst(int argc, char** argv) {
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
    
    printf("\n LCA is : %d",getLCAIterative(root,four,fourteen)->data);
    
    
    return (EXIT_SUCCESS);
}


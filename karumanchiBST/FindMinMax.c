/* 
 * File:   FindMinMax.c
 * Author: kurnagar
 *
 * Created on June 14, 2014, 6:49 PM
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

bstNode* findMaxIterative(bstNode* root){
    if(root == NULL){
        return NULL;
    }
    bstNode* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}
bstNode* findMaxRecursive(bstNode* root){
    if(root == NULL){
        return NULL;
    }
    if(root->right == NULL){ // no need to check left because...right most oda left is anyway less than root at that level.
        return root;
    }
    return findMaxRecursive(root->right);
}

bstNode* findMinIterative(bstNode* root){
    if(root == NULL){
        return NULL;
    }
    bstNode* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
bstNode* findMinRecursive(bstNode* root){
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL){ // no need to check right because...left most oda right is anyway greater than root at that level.
        return root;
    }
    return findMinRecursive(root->left);
}
int mainMinMaxBst(int argc, char** argv) {
    bstNode *one = createBSTNode(1);
    bstNode *two = createBSTNode(2);
    bstNode *three = createBSTNode(3);
    bstNode *four = createBSTNode(4);
    bstNode *five = createBSTNode(5);
    bstNode *six = createBSTNode(6);
    bstNode *seven = createBSTNode(7);
    bstNode *eight = createBSTNode(8);
    bstNode *nine = createBSTNode(9);
    bstNode *ten = createBSTNode(10);
    bstNode *sixteen = createBSTNode(16);
    bstNode *thirteen = createBSTNode(13);
    
    ten->left = six;
    ten->right = sixteen;
    
    six->left = four;
    six->right = nine;
    
    sixteen->left = thirteen;
    
    nine->left = seven;
    
    bstNode *root = ten;
    bstNode *resultMin = findMinIterative(root);
    bstNode *resultMax = findMaxRecursive(root);
    if(resultMin != NULL && resultMax != NULL){
        printf("\n not null");
        printf("\n minimum is %d",resultMin->data);
        printf("\n maximum is %d",resultMax->data);
    }
    
    return (EXIT_SUCCESS);
}


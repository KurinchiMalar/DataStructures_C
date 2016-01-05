/* 
 * File:   printElementsBetweenK1AndK2.c
 * Author: kurnagar
 *
 * Created on June 15, 2014, 1:26 PM
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

void printElementsInRange(bstNode* root,int k1,int k2){
    if(root == NULL){
        return;
    }
    if(root->data >= k1){ // move left
        printElementsInRange(root->left,k1,k2);
    }
    if((k1 < root->data) && (root->data < k2) ){ // gotta print
        printf("%d",root->data);
    }
    if(root->data <= k2){
        printElementsInRange(root->right,k1,k2);
    }
 
}

int main(int argc, char** argv) {
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
    
    printElementsInRange(root,4,22);
    return (EXIT_SUCCESS);
}


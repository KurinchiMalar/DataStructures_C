/* 
 * File:   InsertInBST.c
 * Author: kurnagar
 *
 * Created on June 14, 2014, 8:14 PM
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

void traverseBst(bstNode* root){
    if(root == NULL){
        return;
    }
    
    printf("%d",root->data);
    traverseBst(root->left);
    traverseBst(root->right);
}

bstNode* insertInBst(bstNode* root, int d){
    if(root == NULL){
        bstNode* newNode = createBSTNode(d);
        return newNode;
    }
    if(d < root->data){
        root->left = insertInBst(root->left,d);
    }else if(d > root->data){
        root->right = insertInBst(root->right,d);
    }
    return root;   
    
}
int mainInsertInBST(int argc, char** argv) {
     bstNode *one = createBSTNode(1);
    bstNode *two = createBSTNode(2);
    bstNode *three = createBSTNode(3);
    bstNode *four = createBSTNode(4);
    bstNode *five = createBSTNode(5);
    bstNode *six = createBSTNode(6);
    bstNode *seven = createBSTNode(7);
    bstNode *eight = createBSTNode(8);
    bstNode *nine = createBSTNode(9);
    
    six->left = two;
    six->right = eight;
    
    two->left = one;
    two->right = four;
    
    one->left = three;
    
    bstNode *root = six;
    
    traverseBst(root);
    printf("\n");
    traverseBst(insertInBst(root,5));
    return (EXIT_SUCCESS);
}


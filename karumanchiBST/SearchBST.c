/* 
 * File:   main.c
 * Author: kurnagar
 *
 * Created on June 14, 2014, 4:23 PM
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

bstNode* createBSTNode(int data){
    bstNode* newNode = (bstNode*)malloc(sizeof(struct BSTNode));
    if(newNode != NULL){
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }else{
        printf("\n bstNode creation problem");
        return NULL;
    }
}
bstNode* getFoundBSTIterative(bstNode* root,int d){
    if(root == NULL){
        return NULL;
    }
    bstNode* temp = root;
    while(temp != NULL){
        if(d ==  temp->data){
            return temp;
        }else if( d > temp->right){
            temp = temp->right;
        }else {
            temp = temp->left;
        }
       
    }

}
bstNode* getFoundBSTRecursive(bstNode* root,int d){
    if(root == NULL){
        return NULL;
    }
    if(d < root->data){
        return getFoundBSTRecursive(root->left,d);
    }else if(d > root->data){
        return getFoundBSTRecursive(root->right,d);
    }
    return root;
}

int isFoundInBST(bstNode* root,int d){
    if(root == NULL){
        return 0;
    }
    if(root->data == d){
        return 1;
    }
 
    if(d < root->data){
        return isFoundInBST(root->left,d);
    }else if (d > root->data){
        return isFoundInBST(root->right,d);
    }
    return 0;
}
int mainSearchBST(int argc, char** argv) {

    bstNode *one = createBSTNode(1);
    bstNode *two = createBSTNode(2);
    bstNode *three = createBSTNode(3);
    bstNode *four = createBSTNode(4);
    bstNode *five = createBSTNode(5);
    bstNode *six = createBSTNode(6);
    bstNode *seven = createBSTNode(7);
    bstNode *eight = createBSTNode(8);
    bstNode *nine = createBSTNode(9);
    
    seven->left = four;
    seven->right = nine;
    
    four->left = two;
    four->right = five;
    
    bstNode *root = seven;
    printf("\n isFound :%d",getFoundBSTIterative(root,9)->data);
    printf("\n isFound status :%d",isFoundInBST(root,9));
    return (EXIT_SUCCESS);
}


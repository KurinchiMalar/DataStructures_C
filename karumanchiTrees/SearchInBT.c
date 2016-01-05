/* 
 * File:   SearchInBT.c
 * Author: kurnagar
 *
 * Created on June 10, 2014, 6:52 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}Node;

Node* isFoundBT(Node* root,int d){
    if(root == NULL ){
        return NULL;
    }
    if(root->data == d){
        return root;
    }
    Node* left = isFoundBT(root->left,d);
    if( left != NULL){
        return left;
    }
    Node* right = isFoundBT(root->right,d);
     
    return left?left:right;
}
int isFound(Node* root,int d){
    if (root == NULL){
        return 0;
    }
    if(root->data == d){
        return 1;
    }
    int left = isFound(root->left,d);
    int right;
    if(left != 1){
        right = isFound(root->right,d);
    }
    
    return left?left:right;
}
int mainSearchInBT(int argc, char** argv) {
    Node* root = createTreeNode(5);
    root->left = createTreeNode(7);
    root->right = createTreeNode(3);
    root->right->left = createTreeNode(2);
    
    Node* searchresult = isFoundBT(root,3);
    if(searchresult != NULL){
        printf("\n not null");
        printf("\n result is %d",searchresult->data);
        
    }
   printf("searchResult is: %d",isFoundBT(root,3)->data);

    return (EXIT_SUCCESS);
}


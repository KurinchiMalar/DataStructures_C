/* 
 * File:   sizeOfBT.c
 * Author: kurnagar
 *
 * Created on June 10, 2014, 7:56 AM
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
int sizeOfBT(Node* root){
    if(root == NULL){
        return 0;
    }
    return 1+sizeOfBT(root->left)+sizeOfBT(root->right);
}
int mainSize(int argc, char** argv) {
    Node* root = createNode(5);
/*
    root->left = createNode(7);
    root->right = createNode(3);
    root->right->left = createNode(2);
*/
    printf("\nsize is %d",sizeOfBT(root));
    return (EXIT_SUCCESS);
}


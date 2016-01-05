/* 
 * File:   deleteNodeInBT.c
 * Author: kurnagar
 *
 * Created on June 14, 2014, 1:09 PM
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
}TreeNode,Node;

/*
Node* deleteNodeInBT(Node *root,Node *n1){
   // static Node* deepest = getDeepestNode(root);
    if(root == NULL){
        return NULL;
    }
    
    if(root == n1){
        root->data = deepest->data;
        free(deepest);
        
    }
}
*/
int mainDeleteNode(int argc, char** argv) {

    return (EXIT_SUCCESS);
}


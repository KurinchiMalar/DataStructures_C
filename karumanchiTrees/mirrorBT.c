/* 
 * File:   mirrorBT.c
 * Author: kurnagar
 *
 * Created on June 12, 2014, 8:39 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} Node,TreeNode;

Node* traverseTreeMirror(Node* root){
    if(root == NULL){
        return NULL;
    }
    printf("%d",root->data);
    traverseTreeMirror(root->left);
    traverseTreeMirror(root->right);
}
int isMirror(Node* root1,Node* root2){
/*
    if((root1 == NULL && root2 == NULL ) || root1->data == root2->data){
        return 1;
    }
*/
     if((root1 == NULL && root2 == NULL )){
        return 1;
    }
    if((root1 == NULL || root2 == NULL )){
        return 0;
    }
    if(root1->data != root2->data){
        return 0;
    }
    return ((root1->data == root2->data) && isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left));
    
}
Node* getMirror(Node* root){
    if(root == NULL){
        return NULL;
    }
    getMirror(root->left);
    getMirror(root->right);
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
    
}
int mainMirrorBT(int argc, char** argv) {
    Node* root1 = createTreeNode(1);
    root1->left = createTreeNode(6);
    root1->right = createTreeNode(3);

    traverseTreeMirror(root1);
    printf("\n");
    //Node* root2 = getMirror(root1);
    Node* root2 = createTreeNode(1);
    root2->left = createTreeNode(3);
    root2->right = createTreeNode(6);
    traverseTreeMirror(root2);
    printf("\n");
    printf("\n isMirror: %d",isMirror(root1,root2));

    
    return (EXIT_SUCCESS);
}


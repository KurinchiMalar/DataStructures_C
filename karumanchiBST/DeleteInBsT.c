/* 
 * File:   DeleteInBsT.c
 * Author: kurnagar
 *
 * Created on June 14, 2014, 9:26 PM
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

bstNode* deleteInBST(bstNode* root,int d){
    if(root == NULL){
        return NULL;
    }
    if(d < root->data){
        root->left = deleteInBST(root->left,d);
    }else if(d > root->data){
        root->right = deleteInBST(root->right,d);
    }else{ // found node with data to be deleted
        if(root->left == NULL && root->right == NULL ){//is leaf --> return NULL to parent link.
            return NULL;
        }else if(root->left != NULL && root->right != NULL){ // two children--> replace current node with largest of left subtree.
            bstNode *temp = findMaxRecursive(root->left); 
            root->data = temp->data ;   // duplicate it
            root->left = deleteInBST(root->left,root->data); // the other copy should be deleted.tis control will go to single child logic
        }else{ // one child
            bstNode *temp1 = root;
            if(root->left != NULL){
                root = root->left;    
            }else if(root->right != NULL){
                root = root->right;
            }
             free(temp1);
        }
    }
    return root;
}
int mainDeleteNodeInBst(int argc, char** argv) {
     bstNode *one = createBSTNode(1);
    bstNode *two = createBSTNode(2);
    bstNode *three = createBSTNode(3);
    bstNode *four = createBSTNode(4);
    bstNode *five = createBSTNode(5);
    bstNode *six = createBSTNode(6);
    bstNode *seven = createBSTNode(7);
    bstNode *eight = createBSTNode(8);
    bstNode *nine = createBSTNode(9);
    
    //leaf node to be deleted
/*
    six->left = two;
    six->right = eight;
    
    two->left = one;
    two->right = five;
*/
    
    //one child node to be deleted
/*
    six->left = two;
    six->right = eight;
    
    two->left = one;
    two->right = four;
    
    four->left = three;
*/
    // two child node to be deleted

    four->left = two;
    four->right = eight;
    
    eight->left = five;
    eight->right = one;
    
    five->right = seven;
    
    seven->left = six;
    
    bstNode *root = four;
    traverseBst(root);
    printf("\n");
    traverseBst(deleteInBST(root,8));
    return (EXIT_SUCCESS);
}


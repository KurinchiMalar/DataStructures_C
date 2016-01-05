/* 
 * File:   ShortestPathBetweenTwoNodes.c
 * Author: kurnagar
 *
 * Created on June 15, 2014, 7:53 AM
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

int getShortestPathBetweenTwoNodesBst(bstNode* root,bstNode* n1,bstNode* n2){
    bstNode *commonAnces = getLCARecursive(root,n1,n2);
    bstNode *leftPath = commonAnces;
    bstNode *rightPath = commonAnces;
    int leftCount = 0;
    int rightCount = 0;
    
    while(leftPath != NULL){ // for tracking n1
        if(n1->data < leftPath->data ){
            leftPath = leftPath->left;
            leftCount++;
        }else if(n1->data > leftPath->data){
            leftPath = leftPath->right;
            leftCount++;
        } else{ // found n1
            break;
        }
    }
    
    while(rightPath != NULL){
           if(n2->data < rightPath->data ){
            rightPath = rightPath->left;
            rightCount++;
        }else if(n2->data > rightPath->data){
            rightPath = rightPath->right;
            rightCount++;
        } else{ // found n1
            break;
        }
    }
    return leftCount+rightCount;
}
int mainShortestPathBst(int argc, char** argv) {
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
    
    printf("\n Shortest path is : %d",getShortestPathBetweenTwoNodesBst(root,four,fourteen));

    return (EXIT_SUCCESS);
}


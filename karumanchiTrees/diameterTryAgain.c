/* 
 * File:   diameterTryAgain.c
 * Author: kurnagar
 *
 * Created on June 12, 2014, 11:22 AM
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
int findMaxKurinchi(int n1,int n2){
    return n1 > n2 ? n1:n2;
}
int getDiameterKurinchi(Node* root,int *height){
    int lh = 0, rh = 0;
    if (root == NULL){
        *height = 0;
        return 0;
    }
    int leftDia = getDiameterKurinchi(root->left,&lh);
    int rightDia = getDiameterKurinchi(root->right,&rh);
    *height = findMaxKurinchi(lh,rh)+1;
    
    return findMaxKurinchi(findMaxKurinchi(leftDia,rightDia),1+lh+rh);
    
}
int mainDiameter(int argc, char** argv) {
    Node* one = createTreeNode(1);
    Node* two = createTreeNode(2);
    Node* three = createTreeNode(3);
    Node* four = createTreeNode(4);
    Node* five = createTreeNode(5);
    Node* six = createTreeNode(6);
    Node* seven = createTreeNode(7);
    Node* eight = createTreeNode(8);
    Node* nine = createTreeNode(9);
    Node* ten = createTreeNode(10);
    Node* eleven = createTreeNode(11);
    Node* twelve = createTreeNode(12);
    Node* thirteen = createTreeNode(13);
    Node* fourteen = createTreeNode(14);
    Node* fifteen = createTreeNode(15);

    
/*
    one->left = two;
    one->right = three;
    
    two->left = four;
    two->right = five;
    
    five->left = six;
    five->right = seven;
    
    three->right = eight;
    
    eight->right = nine;
    
    nine->right = ten;
    
    nine->left = eleven;
    
    eleven->left = twelve;
    eleven->right = thirteen;
*/
    
    one->left = two;
    one->right = fourteen;
    
    two->left = three;
    two->right = nine;
    
    three->left = four;
    three->right = five;
    
    five->left = six;
    
    six->left = seven;
    six->right = eight;
    
    nine->right = ten;
    
    ten->left = eleven;
    ten->right = twelve;
    
    twelve->right = thirteen;
    
    fourteen->right = fifteen;
    
    int a = 0;
    int *h = a;
    
    printf("\n dia is :%d",getDiameterKurinchi(one,&a));
    return (EXIT_SUCCESS);
}


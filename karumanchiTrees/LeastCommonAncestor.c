/* 
 * File:   LeastCommonAncestor.c
 * Author: kurnagar
 *
 * Created on June 14, 2014, 9:05 AM
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


Node* LCA(Node *root, Node *n1,Node *n2){
    if(root == NULL){
        return NULL;
    }
    if(root == n1 || root == n2){
        return root;
    }
    
    if((root->left == n1 && root->right == n2) || (root->right == n1 && root->left == n2) ){
        return root;
    }
    
    Node* left = LCA(root->left,n1,n2);
    Node* right = LCA(root->right,n1,n2);
    
    if(left && right){
        return root;
    }
    
    return left?left:right;
}
int getCountUptoGivenNode(Node* root,Node* n1,int count){
    if(root == NULL){
        return 0;
    }
    
    if(root ->data == n1->data){
        return count;
    }
    count++;
    int left = getCountUptoGivenNode(root->left,n1,count);
    if(left){
        return left;
    }
    int right = getCountUptoGivenNode(root->right,n1,count);
    return left?left:right;
    
}
int getShortestPathBetweenTwoNodesBT(Node *root,Node *n1,Node *n2){
    Node* commonAncestor = LCA(root,n1,n2);
    Node* leftPath = commonAncestor;
    Node* rightPath = commonAncestor;
    int leftCount = 0;
    int rightCount = 0;
    
    leftCount = getCountUptoGivenNode(commonAncestor,n1,leftCount);
    rightCount = getCountUptoGivenNode(commonAncestor,n2,rightCount);
    
    printf("\n leftCount: %d",leftCount);
    printf("\n rightCount : %d",rightCount);
    return leftCount+rightCount;
}
int mainLCAandShortestPathBT(int argc, char** argv) {
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
    
/*
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
*/
    one->left = two;
    one->right = three;
    
    two->left = four;
    two->right = five;
    
    three->left = six;
    three->right = seven;
    
    six->right = eight;
    printf("\n LCA is  : %d",LCA(one,four,six)->data);
    printf("\n shortest path is : %d",getShortestPathBetweenTwoNodesBT(one,four,six));
    return (EXIT_SUCCESS);
}


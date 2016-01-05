/*
/* 
 * File:   LevelOrder.c
 * Author: kurnagar
 *
 * Created on June 7, 2014, 10:15 PM
 */


#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

typedef struct ListNode{
    TreeNode* data;
    struct ListNode* link;
}ListNode;

typedef struct Queue{
    ListNode* front;
    ListNode* rear;
}Queue;

Queue* queue = NULL;

void levelOrderTraversal(TreeNode* root){
    
    if(root == NULL){
        return;
    }
    queue = createQueue();

    EnQueue(queue,root);
    while(isQueueEmpty(queue) != 1){
        root = DeQueue(queue);
        
        printf("%d",root->data);
        
        if(root->left != NULL){
            EnQueue(queue,root->left);
        }
        
        if(root->right != NULL){
            EnQueue(queue,root->right);
        }
    }
}
int mainLevelOrder(int argc, char** argv) {

    TreeNode* zero = createTreeNodeNow(0);
    TreeNode* one = createTreeNodeNow(1);
    TreeNode* two = createTreeNodeNow(2);
    TreeNode* three = createTreeNodeNow(3);
    TreeNode* four = createTreeNodeNow(4);
    TreeNode* five = createTreeNodeNow(5);
    TreeNode* six = createTreeNodeNow(6);
    TreeNode* seven = createTreeNodeNow(7);
    TreeNode* eight = createTreeNodeNow(8);
    TreeNode* nine = createTreeNodeNow(9);
    TreeNode* ten = createTreeNodeNow(10);

    TreeNode* root = one;
    
/*
    one->left = two;
    one->right = three;
    
    two->left = four;
    two->right = five;
    
    three->left = six;
    three->right = seven;
*/
    one->left = six;
    one->right = eight;
    
    six->left = two;
    six->right = four;
    
    eight->left = nine;
    eight->right = seven;
    
    levelOrderTraversal(root);

    return (EXIT_SUCCESS);
}



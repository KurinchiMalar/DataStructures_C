/* 
 * File:   ZigZagTreeTraversal.c
 * Author: kurnagar
 *
 * Created on June 14, 2014, 10:19 AM
 * 
 * http://ideone.com/DLApYB
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

typedef struct ListNode{
    TreeNode* data;
    struct ListNode* link;
}ListNode;

typedef struct Stack{
    ListNode* top;
}Stack;

Stack *currentStack = NULL;
Stack *nextStack = NULL;

void ZigZagTraversal(Node* root){
    if(root == NULL){
        return NULL;
    }
    static int leftToRight = 1;
    currentStack = createStack();
    nextStack = createStack();
    
   
    push(currentStack,root);
    
    while (isStackEmpty(currentStack) != 1) {
        Node* temp = pop(currentStack);
         printf("%d",temp->data);
        if (temp != NULL) {
            //printf("\npopping : %d", temp->data);
            if (leftToRight == 1) {
                if(temp->left)
                push(nextStack, temp->left);
                if(temp->right)
                push(nextStack, temp->right);
            } else {
                if(temp->right)
                push(nextStack, temp->right);
                if(temp->left)
                push(nextStack, temp->left);
            }

        }
       

        if (isStackEmpty(currentStack) == 1) {
            Stack* tempStack = currentStack;
            currentStack = nextStack;
            nextStack = tempStack;
           
            leftToRight = 1-leftToRight;
        }

    }
    
    
    
}
int mainZigZag(int argc, char** argv) {
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
    
    one->left = two;
    one->right = three;
    
    two->left = four;
    two->right = five;
    
    three->left = six;
    three->right = seven;
    
/*
    five->left = six;
    five->right = seven;
    
    three->right = eight;
    
    eight->right = nine;
    
    nine->right = ten;
    
    nine->left = eleven;
    
    eleven->left = twelve;
    eleven->right = thirteen;
*/
    
    ZigZagTraversal(one);

    return (EXIT_SUCCESS);
}


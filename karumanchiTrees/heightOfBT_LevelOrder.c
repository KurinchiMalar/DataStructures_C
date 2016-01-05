/* 
 * File:   heightOfBT_LevelOrder
 * Author: kurnagar
 *
 * Created on June 10T, 2014, 6:00 PM
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
}TreeNode;

typedef struct ListNode{
    TreeNode* data;
    struct ListNode* link;
}ListNode;

typedef struct Queue{
    ListNode* front;
    ListNode* rear;
}Queue;

Queue* queue2 = NULL;
int map[20] = {0};

int heightOfBTLevelOrder(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    queue2 = createQueue();
    EnQueue(queue2,root); //root is of level 1
    EnQueue(queue2,NULL); // put a marker.
    int level = 1;
    while(isQueueEmpty(queue2) != 1){
        TreeNode *temp = DeQueue(queue2);
        
        if(temp != NULL){
            if(temp->left != NULL){
                EnQueue(queue2,temp->left);
            }
            if(temp->right != NULL){
                EnQueue(queue2,temp->right);
            }
        }else{// temp = NULL...put another marker for next level
            if(isQueueEmpty(queue2) != 1){
                EnQueue(queue2,NULL);
                 level++;
            }
            
        }
    }
    return level;
} 

int mainHeightOfBTLevelOrder(int argc, char** argv) {
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
    
    seven->left = two;

    printf("\n depth is %d",heightOfBTLevelOrder(one));
    return (EXIT_SUCCESS);
}


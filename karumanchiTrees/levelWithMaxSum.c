/* 
 * File:   levelWithMaxSum.c
 * Author: kurnagar
 *
 * Created on June 11, 2014, 8:05 PM
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

Queue* queueS = NULL;
int getLevelWithMaxSum(TreeNode* root){
    if(root == NULL){
        return -1;
    }
    queueS = createQueue();
    EnQueue(queueS,root);
    EnQueue(queueS,NULL);
    int level = 1;
    int maxSum = INT32_MIN;
    int maxLevel = -1;
    int curLevelSum = 0;
    while(isQueueEmpty(queueS) != 1){
        TreeNode* temp = DeQueue(queueS);
        
        if(temp == NULL){
            
                if(maxSum < curLevelSum){
                    maxSum = curLevelSum;
                    maxLevel = level;
                }
                curLevelSum = 0;
                 level++;
            if(isQueueEmpty(queueS) != 1){
                EnQueue(queueS,NULL);
            }
           
        }else{
            if(isQueueEmpty(queueS) != 1){
                curLevelSum += temp->data;
                if(temp->left != NULL){
                    
                    EnQueue(queueS,temp->left);
                }
                if(temp->right != NULL){
                    
                    EnQueue(queueS,temp->right);
                }
                
/*
                if(curLevelSum > maxSum){
                    maxSum = curLevelSum;
                }
*/
            }
        }
        
    }
    printf("\nMaxSum is :%d",maxSum);
    return maxLevel;
     
}
int mainLevelWithMaxSum(int argc, char** argv) {
     TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(6);
    root->right = createTreeNode(3);
    
    root->left->left = createTreeNode(7);
    root->left->right = createTreeNode(13);
    
    root->right->left = createTreeNode(4);
    root->right->right = createTreeNode(2);
    
    printf("\n Max level is : %d",getLevelWithMaxSum(root));
    return (EXIT_SUCCESS);
}


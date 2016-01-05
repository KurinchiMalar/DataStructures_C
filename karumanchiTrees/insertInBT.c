/* 
 * File:   insertInBT.c
 * Author: kurnagar
 *
 * Created on June 10, 2014, 7:07 AM
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

Queue* queue1 = NULL;
TreeNode* createNodeToInsert(int data){
    TreeNode *newNode = (TreeNode*)malloc(sizeof(struct TreeNode*));
    if(newNode != NULL){
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

TreeNode* traverseTree(TreeNode* root){
    if(root == NULL){
        return NULL;
    }
    printf("%d",root->data);
    traverseTree(root->left);
    traverseTree(root->right);
}

int isLeaf(TreeNode* node){
    if(node == NULL){
        return 0;
    }
    if(node->left == NULL && node->right == NULL){
        return 1;
    }
    return 0;
}
void insertInBTLevelOrder(TreeNode* root,int d){
    if(root == NULL){
        return;
    }
    queue1 = createQueue();
    EnQueue(queue1,root);
    while(isQueueEmpty(queue1) != 1){
        root = DeQueue(queue1);
        if(isLeaf(root) == 1){
            root->left = createTreeNode(d);
            return;
        }else if(root->left == NULL && root->right != NULL){
            root->left = createTreeNode(d);
            return;
        }else if(root->left != NULL && root->right == NULL){
            root->right = createTreeNode(d);
            return;
        }
        if(root->left){
            EnQueue(queue1,root->left);
        }
        if(root->right){
            EnQueue(queue1,root->right);
        }
    }
    
    
}
void insertInBTRecursive(TreeNode* root,int d){ // instead of static int yu have have it passed along with function call also.
    static int isInserted = 0;
    if(root == NULL){
        root = createNodeToInsert(d);
        isInserted = 1;
        return;
    }
    
    if(isLeaf(root) == 1){
        root->left = createNodeToInsert(d);
         isInserted = 1;
        return;
    }else if(root->left == NULL){
        root->left = createNodeToInsert(d);
        isInserted = 1;
        return;
    }else if(root->right == NULL){
        root->right = createNodeToInsert(d);
        isInserted = 1;
        return;
    }
    insertInBTRecursive(root->left,d);
    if(isInserted != 1)
    insertInBTRecursive(root->right,d);
    
}
int mainInsertBT(int argc, char** argv) {
     TreeNode* root = createNodeToInsert(5);
    root->left = createNodeToInsert(7);
    root->right = createNodeToInsert(3);
    root->right->left = createNodeToInsert(2);
    //traverseTree(root);
    insertInBTRecursive(root,6);
    printf("\n");
    insertInBTLevelOrder(root,7);
    printf("\n");
    traverseTree(root);
    //printf("searchResult is: %d",isFound(root,5));

    return (EXIT_SUCCESS);
}


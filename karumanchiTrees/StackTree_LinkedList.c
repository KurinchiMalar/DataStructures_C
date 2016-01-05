/* 
 * File:   StackTree_LinkedList.c
 * Author: kurnagar
 *
 * Created on June 10, 2014, 10:31 PM
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

typedef struct Stack{
    ListNode* top;
}Stack;

Stack* createStack(){
    Stack* newStack = (Stack*)malloc(sizeof(struct Stack*));
    newStack->top = NULL;
    return newStack;
}

int isStackEmpty(Stack* stack){
    if(stack->top == NULL){
        return 1;
    }
    return -1;
}

TreeNode* getTop(Stack* stack){
    if(isStackEmpty(stack) != 1){
        return stack->top->data;
    }
}

TreeNode* pop(Stack* stack){
    TreeNode* oldNodeToReturn = NULL;
    ListNode* oldTop = NULL;
    if(isStackEmpty(stack) != 1){
        oldNodeToReturn = stack->top->data;
        oldTop = stack->top;
        stack->top = stack->top->link;
        
        return oldNodeToReturn;
    }
    printf("\n Unable to pop an empty stack!");
    return NULL;
}

void push(Stack* stack,TreeNode* node){
    if(isStackEmpty(stack) == 1){
        stack->top = createNode(node);
        return;
    }
   
    ListNode* newNode = createNode(node);
    newNode->link = stack->top;
    stack->top = newNode;
}

void traverseStack(Stack* stack){
    if(isStackEmpty(stack) == 1){
        printf("\n Unable to traverse empty stack");
        return;
    }
    ListNode *temp = stack->top;
    while(temp != NULL){
        printf("%d",temp->data->data);
        temp = temp->link;
    }
}
int mainStackTree(int argc, char** argv) {
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
    one->left = six;
    one->right = eight;
    
    six->left = two;
    six->right = four;
    
    eight->left = nine;
    eight->right = seven;

    Stack *mystack = createStack();
    push(mystack,one);
    push(mystack,two);
    push(mystack,three);
    push(mystack,four);
    
    printf("\n top is :%d",getTop(mystack)->data);
    printf("\n");
    traverseStack(mystack);
    
    pop(mystack);
    printf("\n");
    traverseStack(mystack);
    return (EXIT_SUCCESS);
}


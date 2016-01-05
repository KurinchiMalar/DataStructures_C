/* 
 * File:   MajorityNumber_MooreVotingAlgorithm.c
 * Author: kurnagar
 *
 * Created on June 22, 2014, 11:25 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * http://www.geeksforgeeks.org/majority-element/
 */
typedef struct BST{
    int data;
    int count;
    struct BST* left;
    struct BST* right;
}bstNode;

bstNode* createBstNode(int data){
    bstNode* newNode = (bstNode*)malloc(sizeof(struct BST));
    if(newNode != NULL){
         newNode->data = data;
         newNode->count = 1;
         newNode->left = NULL;
         newNode->right = NULL;
         
         return newNode;
    }
   
}
void traverseBst(bstNode* root){
    if(root == NULL){
        return;
    }
    
    printf("%d",root->data);
    traverseBst(root->left);
    traverseBst(root->right);
}
bstNode* isExistsInBst(bstNode* root, int data){
    if (root == NULL){
        return root;
    }
    
    if(root->data == data){
        return root;
    }
    if(data < root->data){
        return isExistsInBst(root->left,data);
    }else{
        return isExistsInBst(root->right,data);
    }
    return NULL;
}
bstNode* insertInBst(bstNode* root, int data){
    if(root == NULL){
        bstNode* newNode = createBstNode(data);
        return newNode;
    }
    if(data < root->data){
        root ->left = insertInBst(root->left,data);
    }else{
        root->right = insertInBst(root->right,data);
    }
    return root;
}
int getMajorityUsingBST(int* ar,int n){
    int i = 0;
    bstNode* root = NULL;
     bstNode* ifExisting = NULL;
    for(i; i < n; i++){
        
        ifExisting = isExistsInBst(root,ar[i]);
       
        if( ifExisting != NULL){ // element already exists.
            printf("\n-----------------------------------\n");
            printf("\n (index, existingData, existingCount) : (%d, %d ,%d)\n",i,ifExisting->data,ifExisting->count);
            if(ifExisting->count > n/2){
                printf("\n ya count big");
                return ifExisting->data;
            }else{
                printf("\n ifExistingCount : %d",ifExisting->count);
                ifExisting->count++;
            } 
             printf("\n (index, existingData, NowCount) : (%d, %d ,%d)\n",i,ifExisting->data,ifExisting->count);
             printf("\n-----------------------------------\n");
        }else{
            root = insertInBst(root,ar[i]);
        }
        
        
    }
     
    printf("\n traversing....\n");
    traverseBst(root);
    if( ifExisting->count > n/2){
        return ifExisting->data;
    }
    return -1;
}
int getMajority(int* ar,int n){
    int i = 0;
    int currentCounter = 1;
    int majorityGuess = ar[0];
    for(i= 1 ; i < n; i++){
        
        if(currentCounter == 0){
            majorityGuess = ar[i];
            currentCounter = 1;
        }
        
        if(majorityGuess == ar[i]){
            currentCounter++;
        }else{
            currentCounter--;
        }
        
    }
    return majorityGuess;
}
int mainMajority(int argc, char** argv) {
    int ar[14] = {3,7,2,3,3,7,3,3,7,3,4,6,3,3};
    int* a = ar;
    //printf("\n majority element : %d",getMajority(a,13));
    printf("\n majority elem using BST : %d",getMajorityUsingBST(a,14));
    return (EXIT_SUCCESS);
}


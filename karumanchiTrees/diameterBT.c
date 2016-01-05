/* 
 * File:   diameterBT.c
 * Author: kurnagar
 *
 * Created on June 11, 2014, 12:19 PM
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
} Node;

int findMaxOfTwoNumbers(int n1,int n2){
    if(n1 >= n2){
        return n1;
    }
    return n2;
}


    
/*
int diameterNsolution(Node* root, int* height)  
{  
    int lh = 0, rh = 0;  
    int leftD = 0, rightD = 0;  
   
    if(root == NULL)  
    {  
        *height = 0;  
        return 0; 
    }  
   
    leftD = diameterNsolution(root->left, &lh);  
    rightD = diameterNsolution(root->right,&rh);  
   

    *height = findMaxOfTwoNumbers(lh, rh) + 1;  
   
    return findMaxOfTwoNumbers(lh + rh + 1, findMaxOfTwoNumbers(leftD,rightD));  
}  
*/

int findDiameterNsolution(Node* root,int* height){
    int lh = 0, rh = 0;  
    
    if(root == NULL){
        *height = 0;
        return 0;
    }

    
    int leftDia = findDiameterNsolution(root->left,&lh); // by passing address....we set value to parent from child
    int rightDia = findDiameterNsolution(root->right,&rh);
    
    *height = findMaxOfTwoNumbers(lh,rh)+1; //normal height calculation logic ... here only we set value...
    
    return findMaxOfTwoNumbers(findMaxOfTwoNumbers(leftDia,rightDia), 1+lh+rh);
    
    
    
}

int findDiameterN2solution(Node* root){
    if(root == NULL){
        return 0;
    }
/*
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
*/
    int leftDia = findDiameterN2solution(root->left);
    int rightDia = findDiameterN2solution(root->right);
    
    int leftHeight = heightOfBT(root->left);
    int rightHeight = heightOfBT(root->right);
    
    return findMaxOfTwoNumbers(leftHeight+rightHeight+1 , leftDia+rightDia);
}

int mainDiameter(int argc, char** argv) {
    
    //Node* zero = createTreeNode(0);
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
/*
    one->left = two;
    one->right = three;
*/
    int zero = 0;
    int *height = zero;
    printf("\n Height of tree is : %d", heightOfBT(one));
    printf("\n Diameter is : %d",findDiameterNsolution(one,&height));    
           
    return (EXIT_SUCCESS);
}


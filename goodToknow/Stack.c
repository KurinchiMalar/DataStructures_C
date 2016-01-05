#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}Node;
typedef struct StackStruct{
    int capacity;
    int size;
    Node** elements;
    
}Stack;

Stack* createStack(int maxNodes){
    Stack *newstack = (Stack*)malloc(sizeof(struct StackStruct*));
    if(newstack != NULL){
        newstack->capacity = maxNodes;
        newstack->size = 0;
        newstack->elements = (Node**)malloc(sizeof(struct TreeNode*)*maxNodes);
    }
    return newstack;
}
/*   after pushing element 1  at 0th index size will be 1 
 *   after  pushing element 2  at 1th index size will be 2
 *   after pushing element 3   at 2nd index size will be 3. 
 */
Node* top(Stack* s){
    if(s->size == 0){
        printf("Stack is empty - top");
        return;
    }
    return s->elements[s->size - 1];
    
}
 
void push(Stack* s, Node* n){
    if(s->size == s->capacity){
        printf("Stack is full");
        return;
    }
    s->elements[s->size] = n;
    s->size++;
}

Node* pop(Stack* s){
    if(s->size == 0){
        printf("Stack is empty - pop");
        return NULL;
    }
    Node* popResult = top(s);
    printf("%d",popResult->data);
    s->size--;
    return popResult;
}

Node* popWithoutPrint(Stack* s){
    if(s->size == 0){
        printf("Stack is empty - pop");
        return NULL;
    }
    Node* popResult = top(s);
    s->size--;
    return popResult;
}

/*int main(int argc, char** argv) {
    
    Stack *mystack = createStack(5);
    push(mystack,1);
    push(mystack,2);
    push(mystack,3);
    push(mystack,4);
    push(mystack,5);
    pop(mystack);
    pop(mystack);
    pop(mystack);
    return (EXIT_SUCCESS);
}*/


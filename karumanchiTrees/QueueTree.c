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

TreeNode* createTreeNodeNow(int data){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(struct TreeNode*));
    if(newNode != NULL){
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}
ListNode* createNode(TreeNode* d){
    ListNode* newNode = (ListNode*)malloc(sizeof(struct ListNode*));
    newNode->data = d;
    newNode->link = NULL;
    return newNode;
}

Queue* createQueue(){
    Queue* newQueue = (Queue*)malloc(sizeof(struct Queue*));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

int isQueueEmpty(Queue *queue){
    if(queue->front == NULL ){
        return 1;
    }
    return 0;
}
/*
int DeQueue(Queue* queue){
    if(isQueueEmpty(queue) == 1){
        printf("\n cannot dequeue an empty queue");
        return -1;
    }
    int temp = queue->front->data->data;
    ListNode* oldfront = queue->front;
    queue->front = queue->front->link;
    free(oldfront);
    
    return temp;
}
*/
TreeNode* DeQueue(Queue* queue){
    if(isQueueEmpty(queue) == 1){
        printf("\n cannot dequeue an empty queue");
        return -1;
    }
    TreeNode* temp = queue->front->data;
    ListNode* oldfront = queue->front;
    queue->front = queue->front->link;
    free(oldfront);
    
    return temp;
}
/*
void EnQueue(Queue *queue,int d){
    if(isQueueEmpty(queue) == 1){
        queue->front = createNode(createTreeNodeNow(d));
        queue->rear =  queue->front; 
    }else{
        queue->rear->link = createNode(createTreeNodeNow(d));
        queue->rear = queue->rear->link;
    }
   
}
*/
void EnQueue(Queue *queue,TreeNode *d){
    if(isQueueEmpty(queue) == 1){
        queue->front = createNode(d);
        queue->rear =  queue->front; 
    }else{
        queue->rear->link = createNode(d);
        queue->rear = queue->rear->link;
    }
   
}

void traverseQueue(Queue *queue){
    printf("\n Traversing....");
    if(isQueueEmpty(queue) == 1){
        printf("\n Queue is empty ...cannot traverse");
        return;
    }
    ListNode* temp = queue->front; 
    if(queue->front->link == NULL){
        printf("\n front->link is null");
    }
    while(temp != NULL){
        printf("%d",temp->data->data); //temp->data is a treeNode ...I'm printing treeNode->data
        temp = temp->link;
    }
}
/*int mainQueueTree(int argc, char** argv) {
    
    Queue *myqueue = createQueue(); 
    EnQueue(myqueue,1);
    EnQueue(myqueue,2);
    EnQueue(myqueue,3);
    EnQueue(myqueue,4);
    EnQueue(myqueue,5);
    EnQueue(myqueue,6);
    traverseQueue(myqueue);
    printf("\n%d",DeQueue(myqueue));
    printf("\n%d",DeQueue(myqueue));
    traverseQueue(myqueue);

    return (EXIT_SUCCESS);
}*/
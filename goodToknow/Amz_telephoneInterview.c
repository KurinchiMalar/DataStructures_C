/*
int getIndexOfDesiredElementInRotatedArray(int *ar, int first, int last, int k{
    while(first <= last){ // base loop
        
        // one element
        if(ar[first] ==k || (first == last && ar[first] ==k) ){
            return first;
        }
        
        if(first+1 == last){// two elements
        
            if(k == a[last]){
                return last;
            }
            
        }
        
   
      
        
        int middle = ((last-first)/2) + first;
        
        // middle can be desired k
        
        if(ar[middle] == k){
            return middle;
        }
        
        if(ar[first] <= ar[middle]){ // first half is sorted asc
            
                if(ar[first] <= k && k < ar[middle]){ // in first half
                    last = middle -1;
                }else{
                    first = middle + 1;
                }
        }else{ // second half 
            
            if(ar[middle] < k && k <=ar[last]){
                first = middle +1;
            }else{
                last = middle - 1;
            }
        }
    
    
    }
    
    return -1; // not found

}

-
---------
------------------------

typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}Node;


int areIdenticalUtility(Node* root1,Node* root2){
    
    //base case1 --> both empty --> identical true
    if(root1 == NULL && root2 == NULL){
        return 1;
    }
    
    //base case2 --> one null and the other not null --> identical false
    if(root1 == NULL || root2 == NULL{
        return -1;
    }
    
    return (root1->data == root2->data && areIdenticalUtility(root1->left,root2->left) && areIdenticalUtility(root1->right,root2->right));

}

int isSubTree(Node* root1, Node* root2){
    // base case --> NULL is definitely subtree
    if(root2 == NULL){
        return 1;
    }
    
    // tree to be compared to is NULL --> the other is not subtree
    if(root1 == NULL){
        return -1;
    }
    
    if(areIdenticalUtility(root1,root2) == 1){
        return 1;
    }
    
    return isSubTree(root1->left,root2) || isSubTree(root1->right,root2);


}































*/

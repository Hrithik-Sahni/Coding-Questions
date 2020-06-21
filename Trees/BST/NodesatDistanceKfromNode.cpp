#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
      if(left) 
          delete left;
      if(right) 
          delete right;
    }
};

void printAtDepthK(BinaryTreeNode<int>* root , int k){
    
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout << root -> data << endl;
    }
    printAtDepthK(root -> left , k - 1);
    printAtDepthK(root -> right , k - 1);
}

int printKNodes(BinaryTreeNode<int>* root, int target , int k){
   
    if (root == NULL) 
       return -1;
   
    if (root -> data == target){
      printAtDepthK(root, k);
      return 0;
   }
    
   int ld = printKNodes(root -> left, target, k);
   
    if (ld != -1){
      if (ld + 1 == k)
         cout << root -> data << endl;
     
    else
          printAtDepthK(root -> right , k - ld - 2);
      
       return 1 + ld;
   }
    
   int rd = printKNodes(root->right, target, k);
    
      if (rd != -1){
          
         if (rd + 1 == k)
             cout << root -> data << endl;
         
          else
             printAtDepthK(root -> left, k - rd - 2);
         
          return 1 + rd;
      }
    
      return -1;
   }

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code here
    int ans = printKNodes(root , node , k);
}





BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
  q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}

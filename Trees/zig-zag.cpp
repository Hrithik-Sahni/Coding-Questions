// C++ implementation of a O(n) time method for 
// Zigzag order traversal 
#include <iostream> 
#include <stack> 
using namespace std; 
  
// Binary Tree node 
struct Node { 
    int data; 
    struct Node *left, *right; 
}; 
  
// function to print the zigzag traversal 
void zizagtraversal(struct Node* root) 
{ 
    // if null then return 
    if (!root) 
        return; 
  
    // declare two stacks 
    stack<struct Node*> currentlevel; 
    stack<struct Node*> nextlevel; 
  
    // push the root 
    currentlevel.push(root); 
    while(!currentlevel.empty() || !nextlevel.empty()){
        while (!currentlevel.empty()) { 
      
            // pop out of stack 
            struct Node* temp = currentlevel.top(); 
            currentlevel.pop(); 
      
            cout << temp -> data << " ";
            
            if(temp -> left != NULL){
                nextlevel.push(temp -> left);
            }

            if(temp -> right != NULL){
                nextlevel.push(temp -> right);
            }
        }
        cout << endl;
        
        while(!nextlevel.empty()){

            struct Node* front = nextlevel.top();
            nextlevel.pop();
            cout << front -> data << " ";

            if(front -> right != NULL){
                currentlevel.push(front -> right);
            }
            if(front -> left != NULL){
                currentlevel.push(front -> left);
            }
        }
        cout << endl;
    }
} 
  
// A utility function to create a new node 
struct Node* newNode(int data) 
{ 
    struct Node* node = new struct Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
  
// driver program to test the above function 
int main() 
{ 
    // create tree 
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4); 
    cout << "ZigZag Order traversal of binary tree is \n"; 
  
    zizagtraversal(root); 
  
    return 0; 
} 
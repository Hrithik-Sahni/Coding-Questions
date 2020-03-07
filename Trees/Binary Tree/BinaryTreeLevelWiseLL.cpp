#include <vector>
#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include <stdlib.h>
using namespace std;

template<typename T>
class node{
public:
    T data;
    node<T> * next;
    node(T data){
        this->data=data;
        this->next=NULL;
    }
};


vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<node<int>*> v;
    node<int>* head = NULL;
    node<int>* tail = NULL;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    while(q.size() != 0)
    {
        int size = q.size();
            
        while(size --){
            
        BinaryTreeNode<int>* front = q.front();
        q.pop();

        
        node<int>* newNode = new node<int>(front -> data);
            
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail -> next = newNode;
                tail = newNode;
            }
            
                    
        if(front -> left != NULL)
        q.push(front -> left);
        
        if(front -> right != NULL)    
        q.push(front -> right);
            
        }
           
        v.push_back(head);
        head = NULL;
        tail = NULL;   
    }
    return v; 
}


BinaryTreeNode<int> * takeInputLevel(){

    int rootData;
    cout << "Enter the root data " << endl;
    cin >> rootData;

    if(rootData == -1)
        return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(q.size() != 0)
    {
        BinaryTreeNode<int>*front = q.front();
        q.pop();

        int leftData , rightData;

        cout << "Enter leftChild of " << front -> data << endl;
        cin >> leftData;

        if(leftData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftData);
                front -> left = child;
                q.push(child);
            }

        cout << "Enter rightChild of " << front -> data << endl;
        cin >> rightData;

        if(rightData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightData);
                front -> right = child;
                q.push(child);
            }
    }
    return root;

}


BinaryTreeNode<int> * takeInput(){

    int rootData;
    cout << "Enter the root data " << endl;
    cin >> rootData;

    if(rootData == -1)
        return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();

    root -> left = leftChild;
    root -> right = rightChild;

    return root;
}

void printTree(BinaryTreeNode<int>* root)
{
    if(root == NULL)
        return;
    
    cout << root -> data << ": ";

    if (root -> left != NULL){
        cout << "L" << root -> left -> data;
    }
    if (root -> right != NULL){
        cout << "R" << root -> right -> data;
    }
    cout << endl;

    printTree(root -> left);
    printTree(root -> right);
}

void printLL(node<int> *head)
{
    node<int> *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){

// BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
// BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
// BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
// root -> left = node1;
// root -> right = node2;

    BinaryTreeNode<int>* root = takeInputLevel();
    
    vector<node<int>*> ans = createLLForEachLevel(root);
    for(int i = 0; i < ans.size(); i++) {
        printLL(ans[i]);
    }
    
    delete root;
    return 0;
}
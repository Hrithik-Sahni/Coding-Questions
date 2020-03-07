#include <vector>
#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include <stdlib.h>
using namespace std;

int height(BinaryTreeNode<int> *root)
{
    if(root == NULL)
        return 0;
    
    int left = height(root -> left);
    int right = height(root -> right);
    
    if(left > right)
        return left + 1;
    
    return right + 1;
}

bool isBalanced(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL)
        return true;
    
    if(abs(height(root -> left) - height(root -> right)) > 1)
        return false;
    
    bool ans1 = isBalanced(root -> left);
    bool ans2 = isBalanced(root -> left);
    
    if(ans1 && ans2)
        return true;
    
    return false;  
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

int main(){

// BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
// BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
// BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
// root -> left = node1;
// root -> right = node2;

    BinaryTreeNode<int>* root = takeInputLevel();
    printTree(root);
    bool ans = isBalanced(root);
    if(ans)
        cout << "Tree is Balanced";

    else
        cout << "Tree is not Balanced";
    
    delete root;
    return 0;
}
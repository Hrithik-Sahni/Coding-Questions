#include <vector>
#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include <stdlib.h>
using namespace std;

void nodesWithoutSibling(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL)
        return;
    
    if(root -> left == NULL && root -> right != NULL)
        cout << root -> right -> data << endl;  
    
    if(root -> left != NULL && root -> right == NULL)
        cout << root -> left -> data << endl;
    
    nodesWithoutSibling(root -> left);
    nodesWithoutSibling(root -> right);
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
    nodesWithoutSibling(root);

    delete root;
    return 0;
}
#include <iostream>
using namespace std;
#include "BinaryTreeNode.h"
#include <vector>
#include<queue>

BinaryTreeNode<int>* buildTreeHelper(int* in, int* pos, int inS, int inE, int preS, int preE) {
    
    if (inS > inE) {
        return NULL;
    }

    int rootData = pos[preE];
    int rootIndex = -1;
    
    for (int i = inS; i <= inE; i++) {
        if (in[i] == rootData) {
            rootIndex = i;
            break;
        }
    }

    int lInS = inS;
    int lInE = rootIndex - 1;
    
    int lPreS = preS;
    int lPreE = lInE - lInS + lPreS;
    
    int rPreS = lPreE + 1;
    int rPreE = preE - 1;
    
    int rInS = rootIndex + 1;
    int rInE = inE;
    
    BinaryTreeNode<int>*  root = new BinaryTreeNode<int>(rootData);
    
    root->left = buildTreeHelper(in, pos, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pos, rInS, rInE, rPreS, rPreE);
    
    return root;
}

BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *preorder, int preLenght, int *inorder, int inLength) {
    // Write your code here
     return buildTreeHelper(inorder, preorder, 0, inLength - 1, 0, preLenght - 1);
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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
        queue<BinaryTreeNode<int>*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            BinaryTreeNode<int> *first = q.front();
            q.pop();
            if(first == NULL) {
                if(q.empty()) {
                    break;
                }
                cout << endl;
                q.push(NULL);
                continue;
            }
            cout << first -> data << " ";
            if(first -> left != NULL) {
                q.push(first -> left);
            }
            if(first -> right != NULL) {
                q.push(first -> right);
            }
        }
}

int main() {
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for(int i=0;i<size;i++)
        cin>>post[i];
    for(int i=0;i<size;i++)
        cin>>in[i];
    BinaryTreeNode<int>* root = getTreeFromPostorderAndInorder(post, size, in, size);
    printLevelATNewLine(root);
}
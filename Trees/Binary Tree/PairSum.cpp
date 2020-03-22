#include<iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include<algorithm>
using namespace std;

int convertToArray(BinaryTreeNode<int>* root , int* arr , int i){
    
    if(root == NULL)
        return 0;
    
    arr[i] = root -> data;
    i = i + 1;
    
    if(root -> left != NULL)
    i = convertToArray(root -> left , arr, i);
    
    if(root -> right != NULL)
    i = convertToArray(root -> right , arr, i);
    
    return i;
}

void nodesSumToS(BinaryTreeNode<int>* root, int sum){
    
    int *arr;
    int size = convertToArray(root , arr , 0);

    sort(arr ,arr + size);

    int i = 0; 
    int j = size - 1; 
    cout << i << endl << j;

    while(i < j)
    {
    	if(arr[i] + arr[j] == sum){
        	cout << arr[i] << " " << arr[j] << endl;
        	i++;
        	j--;
       }

        else if(arr[i] + arr[j] > sum){
            j--;
        }

        else if(arr[i] + arr[j] < sum){
            i++;
        }
    }
    
}
//1 2 3 -1 -1 -1 -1 
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
int main(){
	BinaryTreeNode<int>* root = takeInput();
	nodesSumToS(root , 15);
}
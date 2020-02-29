#include<vector>
#include<iostream>
#include"TreeNode.h"
using namespace std;


TreeNode<int>* takeInput(){
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter the number of children of " << rootData << endl;
    cin >> n;

    for(int i = 0 ; i < n; i++)
    {
        TreeNode<int>* child = takeInput();  //Recursive Call
        root->children.push_back(child);   //Connect with root
    }

    return root;
}
void printTree(TreeNode<int>* root)
{
    if(root == NULL)
        return;

    cout << root -> data << ":" ;
    for(int i = 0 ; i < root->children.size(); i ++)
        cout << root->children[i]->data << "," ;

    cout << endl;

    for(int i = 0 ; i < root->children.size(); i++)
        printTree(root->children[i]);
}
int main()
{
    // TreeNode<int>* root = new TreeNode<int>(1);   //Root
    // TreeNode<int>* node1 = new TreeNode<int>(2);   //Root
    // TreeNode<int>* node2 = new TreeNode<int>(3);   //Root

    // root->children.push_back(node1);
    // root->children.push_back(node2);

    TreeNode<int>* root = takeInput();
    printTree(root);
}
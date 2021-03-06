#include <vector>
#include <iostream>
#include "TreeNode.h"
#include <queue>
using namespace std;

TreeNode<int>* takeInputLevelWise()             //Printing LevelWise Using Queue
{
    int data;
    cout << "Enter root data" << endl;
    cin >> data;

    TreeNode<int>* root = new TreeNode<int>(data);

    queue<TreeNode<int>*> q;
    q.push(root);

    while(q.size() != 0)
    {
        TreeNode<int>* front = q.front();
        q.pop();

        cout << "Enter children of " << front -> data << " node" << endl;
        int numChild;
        cin >> numChild;

        for(int i = 0 ; i < numChild; i ++)
        {
            int childData;
            cout << "Enter data of " << i + 1 << " th child" << endl;
            cin >> childData;

            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            q.push(child);
        }
    }

    return root;
}

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
        cout << root->children[i]->data << ",";

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

    TreeNode<int>* root = takeInputLevelWise();

    printTree(root);
}
#include <vector>
#include <iostream>
#include "TreeNode.h"
#include <queue>
using namespace std;



TreeNode<int>* maxDataNode(TreeNode<int>* root) {

    if(root == NULL)
        return root;
    
    TreeNode<int>* maxNode = root;
   
    for(int i = 0 ; i < root -> children.size(); i++)
    {
         TreeNode<int>* maxRec = maxDataNode(root -> children[i]);
        
        if(maxNode -> data < maxRec -> data)
            maxNode = maxRec;
    }
    
    return maxNode;

}

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
            cout << "Enter data of " << i + 1 << "th child" << endl;
            cin >> childData;

            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            q.push(child);
        }
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

    TreeNode<int>* Max = maxDataNode(root)

}
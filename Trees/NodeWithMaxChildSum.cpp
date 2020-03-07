#include <iostream>
using namespace std;
#include <vector>
#include<queue>

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};

TreeNode<int>* maxSumNode(TreeNode<int> *root){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
    // Finding Sum
    int sum = 0;
    TreeNode<int>* MaxNode = root;
    
    for(int i = 0 ; i < root -> children.size() ; i ++)
    {
        sum += root -> children[i] -> data;
    }
    sum = sum + root -> data;
    
    for(int i = 0 ; i < root->children.size() ; i ++)
    {
        TreeNode<int>* maxRec = maxSumNode(root -> children[i]);
        int sum1 = 0;
        
        for(int i = 0 ; i < maxRec->children.size(); i ++)
        {
            sum1 += maxRec->children[i]-> data;
        }
        
        sum1 += maxRec -> data;
        if(sum1 > sum)
            MaxNode = maxRec;
    }
    
    return MaxNode;
    
}



TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);

    while (pendingNodes.size() != 0) {

        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        int numChild;
        cin >> numChild;

        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}



int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxSumNode(root);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
}
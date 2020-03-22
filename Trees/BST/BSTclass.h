/**************
 
 * Following is BinaryTreeNode class -
 
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
 
 * Foloowing is main function which we are using internally

int main(){
    BST *tree = new BST();
    int choice, input;
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->deleteData(input);
                break;
            case 3:
                cin >> input;
                if(tree->hasData(input)) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
                break;
            default:
                tree->printTree();
                return 0;
                break;
        }
    }
}
*******************/

#include<climits>
class BST {
	// Complete this class
    BinaryTreeNode<int>* root;
    
    private:
        BinaryTreeNode<int>* Min(BinaryTreeNode<int>* node){
            
            if(node == NULL){
                return NULL;
            }
            
            BinaryTreeNode<int>* mini = Min(node -> left);
            if(mini -> data < node -> data)
            	return mini;
            return node;
        }
    
        bool hasHelper(BinaryTreeNode<int>* root1 , int data){
            if(root1 == NULL){
                return false;
            }
            if(root1 -> data == data){
                return true;
            }
            if(data > root1 -> data)
            {
                return(hasHelper(root1 -> right , data));
            }
            return(hasHelper(root1 -> left , data));
        }
    
        void printTreehelper(BinaryTreeNode<int>* root1){
        if(root1 == NULL)
            return;
    
        cout << root1 -> data << ":";

        if (root1 -> left != NULL){   
            cout << "L:" << root1 -> left -> data <<",";
        }
        if (root1 -> right != NULL){
            cout << "R:" << root1 -> right -> data;
        }
        cout << endl;

        printTreehelper(root1 -> left);
        printTreehelper(root1 -> right);
        }
        
        BinaryTreeNode<int>* insertHelp( BinaryTreeNode<int>* node , int data){
            
            if(node == NULL){
                 BinaryTreeNode<int>* newNode = new  BinaryTreeNode<int>(data);
                 return newNode;
            }
            
            if(data < node -> data){
                 BinaryTreeNode<int>*left1 = insertHelp(node -> left , data);
                 node -> left = left1;    
                 return node;
            } 
            
            BinaryTreeNode<int>*right1 = insertHelp(node -> right , data);
            node -> right = right1;
            return node;
        }
        
        BinaryTreeNode<int>* deleteHelper(BinaryTreeNode<int>*node , int data){
            if(node == NULL){
                return NULL;
            }
            if(data > node -> data){
                node -> right = deleteHelper(node -> right , data);
                return node;
            }
            if(data < node -> data){
                node -> left = deleteHelper(node -> left , data);
                return node;
            }
            else{
                if(node -> left == NULL && node -> right == NULL){
                	delete node;
                    return NULL;
                }

                if(node -> left == NULL && node -> right != NULL){
                    return node -> right;
                }

                if(node -> left != NULL && node -> right == NULL){
                    return node -> left;
                }

                BinaryTreeNode<int>* miniRight = Min(node -> right);
                node -> data = miniRight -> data;
                node -> right = deleteHelper(miniRight -> data , node -> right);
                return node;

                }
        }
    public:
        BST(){
            root = NULL;
        }
        bool hasData(int data){
            return (hasHelper(root , data));
        }
    
        void printTree(){
            printTreehelper(root);
        }
        
        void insert(int data){
            root = insertHelp(root , data);
        }
    
        void deleteData(int data){
             root = deleteHelper(root , data);   
        }
    
};

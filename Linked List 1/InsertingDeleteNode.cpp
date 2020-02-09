#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

Node*takeInput()
{
	int data;
	cin >> data;
	Node *head = NULL;
	Node *tail = NULL;
	while(data != -1)
	{
		Node *newNode = new Node(data);
		if(head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else{
		// 	Node*temp = head;
		// 	while(temp -> next != NULL)
		// 	{
		// 		temp = temp -> next;
		// 	}
		// 	temp -> next = newNode; 
		// 
			//Better Solution
			tail -> next = newNode;
			tail = tail -> next;
		}
		cin >> data;
	}
	return head;
}
void print(Node *head){
    Node *temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

Node* insertNode(Node *head , int i , int data)
{
	Node * newNode = new Node(data);
	int count = 0 ;
	Node*temp = head;

	if(i == 0)
	{
		newNode -> next = head;
		head = newNode;
		return head;
	}
	while(temp !=NULL && count < i - 1)
	{
		temp = temp -> next;
		count ++;
	}
	if(temp != NULL)
	{
	Node*t1 = temp -> next;
	temp-> next = newNode;
	newNode -> next = t1;
	//OR
	// newNode->next = temp->next;
	// temp->next = newNode;
	return head;
	}
}

Node* deleteNode(Node *head, int i) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    Node * temp = head;
    if(i == 0)
    {
        head = head -> next;
        delete temp;
        return head;
    }
    int count = 0;
    while(temp != NULL && count < i - 1)
    {
        temp = temp -> next;
        count ++;
    }
    if(temp != NULL)
    {
        Node* t1 = temp -> next;
        temp -> next = t1 -> next;
        delete t1;
        return head;
    }
}


int main(){
	
	int pos , data , posd;
	cout << "Enter elements in LinkedList" << endl;
	Node*head = takeInput();
	print(head);
	cout <<"Enter Index " << endl;
	cin >> pos;
	cout <<"Enter Data " << endl;
    cin >> data;
    head = insertNode(head , pos , data);
    print(head);
    cout << "Enter Index to be deleted" << endl;
    cin >> posd;
    head = deleteNode(head , posd);
    print(head);

    return 0;
}

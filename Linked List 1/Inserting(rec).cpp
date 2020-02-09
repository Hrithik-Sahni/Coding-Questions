#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;
#include "solution.h"

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}


Node* insertNodeRec(Node *head, int i, int data) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    if(head == NULL)
    {
        if(i == 0)
        {
            Node * newNode = new Node(data);
            newNode -> next = head;
            head = newNode;
            return head;
        }
        else
        return head;
    }
    
    if(i == 0)
    {
        Node * newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
        return head;
    }
    
    Node*x = insertNodeRec(head -> next , i - 1, data);
    head -> next = x;
    return head;
    
}

Node* deleteNodeRec(Node *head, int i) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    if(head == NULL)
    {
        return head;
    }
    if(i == 0)
    {
        delete head;
        head = head -> next;
        return head;
    }
    Node* x = deleteNodeRec(head -> next , i - 1);
    head -> next = x;
    return head;
    
}

int main() {
    Node *head = takeinput();
    int pos, data;
    cin >> pos >> data;
    head = insertNodeRec(head, pos, data);
    print(head);
    return 0;
}
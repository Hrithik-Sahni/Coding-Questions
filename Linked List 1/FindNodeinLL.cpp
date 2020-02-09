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
// #include "Solution.h"

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

int indexOfNIter(Node *head, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    Node*temp = head;
    int index = 0;
    while(temp !=NULL && n != temp -> data)
    {
        index ++;
        temp = temp -> next;
    }
    if(temp == NULL)
        return -1;
    else 
        return index;
    
}


int main() {
    Node *head = takeinput();
    int n;
    cin >> n;
    cout << indexOfNIter(head, n);
    
}

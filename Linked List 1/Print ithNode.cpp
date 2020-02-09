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

void printIthNode(Node *head, int i) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
    Node*temp = head;
    int flag = 0;
    for(int k = 0 ; k < i; k++)
    {
        temp = temp -> next;
        if(temp -> next == NULL)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1) {
        cout << "";
    }
    else{
     cout << temp -> data;
    }

}


int main() {
    Node *head = takeinput();
    int pos;
    cin >> pos;
    printIthNode(head, pos);
    return 0;
}



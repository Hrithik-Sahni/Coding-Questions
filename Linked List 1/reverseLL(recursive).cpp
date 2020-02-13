#include <iostream>
using namespace std;

// Reverse Linked List  a. Using recursion  b. Without using recursion

class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
node *reverse_linked_list_rec(node *head)
{
    //write your recursive code here
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    node*x = reverse_linked_list_rec(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    
    return x; 
}


node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node* head=takeinput();
    head=reverse_linked_list_rec(head);
    print(head);
    return 0;
}




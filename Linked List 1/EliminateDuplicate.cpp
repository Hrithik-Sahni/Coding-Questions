// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/

//Eliminate duplicates from a sorted linked list
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
using namespace std;
// #include "solution.h"

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



node*eliminate_duplicate(node *head){
    //write your code here
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    node*x = eliminate_duplicate(head -> next);
    head -> next = x;
    
    node * temp = head -> next;
    if(head->data == temp-> data && temp != NULL)
    {
        node*t1 = head -> next;
        head->next = t1 -> next;
        delete t1;
        return head;    
    }

    return head;
}


int main(){
    node* head=takeinput();
    head=eliminate_duplicate(head);
    print(head);
    return 0;
}


// Print a given linked list in reverse order. Tail first. You cant change any pointer in the linked list
#include <iostream>
#include<bits/stdc++.h>
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

pair<node* , node*> revhelper(node* head)
{
    if(head == NULL || head -> next == NULL)
    {
        pair <node* , node*>p1;
        p1.first = head;
        p1.second = head;
        return p1;
    }

    pair <node* , node*> smallAns = revhelper(head -> next);
    smallAns.second -> next = head;
    head -> next = NULL;
    smallAns.second = head;
    return smallAns;
}

node*rev(node*head)
{
    //write your code here
    pair<node* , node*> p1 = revhelper(head);
    return p1.first;

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

int main()
{
    node*head=takeinput();
    node* revhead = rev(head);
    print(revhead);
    return 0;
}




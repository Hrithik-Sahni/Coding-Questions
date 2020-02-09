//head is the head of the linked list and n is  how many element you want to append from the last to the front
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


//Append the last n elements of a linked list to the front
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
}


node* append_LinkedList(node* head,int n)
{
    //write your code here
    node*temp = head;
    node*t1 = head;
    int count = 1 ,len; 
    while(temp->next != NULL)
    {    
        count++;
        temp = temp -> next;
    }
    len = count - n - 1;
    temp -> next = head;
    while(len != 0)
    {
        t1 = t1 -> next;
        len --;
    }
    head = t1 -> next;
    t1 -> next = NULL;
    
    return head;
    
}
int main()
{
    node* head=takeinput();
    int n;
    cin>>n;
    head=append_LinkedList(head,n);
    print(head);
    return 0;
}

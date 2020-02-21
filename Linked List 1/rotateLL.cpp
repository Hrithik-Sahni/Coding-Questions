//Arrange elements in a Linked List such that all even numbers are placed after odd numbers
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
node* head=NULL,*tail=NULL;
using namespace std;
// #include "solution.h"
node* takeinput(){
    int data;
    cin>>data;
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

node*rotated(node* head , int k)
{
    if(head == NULL)
        return head;
    node*temp = head;
    node*t1 = head;
    int ctr = 0;
    while(temp -> next != NULL)
    {
        // k--;
        temp = temp-> next;
        ctr++;
    }
    if(k >= ctr + 1)
        return head;
    temp -> next = head;
    while(k != 1)
    {
        t1= t1->next;
        k--;
    }
    head = t1->next;
    t1->next = NULL;
    return head;


}
int main()
{
    node*head=takeinput();
    print(head);
    // head=arrange_LinkedList(head);
    head = rotated(head , 1);
    print(head);
    return 0;
}
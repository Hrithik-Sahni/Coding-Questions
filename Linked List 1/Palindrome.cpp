//Check if a linked list is a palindrome
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


node*reverseLL(node*head)
{
    if(head == NULL || head->next == NULL)
        return head;
    
    node*t1 = reverseLL(head -> next);
    
    head->next->next = head;
    head -> next = NULL;
    return t1; 
    
}
bool check_palindrome(node* head)
{
    //write your code here
    node*temp = head;
    node*temp1 = head;
    node*temp2 = head;
    int count = 0 , flag =0;
    
    while(temp != NULL)
    {
        count++;
        temp = temp -> next;
    }
    count = count/2;
    
    while(count != 1)
    {
        count--;
        temp1 = temp1 -> next;
    }
    
    node*x = reverseLL(temp1->next);
    temp1-> next = NULL;
    
    while(temp2!=NULL || x!=NULL)
    {
        if(temp2->data != x->data)
        {
            flag = 1;
            break;
        }
        temp2 = temp2->next;
        x = x-> next;
    }
    if(flag)
        return false;
    else
        return true;
}


int main()
{
    node*head=takeinput();
    bool ans=check_palindrome(head);
    if(ans)
        cout<<"true";
    else 
        cout << "false";
    return 0;
}
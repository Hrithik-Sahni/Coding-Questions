#include <iostream>
#include <math.h>
#include <cstdlib>

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

node* swap_nodes(node *head,int i,int j)
{
    //write your code here
    if(head == NULL || head -> next == NULL)
        return head;
    
    int ctr1 = 0, ctr2 = 0; 
    node*curr1 = head;
    node*curr2 = head;
    
    node* prev1 = NULL;
    node* prev2 = NULL;
    
    while(ctr1 != i)
    {
        prev1 = curr1;
        curr1 = curr1 -> next;
        ctr1 ++;
    }
    
    while(ctr2 != j)
    {
        prev2 = curr2;
        curr2 = curr2 -> next;
        ctr2 ++;
    }
        
    if((i == 0 || j == 0) && abs(i - j) == 1 )
    {
        if(i == 0)
        {
            curr1 -> next = curr2 -> next;
            curr2 -> next = curr1;
            head = curr2;
            
            return head;
        }
        
        else
        {
            curr2 -> next = curr1 -> next;
            curr1 -> next = curr2;
            head = curr1;
            
            return head; 
        }
    }
    
    if(i == 0 || j == 0)
    {
       if(i == 0)
       {
           prev2 -> next = curr1; 
            node* x = curr1 -> next;
           curr1 -> next = curr2 -> next;
           curr2 -> next = x;
           head = curr2;
           
        return head;
       
       }
        else
        {
           prev1 -> next = curr2; 
            node* x = curr2 -> next;
           curr2 -> next = curr1 -> next;
           curr1 -> next = x;
           head = curr2;
        return head;   
        }
    }
    
    
    if(abs(i - j) == 1)
    {
        if(i < j)
        {
            prev1 -> next = curr2;
            curr1 -> next = curr2 -> next;
            curr2 -> next = curr1;
            
            return head;
        }
        else
        {
            prev2 -> next = curr1;
            curr2 -> next = curr1 -> next;
            curr1 -> next = curr2;
            
            return head;
            
        }
    }
    

    
    if(i < j)
    {
        prev1 -> next = curr2;
        node* nex1 = curr1 -> next;
        curr1 -> next = curr2 -> next;
        curr2 -> next = nex1;
        nex1 -> next = curr1;
        
            return head;
    }
    

    else
    {
        prev2 -> next = curr1;
        node* nex2 = curr2 -> next;
        curr2 -> next = curr1 -> next;
        curr1 -> next = nex2;
        nex2 -> next = curr2; 
        
            return head;
    }  

}

//Implement code to swap two elements of a Linked List. You need to swap the nodes not the data


int main()
{
    int i,j;
    node* head =takeinput();
    cin>>i;
    cin>>j;
    head=swap_nodes(head,i,j);
    print(head);
    return 0;
}
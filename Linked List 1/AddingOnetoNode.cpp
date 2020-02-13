#include<iostream>
#include<conio.h>
using namespace std;

struct node{
int data;
node *next;
};
node *head=new node;
int flag;

int main()
{ 
    head=NULL;
    void insertion(int x);
    void disp();
    void reversing();
    void add();
     insertion(4);
     insertion(3);
     insertion(2);
     insertion(1);
     disp();
     reversing();
     add();
     reversing();
     // if (flag==1)
     //    insertion(1);
     if(head -> data == 0)
     {
        insertion(1);
     }
     disp();

    getch();
    return 0;

}
void insertion(int x){
node *temp=new node;
temp->data=x;
if (head==NULL)
{
    head=temp;
    temp->next=NULL;
    }
    else
     {

        temp->next=head;
        head=temp;


}
}

void disp(){
 node *temp;
 temp=head;
 while(temp!=NULL)
{
    cout<<temp->data<<" ";
    temp=temp->next;
}
cout<<"\n";
}

void reversing()
{
    node *curr,*prev,*next;
    curr=head;
    prev=NULL;
    next=NULL;
    while(curr!=NULL){
     next=curr->next;
     curr->next=prev;
     prev=curr;
     curr=next;
    }
    head=prev;
}

void add()
{   node *temp;
    temp=head;  
    // flag=0;

    temp -> data = temp -> data + 1;
    while (temp -> data == 10 && temp -> next != NULL)
    {
        temp -> data = 0;
        temp -> next -> data += 1;
        temp = temp -> next;
    }
    if(temp -> data == 10)
    {
        temp -> data = 0;
    }

}
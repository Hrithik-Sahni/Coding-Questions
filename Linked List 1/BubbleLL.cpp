int len(node* head)
{
    node* temp = head;
    int ctr = 0;
    while(temp != NULL)
    {
        temp = temp -> next;
        ctr ++;
    }
    return ctr;
}
node* bubble_sort_LinkedList_itr(node* head)
{
   
    int l = len(head);
    for (int i = 0; i < l; i++)
    {
        node* prev = NULL;
        node* curr = head;
        
        while(curr -> next != NULL)
        {
        
            if(curr -> data > curr -> next -> data)
            {
                if(prev != NULL)
                {
                    node* nex = curr -> next;
                    curr->next->next = curr;
                    prev->next = curr->next;
                    curr->next = nex;
                    prev = prev->next;
                
                }
                else{
                    head = curr -> next;
                    curr -> next = head -> next;
                    head -> next = curr;
                    prev = head;
                }

            }
            else
            {
                prev = curr;
            curr = curr -> next;
           // prev = prev -> next;
            } 
        }
        
    }
    return head;
}


//head is the head of the linked list
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
int len(node* head)
{
    node* temp = head;
    int ctr = 0;
    while(temp != NULL)
    {
        temp = temp -> next;
        ctr ++;
    }
    return ctr;
}
node* bubble_sort_LinkedList_itr(node* head)
{
    //write your code here
    if(head == NULL || head -> next == NULL)
        return head;
    
    
    for (int i = 0; i < len(head); i++)
    {
        node* prev = NULL;
        node* curr = head;
        
        while(curr -> next != NULL)
        {
            if(curr -> data > curr -> next -> data)
            {
                if(prev == NULL)
                {
                    node*nex = curr -> next;
                    head = nex;
                    prev = nex;
                    curr -> next = nex -> next;
                    nex -> next = curr;
                }
                else{
                    node*nex = curr -> next;
                    prev -> next = curr -> next;
                    curr -> next = nex -> next;
                    nex -> next = curr;
                    prev = prev -> next;
                }

            }
            else
            {
                prev = curr;
                curr = curr -> next;
            }
        }
        
    }
    return head;
}

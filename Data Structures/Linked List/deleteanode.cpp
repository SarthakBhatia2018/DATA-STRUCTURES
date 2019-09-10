#include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node* next;
};

node* newnode(int data)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
node* deletenode(node *head,int data)
{
     node *ptr=head,*curr=head->next;
     if(ptr->data==data)
     {
        ptr->next=NULL;
        free(ptr);
        return curr;
     }

     while(curr)
        {
            if(curr->data==data)
            {
                ptr->next=curr->next;
                curr->next=NULL;
                free(curr);
                return head;
            }
            curr=curr->next;
            ptr=ptr->next;
        }
      cout<<"\n"<<data<<" Not Found is the Linked List";
      return head;
}
void deletenode2(node **head_ref,int data)
{
    node *ptr=*head_ref,*temp;
    if(ptr!=NULL and ptr->data==data)
    {
        *head_ref=ptr->next;
        free(ptr);
        return;
    }
    while(ptr && ptr->data!=data)
    {
       temp=ptr;
       ptr=ptr->next;
    }
    if(ptr==NULL)
    {
        cout<<"\n"<<data<<" Not Found is the Linked List";
        return;
    }
    temp->next=ptr->next;
    free(temp);
}

void deletenodeatposition(node **head,int pos)
{
    node *temp=*head,*ptr;
    if(pos==0)
    {
        *head=temp->next;
        free(temp);
        return;
    }
    while(pos-1 && temp)
    {
        temp=temp->next;
        pos--;
    }
    if(temp!=(*head))
    {
     ptr=temp->next;
    temp->next=temp->next->next;
    free(ptr);
    return;
    }
    cout<<"\nposition does not exist";
}

void printll(node *head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{
     node* head=newnode(1);
     head->next=newnode(2);
     head->next->next=newnode(3);
     head->next->next->next=newnode(4);
     head->next->next->next->next=newnode(7);
     cout<<"BEFORE:\n";
     printll(head);
     deletenodeatposition(&head,9);
     cout<<"\nAFTER:\n";
     printll(head);
//    node->next->next->next->next=newnode(5);
//    node->next->next->next->next->next=newnode(6);
//    printll(node);
//    cout<<"\n";
//    push(&node,7);
//    printll(node);
    return 0;
}

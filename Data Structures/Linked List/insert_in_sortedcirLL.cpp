#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node  *next;
};

node* newnode(int data)
{
    node *ptr=(node*)malloc(sizeof(node));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}
node *insertscl(node *head,int data)
{
    node *new_node=newnode(data),*curr=head->next,*prev=head;
//    cout<<"\t"<<new_node->data;
    if(!head)
        {
          new_node->next=new_node;
          head=new_node;
//          cout<<new_node->data;
          return head;
        }
    if(data < head->data)
        {
           new_node->next=head;
           while(curr->next != head)
             curr=curr->next;
           head=new_node;
           curr->next=head;
           return head;
        }
    while(true)
    {
        if(data < curr->data)
        {
            prev->next=new_node;
            new_node->next=curr;
            return head;
        }
        else if(curr->next==head)
        {
            curr->next=new_node;
            new_node->next=head;
            return head;
        }
        else
        {
            curr=curr->next;
            prev=prev->next;
        }
    }
}
void sortedInsert(node** head_ref, int data)
{
    node *new_node=newnode(data);
    node* current = *head_ref;

    // Case 1 of the above algo
    if (current == NULL)
    {
        new_node->next = new_node;
        *head_ref = new_node;
    }

    // Case 2 of the above algo
    else if (current->data >= new_node->data)
    {
        /* If value is smaller than head's value then
        we need to change next of last node */
        while(current->next != *head_ref)
            current = current->next;
        current->next = new_node;
        new_node->next = *head_ref;
        *head_ref = new_node;
    }

    // Case 3 of the above algo
    else
    {
        /* Locate the node before the point of insertion */
        while (current->next!= *head_ref && current->next->data < new_node->data)
        current = current->next;

        new_node->next = current->next;
        current->next = new_node;
    }
}

//void insert_circularll(node *head,int data)
//{
//    node *new_node=newnode(data),*curr=head;
//    if(!head)
//    {
//        new_node->next=new_node;
//        return;
//    }
//    else if(curr!=head && curr->data>=data)
//    {
//        new_node->next=head;
//        head
//    }
//
//}


void printCLL(node *head)
{
    node *ptr=head;
    while(true)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
        if(ptr==head)
            return;
    }
}
int main()
{
    node *head=newnode(1);
    node *ptr=head;
    head->next=newnode(2);
    head->next->next=newnode(3);
    head->next->next->next=newnode(4);
    head->next->next->next->next=newnode(6);
    head->next->next->next->next->next=ptr;
    cout<<"BEFORE:\n";
    printCLL(head);
    cout<<"\nAFTER\n";
    head=insertscl(head,5);
    printCLL(head);
    cout<<"\nAFTER\n";
    head=insertscl(head,10);
    printCLL(head);
    cout<<"\nAFTER\n";
    head=insertscl(head,11);
    printCLL(head);
    cout<<"\nAFTER\n";
    head=insertscl(head,6);
    printCLL(head);
    cout<<"\nAFTER\n";
    head=insertscl(head,0);
    printCLL(head);
    return 0;
}



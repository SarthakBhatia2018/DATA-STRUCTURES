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
void printll(node *head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
node* push(node* head,int data)
{
  node*ptr=head;
  node *newnode=(node*)malloc(sizeof(node));
  newnode->data=data;
  while(ptr->next)
  {
        ptr=ptr->next;
  }
  ptr->next=newnode;
  newnode->next=NULL;
  return head;
}

node* reverse(node*head)
{
 node*current=head,*prev=NULL,*nextnode;
 while(current)
 {
     nextnode=current->next;
     current->next=prev;
     prev=current;
     current=nextnode;
 }
 return prev;
}
node* addoneB(node* head)
{
    node *ptr=head,*temp;
    while(ptr)
    {
        if(ptr->data<9)
            {
                ptr->data=ptr->data+1;
                return head;
            }
        else
            {
                ptr->data=0;
                temp=ptr;
                ptr=ptr->next;
            }
    }
    ptr=(node *)malloc(sizeof(node));
    ptr->data=1;
    ptr->next=NULL;
    temp->next=ptr;
    return head;
}
node* addoneA(node* head)
{
    head=reverse(head);
    head=addoneB(head);
    return reverse(head);
}


int main()
{
    int n,x[20],i=1;
    cout <<"Enter the length of the number";
    cin>>n;
    node* head=NULL,*ptr;
    cout<<"\nEnter the number(with spaces)";
    cin>>x[0];
    head=newnode(x[0]);
    ptr=head;
    while(n-1)
    {
        --n;
        cin>>x[i];
        head->next=newnode(x[i]);
        i+=1;
    }
    head=ptr;
//    node* head=newnode(1);
//    head->next=newnode(2);
//    head->next->next=newnode(3);
//    head->next->next->next=newnode(4);
    cout<<"BEFORE:\n";
    printll(head);
    head=addoneA(head);
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

#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
int c=0;
//node* pointer;
node *newnode(int data)
{
//    node *new_node=(node*)malloc(sizeof(node));
    node *new_node=new node;
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}
void push(node **head_ref,int data)
{
    node *new_node=newnode(data);
    new_node->next=*head_ref;
    *head_ref=new_node;
}
void printLinkedList(node *head)
{
    node *ptr=head;
//    count=0;
    if(!ptr)
    {
        cout<<"Linked List Empty";
        return;
    }
    while(ptr)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
//        count+=1;
    }
}
int count(node *head)
{
    int count=0;
    while(head)
    {
        count+=1;
        head=head->next;
    }
    return count;
}
node *returnnthnoode(node *head,int n)
{
    node *pnode=NULL,*temp=head;
    for(int i=1;i<n;++i)
    {
        if(temp)
        temp=temp->next;
    }
    while(temp)
    {
        if(!pnode)
            pnode=head;
        else
            pnode=pnode->next;
        temp=temp->next;
    }
    if(pnode)
        return pnode;
    return NULL;
}
//node* returnnthnoderecur(node *head,int n)
//{
//    if(head)
//    {
//        head=head->next;
//        returnnthnoderecur(head->next,n);
//        c++;
//        if(c==n)
//        pointer=head;
//}
//return pointer;
//}
node* delete_nth_node(node *head,int n)
{
    node* ptr=head;
    int p=count(head)-n;
    cout<<"\n";
    if(p-1)
    {
        while(p-1)
    {
        ptr=ptr->next;
        p-=1;
    }
    node *temp=ptr->next;
    ptr->next=temp->next;
    temp->next=NULL;
    return head;
    }
    cout<<"\nLess number of nodes";
}
int main()
{
    node *head=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    push(&head,6);
    printLinkedList(head);
//    head=delete_nth_node(head,2);
//    head=delete_nth_node(head,3);
    node* ptr=returnnthnoode(head,4);
    if(ptr)
    cout<<"\n\n\n"<<ptr->data;
    else
        cout<<"\n\n\n"<<"Node not possible";
    return 0;
}

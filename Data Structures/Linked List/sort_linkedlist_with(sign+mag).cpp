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
/* 1      -2      -3       4        -5*/

node* sortll(node* head)
{
    if(!head) return head;
    if(!(head->next)) return head;
    node *current=head->next,*prev=head;
    while(current)
    {
        if(current->data<prev->data)
        {
//            node *temp=current;
            prev->next=current->next;
            current->next=head;
            head=current;
        }
        else
        {
            prev=prev->next;
        }
//        if(!prev)
//            return head;
        current=prev->next;
    }
    return head;
}
void alternate(node *ptr)
{
//    node *ptr=head;
//    ptr=ptr->next;
    cout<<"\n";
    while(ptr)
    {
        cout<<ptr->data<<" ";
        if(ptr->next)
            ptr=ptr->next->next;
        else
            return;
    }
//    cout<<"\n";
}
void alternate2(node *head)
{
    cout<<"\n";
 int count=1;
 while(head)
 {
     if(count%2==0)
        cout<<head->data<<" ";
     count+=1;
     head=head->next;
 }
}
void deletealternate(node *head)
{
    if(!head) return;
    node *ptr=head->next,*prev=head;
    while(prev && ptr)
    {
        prev->next=ptr->next;
        free(ptr);
        prev=prev->next;
        if(prev)
           ptr=prev->next;
    }
//    return head;
}
//int c=0;
void recusive_del_alt(node *head)
{
    if(!head) return;
    node *Node=head->next;
    if(!Node) return;
    head->next=Node->next;
    free(Node);
    recusive_del_alt(head->next);
}

int main()
{
    node* head=newnode(-1);
    head->next=newnode(-2);
    head->next->next=newnode(-3);
    head->next->next->next=newnode(4);
    head->next->next->next->next=newnode(-5);
    head->next->next->next->next->next=newnode(11);
    head->next->next->next->next->next->next=newnode(-19);
    head->next->next->next->next->next->next->next=newnode(11110);
    cout<<"BEFORE:\n";
    printll(head);
    cout<<"\nAlternate:";
    alternate(head);
    head=sortll(head);
    cout<<"\nAFTER:\n";
    printll(head);
    cout<<"\nDeleting alternate nodes:\n";
    recusive_del_alt(head);
    printll(head);
    return 0;
}

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node *next=NULL;
};
node *top=NULL;

node* newdata(int data)
{
    node *new_node=(node*) malloc(sizeof(node));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}
int peek()
{
    if(top==NULL)
    {
        cout<<"Stack Empty,Can't peek!";
        exit(1);
    }
    else
        return top->data;
}
int isEmpty()
{
    return (top==NULL);
}
void push(int data)
{
  node *ptr=newdata(data);
  if(!ptr)
 {
    cout<<"Heap overflowed";
    exit(1);
 }
 ptr->next=top;
 top=ptr;
}
void pop()
{
    if(!top)
    {
        cout<<"Stack Underflow";
        exit(1);
    }
    else
    {
        node *temp=top;
        top=top->next;
        temp->next=NULL;
        free(temp);
    }
}
void display()
{
    if(!top)
    {
        cout<<"\nNo data to display in the stack";
    }
    else
    {
        node* temp =top;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    cout<<peek();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    cout<<peek();
    if(isEmpty())
    {
    push(11);
    display();
    }
    return 0;
}

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
//node* sort012(node *head)
//{
//    if(!head) return head;
//    node *ptr0,*ptr1,*ptr2,*headptr0,*headptr1,*headptr2,*curr=head,*temp;
//    while(curr)
//    {
//
////        cout<<curr->data;
////        switch(curr->data)
////        {
////            case 0: cout<<0;
//            if(curr->data==0)
//            {
//
//                    if(!ptr0)
//                        {
//                        ptr0=curr;
//                        headptr0=ptr0;
//                        }
//                    else
//                     {
//                        ptr0->next=curr;
//                        ptr0=ptr0->next;
//                        }
//
//            }
////              break;
////            case 1:cout<<1;
//                 else if(curr->data==1)
//                 {
//               if(!ptr1)
//                        { ptr1=curr;
//                        headptr1=ptr1;
//                        }
//                    else
//                        {
//                            ptr1->next=curr;
//                            ptr1=ptr1->next;
//                            }
//
//                 }
////                    break;
////            case 2: cout<<1;
//                  else if(curr->data==2)
//                  {
//                if(!ptr2)
//                        {
//                            ptr2=curr;
//                            headptr2=ptr2;
//                        }
//                    else
//                            {
//                                ptr2->next=curr;
//                                ptr2=ptr2->next;
//                            }
//        }
//
////        cout<<"Break hora!!";
//     temp=curr;
//     curr=curr->next;
//     temp->next=NULL;
//     }
////     cout<<"\n"<<headptr0->data;
//    ptr0->next=headptr1;
//    ptr1->next=headptr2;
////    head=headptr0;
//    printll(headptr0);
//    return headptr0;
//}


void printalternate(node *head)
{
    if(!head) return;
    cout<<head->data<<" ";
    if(head->next)
        printalternate(head->next->next);
}
void printalternate2(node *head,bool isodd=false)
{
    if(!head)
        return;
    if(isodd)
        cout<<head->data<<" ";
    printalternate2(head->next,!isodd);
}
int main()
{
    node* head=newnode(1);
    head->next=newnode(2);
    head->next->next=newnode(2);
    head->next->next->next=newnode(0);
    head->next->next->next->next=newnode(0);
    head->next->next->next->next->next=newnode(1);
    head->next->next->next->next->next->next=newnode(2);
    head->next->next->next->next->next->next->next=newnode(0);
    cout<<"BEFORE:\n";
    printll(head);
//    head=sort012(head);
    cout<<"\nAFTER:\n";
    printalternate2(head);
    return 0;
}

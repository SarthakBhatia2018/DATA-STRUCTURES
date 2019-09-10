#include<iostream>
#include<stdlib.h>

using namespace std;
//struct node
//{
//    int data;
//    node *next;
//};
//
//node *newnode(int data)
//{
////    node *new_node=(node*)malloc(sizeof(node));
//    node *new_node=new node;
//    new_node->data=data;
//    new_node->next=NULL;
//    return new_node;
//}
int main()
{
    int *p=(int*)malloc(sizeof(int)*5);
//      int *p=new int(5);
    cout<<"Enter the inputs\n";
    for(int i=0;i<5;++i)
    {
        cin>>p[i];
    }
    cout<<"\nThe output is :\n";
    for(int i=0;i<5;++i)
    {
        cout<<p[i]<<" ";
    }
    free(p);
    for(int i=0;i<5;++i)
    {
        cout<<p[i]<<" ";
    }
    return 0;
}

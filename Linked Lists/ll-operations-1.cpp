#include<iostream>
using namespace std;
struct node
{
       int data;
       node *next;
}; 
void printlist(node *l)
{
     cout<<"  the list contains: \n";
     while(l!=NULL)
     {
                   cout<<l->data<<endl;
                   l=l->next;
     }
}
void add(node *l,int k)
{
     while(l->next!=NULL)
     {
                   l=l->next;
     }
     l->next=(node*)new node;
     l->next->data=k;
     l->next->next=NULL;
}
void search(node *l,int k)
{
     if(l->data!=k)
     {
                       l=l->next;
                       search(l,k);
     }
     if(l->data==k)
     {
                   cout<<"got it\n";
     }
}
main()
{
      node *l1,*h1;
      int a,b,c,d,e,f,k;
      h1=(node*)new node;
      cout<<"enter the no.s \n";
      cin>>a;
      h1->data=a;
      h1->next=NULL;
      l1=h1;
      cout<<"enter the no. of numbers u want to be in the lists \n";
      cin>>c;
      cout<<"enter them in list1\n";
      for(int i=0;i<c;i++)
      {
              cin>>e;
              add(l1,e);
      }
      cout<<"search \n";
      cin>>k;
      search(l1,k);
      system("pause");
}

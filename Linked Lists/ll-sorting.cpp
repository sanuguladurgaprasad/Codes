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
void ff(node *l,node *h)
{
     node *o;
     o=h;
while(o!=NULL)
      {             
                     l=h;
                     while(l->next!=NULL)
                     {
                                    if((l->data)>(l->next->data))
                                    {
                                                                 int t;
                                                               t=l->data;
                                                               l->data=l->next->data;
                                                               l->next->data=t;
                                    }
                                    l=l->next;
                     }
                    o=o->next;
      }
}
main()
{
      int a,b,c,d,e,p,t;
      node *h1,*l1,*o;
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
              printlist(l1);ff(l1,h1);
              printlist(l1);
              cout<<"   ";
      }
      cout<<endl;
      printlist(l1);cout<<"\n";
      ff(l1,h1);
     /* while(o!=NULL)
      {             
                     l1=h1;
                     while(l1->next!=NULL)
                     {
                                    if((l1->data)>(l1->next->data))
                                    {
                                                               t=l1->data;
                                                               l1->data=l1->next->data;
                                                               l1->next->data=t;
                                    }
                                    l1=l1->next;
                     }
                    o=o->next;
      }
      l1=h1;*/
      //l1=h1;
      printlist(l1);
system("pause");
}

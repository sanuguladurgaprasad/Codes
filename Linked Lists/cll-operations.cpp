#include<iostream>
using namespace std;
struct node
{
       int data;
       node *next;
};
void add(node *c,int k)
{
     node *t;
     while(c->next->data!=-1)
     {
                             c=c->next;
     }
     t=(node*)new node;
     t->data=k;
     t->next=c->next;
     c->next=t;
    //cout<<t->data<<endl;
}
void display(node *c)
{
     cout<<"  the list contains: \n";
     while(c->next->data!=-1)
     {
                   cout<<c->data<<endl;
                   c=c->next;
     }
     cout<<c->data<<endl;
}
main()
{
      char m;
      int a,b,y,d;
      node *h1,*c1;
      h1=NULL;
      c1=NULL;
      h1=(node*)new node;
      cout<<"enter the data in the head node \n";
      cin>>a;
      h1->data=a;
      h1->next=h1;
      c1=h1;
      cout<<"enter the elements u want 2 enter in the llinked list \n";
      cin>>y;
      for(int i=0;i<y;i++)
      {
              cin>>d;
              add(c1,d);
      }
      display(c1);
      cin>>m;
}

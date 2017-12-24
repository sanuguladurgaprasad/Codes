#include<iostream>
using namespace std;
struct node
{
       int data;
       node *next;
       node *bottom;
};
void add(node *s,node *c,int a)
{
     node *t;int j,q;
     while(s->bottom->data!=a)
     {
                             s=s->bottom;
     }
     t=(node*)new node;cout<<"enter data \n";cin>>j;
     t->data=j;
     t->bottom=s->bottom;
     s->bottom=t;
     q=c->data;
     while(c->next->data!=q)
     {
           c=c->next;
     }
     t->next=c->next;
     c->next=t;
}
void display(node *s)
{int r;
     while(s->bottom->next!=NULL)
     {
                                 s=s->bottom;r=s->data;
                                 while(s->next->bottom!=NULL)
                                 {
                                                              s=s->next;
                                 }
                                 cout<<"course:"<<s->next->data<<endl;
                                 s=s->next;
                                 while(s->data!=r)
                                 {
                                                 s=s->next;
                                 }
     }
}
void displa(node *c)
{int r;
     while(c->next->bottom!=NULL)
     {
                                 c=c->next;r=c->data;
                                 while(c->bottom->next!=NULL)
                                 {
                                                              c=c->bottom;
                                 }
                                 cout<<"student:"<<c->bottom->data<<endl;
                                 c=c->bottom;
                                 while(c->data!=r)
                                 {
                                                 c=c->bottom;
                                 }
     }
}
main()
{
      int i,y,e,j,d,a[5],b[5];
      node *h[5],*s[5],*m[5],*c[5];
      for(i=0;i<5;i++)
      {
      h[i]=NULL;
      m[i]=NULL;
      h[i]=(node*)new node;
      m[i]=(node*)new node;
      }
      cout<<"enter the data in the head node \n";
      for(i=0;i<5;i++)
      {
      cin>>a[i]>>b[i];
      h[i]->data=a[i];
      m[i]->data=b[i];
      h[i]->next=NULL;
      h[i]->bottom=h[i];
      m[i]->next=m[i];
      m[i]->bottom=NULL;
      s[i]=h[i];
      c[i]=m[i];
      }
      for(int i=0;i<5;i++)
      {
              cout<<"enter no. of courses\n";
              cin>>y;
              for(j=0;j<y;j++)
              {
                              cin>>d;
              add(s[i],c[d-1],a[i]);
              }
      }for(i=0;i<5;i++)
      {s[i]=h[i];
      }
      for(i=0;i<5;i++)
      {
      cout<<"which student data \n";
      cin>>e;
      display(s[e-1]);
      }
      for(i=0;i<5;i++)
      {
      cout<<"which course data \n";
      cin>>e;
      displa(c[e-1]);
      }
      system("pause");
}

#include<iostream>
using namespace std;
struct node
{
       int data;
       node *right;
       node *left;
};
void add1(node *l,int k,int s)
{
     node *t;
     while(l->right->data!=s)
     {
                   l=l->right;
     }
 t=(node*)new node;
 t->data=k;
 t->right=l->right;
     l->right=t;
}
void printlist1(node *l,int s)
{
     cout<<"  the list contains: \n";
     while(l->right->data!=s)
     {
                   cout<<l->data<<endl;
                   l=l->right;
     }
     cout<<l->data;
}
void merge(node *h,node *l,node *m,int s,int v)
{
     while(l->right->data!=s)
     {
                             l=l->right;
     }
     l->right=m;
     m->right->left=l;
     while(m->right->data!=v)
     {
                             m=m->right;
     }
     m->right=h;
     h->left=m;
}
main()
{     node *l1,*h1,*l2,*h2; 
      int i,a,b,c,k,d,e,f,g,j;
      h1=(node*)new node;
      cout<<"enter the digit\n";
      cin>>a;
      h1->data=a;
      h1->right=h1;
      h1->left=h1;l1=h1;
      h2=(node*)new node;
      cout<<"enter the digit\n";
      cin>>f;
      h2->data=f;
      h2->right=h2;
      h2->left=h2;l2=h2;
      cout<<"enter the no.\n";
      cin>>b;cout<<"enter \n";
      for(i=0;i<b;i++)
      {
                      cin>>c;
                      add1(l1,c,a);
      }
      printlist1(l1,a);
      cout<<"enter the no.\n";
      cin>>b;cout<<"enter \n";
      for(i=0;i<b;i++)
      {
                      cin>>c;
                      add1(l2,c,f);
      }
      printlist1(l2,f);
      merge(h1,l1,l2,a,f);
      printlist1(l1,a);
      system("pause");
}

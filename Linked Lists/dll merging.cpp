#include<iostream>
using namespace std;
struct node
{
       int data;
       node *right;
       node *left;
};
void add1(node *l,int k)
{
     while(l->right!=NULL)
     {
                   l=l->right;
     }
     l->right=(node*)new node;
     l->right->data=k; 
     l->right->left=l;
     l->right->right=NULL;
}

void printlist1(node *l)
{
     cout<<"  the list contains: \n";
     while(l!=NULL)
     {
                   cout<<l->data<<endl;
                   l=l->right;
     }
}
void merge(node *l,node *m)
{
     while(l->right!=NULL)
     {
                          l=l->right;
     }
     l->right=m;
     m->right->left=l;
}
main()
{
      node *l1,*h1,*t1,*h2,*l2,*t2;
      int i,a,b,c,k,d,e,f,g,j;
      h1=(node*)new node;
      cout<<"enter the digit\n";
      cin>>a;
      h1->data=a;
      h1->right=NULL;
      h1->left=NULL;t1=h1;l1=h1;
      h2=(node*)new node;
      cout<<"enter the digit\n";
      cin>>a;
      h2->data=a;
      h2->right=NULL;
      h2->left=NULL;t2=h2;l2=h2;
      cout<<"enter the no.\n";
      cin>>b;cout<<"enter \n";
      for(i=0;i<b;i++)
      {
                      cin>>c;
                      add1(l1,c);
                      t1=t1->right;
      }
      cout<<"enter the no.\n";
      cin>>b;cout<<"enter \n";
      for(i=0;i<b;i++)
      {
                      cin>>c;
                      add1(l2,c);
                      t2=t2->right;
      }
       printlist1(l1);
       printlist1(l2);
       merge(l1,l2);
       printlist1(l1);
      system("pause");
}

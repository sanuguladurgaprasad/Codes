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
void del1(node *l,int k)
{
     node *t;
     while(l->right->data!=k)
     {
                             l=l->right;
     }
         if(l->right->right==NULL)
         {
                    l->right=NULL;
         } 
         else
         {t=l->right;
         l->right=t->right;
         t->right->left=l;
         }
         delete t;                    
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
void add2(node *l,int k)
{
     while(l->left!=NULL)
     {
                   l=l->left;
     }
     l->left=(node*)new node;
     l->left->data=k; 
     l->left->right=l;
     l->left->left=NULL;
}
void del2(node *l,int k)
{
     node *t;
      while(l->left->data!=k)
     {
                             l=l->left;
     }
         if(l->left->left==NULL)
         {
                    l->left=NULL;
         } 
         else
         {t=l->left;
         l->left=t->left;
         t->left->right=l;
         }
         delete t;                    
}
void printlist2(node *l)
{
     cout<<"  the list contains: \n";
     while(l!=NULL)
     {
                   cout<<l->data<<endl;
                   l=l->left;
     }
}
main()
{
      node *l1,*h1,*t1;
      int i,a,b,c,k,d,e,f,g,j;
      h1=(node*)new node;
      cout<<"enter the digit\n";
      cin>>a;
      h1->data=a;
      h1->right=NULL;
      h1->left=NULL;t1=h1;l1=h1;
      cout<<"enter the no.\n";
      cin>>b;cout<<"enter \n";
      for(i=0;i<b;i++)
      {
                      cin>>c;
                      add1(l1,c);
                      t1=t1->right;
      }
      cout<<"enter the no. nd digits to be deleted \n";
      cin>>e;
      for(i=0;i<e;i++)
      {
                      cin>>d;
                      if(t1->data==d)
                      {
                                    t1=t1->left;
                                    del1(l1,d);
                      }
                      else
                      {
                        del1(l1,d);
                      }
      }
       printlist1(l1);l1=t1;
       printlist2(l1);
       cout<<"enter the no.\n";
      cin>>f;cout<<"enter \n";
       for(i=0;i<f;i++)
      {
                      cin>>g;
                      add2(l1,g);
                      h1=h1->left;
      }
      cout<<"enter the no. nd digits to be deleted \n";
      cin>>j;
      for(i=0;i<j;i++)
      {
                      cin>>k;
                      if(h1->data==k)
                      {
                      h1=h1->right;
                      del2(l1,k);
                      }
      else
      {
          del2(l1,k);
      }
      }
      printlist2(l1);
      system("pause");
}

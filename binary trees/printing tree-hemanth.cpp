#include<iostream>
#include<cmath>
using namespace std;
struct bnode
{         
       int data;
       bnode *rchild;
       bnode *lchild;
}; 
void insert(bnode *b,int k)
{
     if(b->data>k)
     {
     if(b->lchild==NULL)
     {
                        b->lchild=new bnode;
                        b->lchild->data=k;
                        b->lchild->rchild=NULL;
                        b->lchild->lchild=NULL;
     }
     else
     insert(b->lchild,k);
     }
     if(b->data<k)
     {
     if(b->rchild==NULL)
     {
                        b->rchild=new bnode;
                        b->rchild->data=k;
                        b->rchild->lchild=NULL;
                        b->rchild->rchild=NULL;
     }
     else
     insert(b->rchild,k);     
     }
}
void print(bnode *b)
{
     if(b!=NULL)
     {
                print(b->lchild);
                cout<<b->data<<endl;
                print(b->rchild);
     }
}    
int po(int t,int z)
{t=1;
    if(z==0)
    {return t;}
    else
    {
        for(int i=0;i<z;i++)
        {t=t*2;}
        return t;
    }
}
void pp(bnode *l,int count,int o)
{
     if(l!=NULL)
     {
                if(count==0)
                {cout<<l->data<<endl;count++;}
     }
     if(count==po(2,o)-1)
     {o++;
     cout<<endl;                  
     }
     if(l->lchild!=NULL)
     {cout<<l->lchild->data<<" ";count++;}
     if(l->rchild!=NULL)
     {cout<<l->rchild->data<<" ";count++;}
    if((count%po(2,o-1)!=0)&&(l->lchild!=NULL))
     {pp(l->lchild,count,o);}
     if(((count+po(2,o-1)-1)%(po(2,o-1))==0)&&(l->rchild!=NULL))
     {pp(l->rchild,count,o);}
}
main()
{
      bnode *b1,*h1;int count=0;
      int a,b,c,d,e,f,k,o=1;
      h1=(bnode*)new bnode;
      cout<<"enter the no.s \n";
      cin>>a;
      h1->data=a;
      h1->lchild=NULL;
      h1->rchild=NULL;
      b1=h1;
      cout<<"enter the no. of numbers u want to be in the tree \n";
      cin>>c;
      cout<<"enter them in list1\n";
      for(int i=0;i<c;i++)
      {
              cin>>e;
              insert(b1,e);
      }
      print(b1);
      cout<<"enter \n";
      pp(b1,count,o);
      system("pause");
}

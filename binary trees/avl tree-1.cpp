#include<iostream>
#include<cmath>
using namespace std;
struct bnode
{
       int data;
       int height;
       bnode *rchild;
       bnode *lchild;
};
int max(int m1,int n1)
{
    if(m1>n1){return m1;}
    else {return n1;}
}
bnode* insert(bnode *b,int k)
{
     if(b==NULL)
     {
                        b=new bnode;
                        b->data=k;
                        b->rchild=NULL;
                        b->lchild=NULL;
     }
if(b->data>k){b->lchild=insert(b->lchild,k);}
if(b->data<k){b->rchild=insert(b->rchild,k);}
return b;
}
int height1(bnode *b)
{
    int m,n;
    if(b==NULL){return -1;}
    else{m=height1(b->lchild);n=height1(b->rchild);b->height=max(m,n)+1;return (max(m,n)+1);}
}
void lrot(bnode *b)
{
     bnode *x=b->lchild;b->lchild=x->rchild;x->rchild=b;b=x;height1(b);
}
void rrot(bnode *b)
{
     bnode *x=b->rchild;b->rchild=x->lchild;x->lchild=b;b=x;height1(b);
}
void ldbrot(bnode *b)
{
     bnode *x,*y;
     x=b->lchild;y=x->rchild;b->lchild=y->rchild;
     x->rchild=y->lchild;y->rchild=b;y->lchild=x;b=y;height1(b);
}
void rdbrot(bnode *b)
{
     bnode *x,*y;
     x=b->rchild;y=x->lchild;b->rchild=y->lchild;
     x->lchild=y->rchild;y->lchild=b;y->rchild=x;b=y;height1(b);
}
bnode* check(bnode *b,int e)
{
       if(((e<b->data)&&(e>b->lchild->data))||((e<b->data)&&(e<b->rchild->data)))
       {
       if((b->data>b->lchild->data)&&(b->lchild->data<b->lchild->rchild->data)){ldbrot(b);}
       if((b->data<b->rchild->data)&&(b->rchild->data>b->rchild->lchild->data)){rdbrot(b);}
       }
       else
       {
       if((e<b->data)&&(e>b->lchild->data)){lrot(b);}
       if((e<b->data)&&(e<b->rchild->data)){rrot(b);}
       }
}
int height(bnode *b,int e)
{
    int m,n;
    if(b==NULL){return -1;}
    else{m=height(b->lchild,e);n=height(b->rchild,e);b->height=max(m,n)+1;if(abs(m-n)>1){check(b,e);}return (max(m,n)+1);}
}
void print(bnode *b)
{
     if(b!=NULL)
     {
                print(b->lchild);
                cout<<b->data<<"-"<<b->height<<endl;
                print(b->rchild);
     }
}
main()
{
      bnode *b1,*h1;
      int a,b,c,d,e,f,k;
      h1=(bnode*)new bnode;
      cout<<"enter the no.s \n";
      cin>>a;
      b1=NULL;
      h1=NULL;
      b1=h1;
      cout<<"enter them in list1\n";
      for(int i=0;i<a;i++)
      {
              cin>>e;
              b1=insert(b1,e);height(b1,e);
      }
       print(b1);
      system("pause");
}

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
class queue
{
      public:
             int size;
             int front;
             int rear;
             bnode *elements[100];
             queue(int);
             void enqueue(bnode*);
             bnode* dequeue();
};
queue::queue(int z)
{
                 size=z;front=-1;rear=-1;
}
void queue::enqueue(bnode* x)
{
     if(front==(rear+1)%size)
     {
                             cout<<"queue is full\n";
     }
     else
     {
     if(front==-1)
     {
                  front=0;
     }
         rear= (rear+1)%size;
         elements[rear]=x;
     }
}
bnode* queue::dequeue()
{
    bnode *t;
    if(front==-1)
    {
                 cout<<"queue is empty \n";
    }
    else
    {
    if(front==rear)
    {
     t=elements[front];
     front=-1;
     rear=-1;
    }
    else
    {
        t=elements[front];
        front=(front+1)%size;
    }
}
    return t;
}
queue q(100);
int max(int m1,int n1)
{
    if(m1>n1){return m1;}
    else {return n1;}
}
int height(bnode *b)
{
    int m,n;
    if(b==NULL){return -1;}
    else
    {m=height(b->lchild);n=height(b->rchild);b->height=max(m,n)+1;
    return (max(m,n)+1);}
}
bnode* lrot(bnode *b)
{
     bnode *x=b->lchild;;
     b->lchild=x->rchild;
     x->rchild=b;
     b->height=max(height(b->lchild),height(b->rchild))+1;
     x->height=max(height(x->lchild),height(x->rchild))+1;
     b=x;return b;
}
bnode* rrot(bnode *b)
{
     bnode *x=b->rchild;b->rchild=x->lchild;x->lchild=b;
     b->height=max(height(b->lchild),height(b->rchild))+1;
     x->height=max(height(x->lchild),height(x->rchild))+1;
     b=x;return b;
}
bnode* ldbrot(bnode *b)
{
     b->lchild=rrot(b->lchild);b=lrot(b);return b;
}
bnode* rdbrot(bnode *b)
{
b->rchild=lrot(b->rchild);b=rrot(b);return b;
}
bnode* check(bnode *b,int e)
{int m=0;
if((m==0)&&(b->lchild!=NULL)&&(b->lchild->rchild!=NULL)){if((e<b->data)&&(e>b->lchild->data)){m++;cout<<"k";b=ldbrot(b);}}
if((m==0)&&(b->rchild!=NULL)&&(b->rchild->lchild!=NULL)){if((e>b->data)&&(e<b->rchild->data)){m++;cout<<"v";b=rdbrot(b);}}
if((m==0)&&(b!=NULL)&&(b->rchild!=NULL)){if((e>b->data)&&(e>b->rchild->data)){m++;cout<<"l";b=rrot(b);cout<<b->data;}}
if((m==0)&&(b!=NULL)&&(b->lchild!=NULL)){if((e<b->data)&&(e<b->lchild->data)){m++;cout<<"s";b=lrot(b);}}
return b;                                                      
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
if(abs(height(b->lchild)-height(b->rchild))>1){cout<<b->data;b=check(b,k);cout<<b->data;}
return b;
}
void print(bnode *b)
{
     if(b!=NULL)
     {
                print(b->lchild);
                cout<<b->data<<"-"<<b->height<<endl;
                print(b->rchild);
     }
}bnode *a1;
void print2(bnode *b,bnode *r)
{
     static int k1=0;
     if(b!=NULL)
     {
                if(k1==0)
                {
                q.enqueue(b);q.enqueue(r);
                }
                k1++;
                if(k1>1)
                {      if(b->lchild!=NULL){q.enqueue(b->lchild);}
                       if(b->rchild!=NULL){q.enqueue(b->rchild);}
                }
     }
     k1++;
     if(q.front!=q.rear)
     {
                        a1=q.dequeue();
     if(a1->data==-1)
     {
     q.enqueue(r);cout<<endl;
     }
     else{cout<<a1->data<<","<<a1->height<<"  ";}
     print2(a1,r);
     }
}
main()
{
      bnode *b1;bnode *r;r=new bnode;
      r->data=-1;
      r->lchild=NULL;r->rchild=NULL;
      int a,b,c,d,e,f,k;
      cout<<"enter thehuihui no.s \n";
      cin>>a;
      b1=NULL;
      cout<<"enter them in list1\n";
      for(int i=0;i<a;i++)
      {
              cin>>e;
              b1=insert(b1,e);height(b1);
      }
      cout<<"\n"; print2(b1,r);
      system("pause");
}

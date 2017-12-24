#include<iostream>
#include<cmath>
using namespace std;
struct bnode
{         
       int data;int height;
       bnode *rchild;
       bnode *lchild;
}; class queue
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
         rear=(rear+1)%size;
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
}bnode *p1;
void del(bnode *b,int k)
{bnode *r; int count=0;
if(b->lchild!=NULL)
{r=b;
     if((b->lchild->data==k)&&(b->lchild->lchild==NULL)&&(b->lchild->rchild==NULL))
     {
               r=b->lchild;
              b->lchild=r->lchild ;count++;
               delete r;
     }
}
if(b->rchild!=NULL)
{r=b;
     if((b->rchild->data==k)&&(b->rchild->rchild==NULL)&&(b->rchild->lchild==NULL))
     {
               r=b->rchild;
               b->rchild=r->rchild;count++;
               delete r;
     }
}
     if((b->data==k)&&(count==0))
     {
          r=b;
          if(b->lchild!=NULL)
          {count++;
                             if(r->lchild->rchild==NULL)
                             {r=r->lchild;
                                                        b->data=r->data;
                                                        b->lchild=r->lchild;
                                                        delete r;
                             }
                             else
                             {
                             r=r->lchild;
                             while(r->rchild->rchild!=NULL)
                             {
                                                        r=r->rchild;
                             }
                             b->data=r->rchild->data;
                             if(r->rchild->lchild!=NULL)
                             {p1=r->rchild->lchild;
                             r->rchild=p1;
                             }
                             if(r->rchild->lchild!=NULL){r->rchild=NULL;}
          }}
          if((b->rchild!=NULL)&&(count==0))
          {
                             if(r->rchild->lchild==NULL)
                             {r=r->rchild;
                                                        b->data=r->data;
                                                        b->rchild=r->rchild;cout<<"m";
                                                        delete r;
                             }
                             else
                             {
                             r=r->lchild;
                             while(r->lchild->lchild!=NULL)
                             {
                                                        r=r->lchild;
                             }
                             b->data=r->lchild->data;
                            if(r->lchild->rchild!=NULL)
                             {p1=r->lchild->rchild;
                             r->lchild=p1;
                             }
                             if(r->lchild->lchild!=NULL){r->lchild=NULL;} 
                             }
          }       
     }
     else if((b->data<k)&&(count==0))
     del(b->rchild,k);
     else if((b->data>k)&&(count==0))
     del(b->lchild,k);
}bnode *z1,*y2,*x1;
int hh(bnode *b)
{
    int m,n,a,b2,c=0,d=0,e,f,g=0,h=0;
    if(b==NULL){return -1;}
    else{m=hh(b->lchild);n=hh(b->rchild);
    b->height=max(m,n)+1;
    if(abs(m-n)>1)
    {
                  z1=b;
                  a=hh(z1->lchild);
                  b2=hh(z1->rchild);
                  if(a>b2){y2=z1->lchild;c=1;}
                  else{y2=z1->rchild;d=1;}
                  e=hh(y2->lchild);
                  f=hh(y2->rchild);
                  if(e>f){x1=y2->lchild;g=1;}
                  else{x1=y2->rchild;h=1;}
                  if((g==1)&&(c==1))
                  {b=lrot(b);}
                  else if((c==1)&&(h==1)){b=ldbrot(b);}
                  else if((d==1)&&(h==1)){b=lrot(b);}
                  else if((d==1)&&(g==1)){b=rdbrot(b);}
    }
    return (max(m,n)+1);
}
}
bnode *a1;int k1;
void print2(bnode *b,bnode *r)
{
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
     else{cout<<a1->data<<"-"<<a1->height<<" ";}
     print2(a1,r);
     }
}
main()
{
      bnode *b1;b1=NULL;
      int a,b,c,d,e,f,k;
    bnode *r;r=new bnode;
      r->data=-1;
      r->lchild=NULL;r->rchild=NULL;
      cout<<"enter the no. of numbers u want to be in the tree \n";
      cin>>c;
      cout<<"enter them in list1\n";
      for(int i=0;i<c;i++)
      {
              cin>>e;
             b1=insert(b1,e);height(b1);
      }
      print(b1);cout<<"level\n";print2(b1,r);while(q.front!=-1){q.dequeue();}
      cout<<"enter \n";
      for(int i=0;i<c;i++)
      {
      cin>>e;k1=0;
      del(b1,e);height(b1);hh(b1);height(b1);
      cout<<"level\n";print2(b1,r);while(q.front!=-1){q.dequeue();}
      }
      system("pause");
}

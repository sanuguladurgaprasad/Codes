#include<iostream>
#include<conio.h>
using namespace std;
struct hpnode
{
       int data;
       hpnode **child;
       int count;
       hpnode *parent;
};class queue
{
      public:
             int size;
             int front;
             int rear;
             hpnode *elements[100];
             queue(int);
             void enqueue(hpnode*);
             hpnode* dequeue();
};
queue::queue(int z)
{
                 size=z;front=-1;rear=-1;
}
void queue::enqueue(hpnode* x)
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
hpnode* queue::dequeue()
{
    hpnode *t;
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
void swap(int *p,int *q)
{
     int t=*p;
     *p=*q;
     *q=t;
}
void check(hpnode *d)
{
     if(d->parent!=NULL)
     {if(d->parent->data>d->data){swap(d->parent->data,d->data);}check(d->parent);}
}
hpnode *e,*g;int i=0;
hpnode* insert(hpnode *&d,int d1)
{int j,y,l;static int m=0;cout<<"do u want to enter \n";cin>>y;
if(y==1){cout<<"enter the value\n";cin>>l;
     if(d==NULL)
     {cout<<"t";
                d=new hpnode;
                d->data=l;if(m==0){d->parent=NULL;}else{d->parent=g;}
                d->child=NULL;check(d);
                m++;
                for(int f=0;f<d1;f++)
                {cout<<"r";q.enqueue(d);}i++;
     }g=q.dequeue();
    if(g->child==NULL)
    {i=0;cout<<"l";g->child=new hpnode*[d1];for(int f=0;f<d1;f++){g->child[f]=NULL;}}
    if((g->child[i]==NULL)&&(i<d1))
    {cout<<i<<"a";g->child[i]=insert(g->child[i],d1);
    }return d;}
}
void print(hpnode *b)
{if(b!=NULL){
     for(int k=0;k<2;k++)
     {cout<<b->data<<":";
     print(b->child[k]);}
}}
hpnode* create(hpnode *d,int d1)
{
     int a,b;
    d=insert(d,d1);
     return d;
}
hpnode *a1;
void print2(hpnode *b,hpnode *r,int d1)
{
     static int k=0;
     if(b!=NULL)
     {
                if(k==0)
                {
                q.enqueue(b);q.enqueue(r);
                }
                k++;
                if(k>1)
                {if(b->child!=NULL){
                    for(int i=0;i<d1;i++){
                       if(b->child[i]!=NULL){cout<<b->child[i]->data<<"$";q.enqueue(b->child[i]);}
                }}
     }}
     k++;getch();
     if(q.front!=q.rear)
     {
                        a1=q.dequeue();cout<<a1->data<<"*";
     if(a1->data==-1)
     {cout<<"h";
     q.enqueue(r);cout<<endl;
     }
     else{if(k>2){cout<<a1->data<<"  par="<<a1->parent->data<<"  ";}else{cout<<a1->data<<" no parent\n";}}
     print2(a1,r,d1);
     }
}
main()
{
      int e1,i,d1;hpnode *r,*d;d=NULL;r=new hpnode;
      r->data=-1;
      r->parent=NULL;r->child=NULL;
      cout<<"enter how many elements u want in the heap\n";
      cout<<"enter the d\n";cin>>d1;
      d=create(d,d1);
       while(q.front!=-1)
      {q.dequeue();}cout<<endl;print2(d,r,d1);
	  int xx;cin>>xx;
}

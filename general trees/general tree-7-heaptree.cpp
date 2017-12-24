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
void fn(int h[],int k,int d1)
{
     if(k!=-1)
     {
    for(int i=0;i<d1;i++)
    {     if(k%d1==0){
                        if(h[k]<h[(k-1)/d1])
                        {
                                         swap(&h[k],&h[(k-1)/d1]);
                        }
                                        fn(h,k-1,d1);
                         }
                         if(k%d1==i)
                         {
                                     if(h[k]<h[(k-i)/d1])
                                        {
                                            swap(&h[k],&h[(k-i)/d1]);
                                        }
                                        fn(h,k-1,d1);
                         }
     }
}
}hpnode *e,*g;
hpnode* insert(hpnode *d,int b,int y,int d1)
{cout<<"y";int j;
     if(d==NULL)
     {
                d=new hpnode;
                d->data=b;d->parent=NULL;d->child=NULL;
                for(int f=0;f<d1;f++)
                {q.enqueue(d);}
     }
     else
     {g=q.dequeue();cout<<"k";
     if(g!=NULL)
	 {
    if((g->child==NULL)&&(y%d1==1))
         {g->child=new hpnode*[d1];for(int f=0;f<d1;f++){g->child[f]=NULL;}g->child[0]=new hpnode;
         g->child[0]->parent=g;g->child[0]->data=b;g->child[0]->child=NULL;cout<<"t";
        for(int f=0;f<d1;f++) {q.enqueue(g->child[0]);}}
     else if((g->child!=NULL)&&(y%d1!=1))
         {if(y%d1==0){j=d1-1;cout<<j;g->child[j]=new hpnode;
         cout<<"b";g->child[j]->parent=g;cout<<"u";g->child[j]->data=b;cout<<"d";g->child[j]->child=NULL;cout<<"s";
        for(int f=0;f<d1;f++) {q.enqueue(g->child[j]);}}
          else{   j=y%d1;cout<<"r";g->child[j-1]=new hpnode;
          g->child[j-1]->parent=g;cout<<"u";g->child[j-1]->data=b;cout<<"d";g->child[j-1]->child=NULL;cout<<"s";
        for(int f=0;f<d1;f++) {cout<<"i";q.enqueue(g->child[j-1]);}}
     }}}cout<<"e";
     return d;
}
hpnode* create(int h[],int size,int d1,hpnode *d)
{
     int a,b;
     for(int i=0;i<size;i++)
     {
             cin>>a;h[i]=a;fn(h,i,d1);
     }
     for(int i=0;i<size;i++)
     {cout<<"zz";
             b=h[i];d=insert(d,b,i,d1);
     }
     return d;
}
void delet(int h[],int size,int h1[],int d1)
{
     int i=0;
     while(size!=0)
     {
         h1[i]=h[0];
         h[0]=h[size-1];
         size--;i++;
         fn(h,size-1,d1);
     }
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
                       if(b->child[i]!=NULL){q.enqueue(b->child[i]);}}
                }}
     }
     k++;getch();
     if(q.front!=q.rear)
     {
                        a1=q.dequeue();
     if(a1->data==-1)
     {
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
      cin>>e1;cout<<"enter the d\n";cin>>d1;
      int h[e1],h1[e1];
     d=create(h,e1,d1,d);
      cout<<"the heap insertion is\n";
      for(i=0;i<e1;i++)
      {cout<<h[i]<<" "<<endl;}cout<<"the sorted way is\n";
      delet(h,e1,h1,d1);
      for(i=0;i<e1;i++)
      {cout<<h1[i]<<" "<<endl;}
       while(q.front!=-1)
      {q.dequeue();}cout<<endl;print2(d,r,d1);
      system("pause");
}

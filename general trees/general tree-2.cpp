#include<iostream>
using namespace std;
struct bnode
{         
          int data;int count;
          bnode **nchild;
};
class queue
{
      public:
             int size;
             int front;
             int rear;
             bnode *elements[35];
             queue(int);
             void enqueue(bnode*);
             bnode* dequeue();
};
queue::queue(int z)
{
                 size=z;front=-1;rear=-1;
}bnode *g;
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
queue q(30);
void insert(bnode *b)
{int x,m,i,j;static int y=0;
if(y!=0){b=new bnode;}
cout<<"do u want children\n";cin>>j;
if(j==1)
{
     cout<<"enter the no. of children u want\n";
     cin>>x;b->count=x;b->nchild=new bnode*[x];
     for(i=0;i<x;i++)
     {cout<<"enter\n";cin>>m;b->nchild[i]=new bnode;b->nchild[i]->data=m;insert(b->nchild[i]);}
}    
else
{b->nchild=NULL;}
}
bnode *a1;
void print(bnode *b,bnode *r)
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
                {
                       for(int i=0;i<b->count;i++){
                if(b->nchild[i]!=NULL)q.enqueue(b->nchild[i]);
                }
                }
     }
     k++;
     if(q.front!=q.rear)
     {
                        a1=q.dequeue();
     if(a1->data==-1)
     {
     q.enqueue(r);cout<<endl;
     }
     else{cout<<a1->data<<"  ";}
     print(a1,r);
     }
}
main()
{
      bnode *a,*b,*r;
      int c,d,e,f,x,m;
      cout<<"enter the data in the head node \n";
      cin>>c;
      r=new bnode;
      r->data=-1;
      r->nchild=NULL;
      a=new bnode;a->data=c;a->nchild=NULL;
      b=a;
      insert(b);print(b,r);
      system("pause");
}

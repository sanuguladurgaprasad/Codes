#include<iostream>
using namespace std;
struct bnode
{         
       int data;
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
bnode* insert(bnode *b,int k)
{
     if(b==NULL)
     {
                        b=new bnode;
                        b->data=k;
                        b->rchild=NULL;
                        b->lchild=NULL;
     }
     if(b->data>k)
     {
     b->lchild=insert(b->lchild,k);
     }
     if(b->data<k)
     {
     b->rchild=insert(b->rchild,k);     
     }return b;
}    
void print(bnode *b)
{
     if(b!=NULL)
     {
                print(b->lchild);
                if(b->data!=-1){cout<<b->data<<endl;}
                print(b->rchild);
     }
}
bnode* findmin(bnode *b)
{
       if(b->lchild!=NULL)
       {b->lchild=findmin(b->lchild);return b;}
       else{return b;}
}
bnode* findmax(bnode *b)
{
       if(b->rchild!=NULL)
       {b->rchild=findmax(b->rchild);return b;}
       else{return b;}
}
bnode *p1,*p;
bnode* del(bnode *b,int k)
{
     if(b->data==k)
     {
     if(b->lchild!=NULL){p=b->lchild;p1=findmax(p);}
     else if(b->rchild!=NULL){p=b->rchild;p1=findmin(p);}
     else{p1=b;}
     b->data=p1->data;p1->data=-1;
     }
     else if(b->data>k){b->lchild=del(b->lchild,k);}
     else{b->rchild=del(b->rchild,k);}
     return b;
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
     if(a1->data==-11)
     {
     q.enqueue(r);cout<<endl;
     }
     else{if(a1->data!=-1){cout<<a1->data<<" ";}}
     print2(a1,r);
     }
}
main()
{
      bnode *b1;b1=NULL;
      int a,b,c,d,e,f,k;
     bnode *r;r=new bnode;
      r->data=-11;
      r->lchild=NULL;r->rchild=NULL;
      cout<<"enter the no. of numbers u want to be in the tree \n";
      cin>>c;
      cout<<"enter them in list1\n";
      for(int i=0;i<c;i++)
      {
              cin>>e;
              b1=insert(b1,e);
      }
      print(b1);cout<<"level\n";print2(b1,r);while(q.front!=-1){q.dequeue();}
      cout<<"enter \n";
      for(int i=0;i<9;i++)
      {k1=0;
      cin>>e;
      del(b1,e);cout<<endl;print(b1);cout<<"level\n";print2(b1,r);while(q.front!=-1){q.dequeue();}
      }
      system("pause");
}

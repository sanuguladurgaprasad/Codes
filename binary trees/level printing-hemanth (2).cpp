#include<iostream>
using namespace std;
struct bnode
{         
       int data;
       int roll;
       bnode *rchild;
       bnode *lchild;
}; 
class queue
{
      public:
             int size;
             int front;
             int rear;
             bnode *elements[35];
             queue(int);
            //~queue();
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
                static int c1=0;
                b->roll=c1;c1++;//ut<<b->roll;
                print(b->rchild);}
}
void print1(bnode *b)
{
     int e=b->roll;
   for(int i=0;i<e;i++)
     {cout<<"    ";}
}
bnode *a1;
void level(bnode *b,bnode *r)
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
                {//ut<<"m\n";cout<<b->data;
                if(b->lchild!=NULL)q.enqueue(b->lchild);
                if(b->rchild!=NULL)q.enqueue(b->rchild);
                }
     }
     k++;
     if(q.front!=q.rear)
     {
                        a1=q.dequeue();
     if(a1->data==-1)
     {
     q.enqueue(r);cout<<"\n\n\n\n";
     }
     else{print1(a1);
cout<<"("<<a1->data<<")"<<" ";}
     level(a1,r);
     }
}
main()
{
      bnode *b1,*h1,*r;
      int a,b,c,d,e,f,k;
      h1=(bnode*)new bnode;
      cout<<"enter the no.s \n";
      cin>>a;
      h1->data=a;
      h1->lchild=NULL;
      h1->rchild=NULL;
      r=(bnode*)new bnode;
      r->data=-1;
      r->lchild=NULL;
      r->rchild=NULL;
      b1=h1;
      cout<<"enter the no. of numbers u want to be in the tree \n";
      cin>>c;
      cout<<"enter them in list1\n";
      for(int i=0;i<c;i++)
      {
              cin>>e;
              insert(b1,e);
      }int i;
      print(b1);
      level(b1,r);
      system("pause");
}

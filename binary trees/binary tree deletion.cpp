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
}bnode *a1;int k1;
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
     else{cout<<a1->data<<" ";}
     print2(a1,r);
     }
}
main()
{
      bnode *b1,*h1;
      int a,b,c,d,e,f,k;
      h1=(bnode*)new bnode;bnode *r;r=new bnode;
      r->data=-1;
      r->lchild=NULL;r->rchild=NULL;
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
      for(int i=0;i<9;i++)
      {
      cin>>e;k1=0;
      del(b1,e);print(b1);cout<<"level\n";print2(b1,r);while(q.front!=-1){q.dequeue();}
      }
      system("pause");
}

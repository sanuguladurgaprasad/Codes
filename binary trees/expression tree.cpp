#include<iostream>
#include<string>
#include<cctype>
using namespace std;
struct bnode
{
       char data;
       bnode *rchild;
       bnode *lchild;
};
class stack
{
      public:
             int size;
             int top;
             bnode* elements[35];
             void push(bnode*);
             bnode* pop();
             stack(int);
};
stack::stack(int z)
{
size=z;
top=-1;
}
void stack::push(bnode* x)
{
     if(top==size-1)
     {
                cout<<"stack is full \n";
     }
     else
     {
     elements[++top]=x;
     }
}
bnode* stack::pop()
{
     if(top==-1)
     {
                cout<<"stack is empty \n";
     }
     else
     {
         return(elements[top--]);
     }
}class queue
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
stack s(30);
bnode *a,*b,*a1;
void create(bnode *b1,char k)
{
     b1=new bnode;
     b1->data=k;b1->lchild=NULL;b1->rchild=NULL;
     if(!isdigit(k))
     {
                  a=s.pop();
                  b=s.pop();
                  b1->lchild=b;b1->rchild=a;
     }
     s.push(b1);
}
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
     q.enqueue(r);cout<<endl;
     }
     else{cout<<a1->data<<"  ";}
     print(a1,r);
     }
}
int fn(int a1,int a2,char a3)
{
    if(a3=='+'){return (a1+a2);}
    if(a3=='-'){return (a1-a2);}
    if(a3=='*'){return (a1*a2);}
    if(a3=='/'){return (a1/a2);}
}
int evaluate(bnode *et)
{
   int a1,a2,r;char sym;
   if(et!=NULL)
   {
    if(isdigit(et->data)){return (et->data-'0');}
    a1=evaluate(et->lchild);
    a2=evaluate(et->rchild);
    sym=et->data;
    r=fn(a1,a2,sym);
    return r;
   }
}
main()
{
      int m,z1,x,i=0,k;
      bnode *l,*r;
      r=(bnode*)new bnode;
      r->data=-1;
      r->lchild=NULL;
      r->rchild=NULL;
      string s1;
      getline(cin,s1);z1=s1.length();
      for(k=0;k<z1;k++)
      {
                       i=k;
                      while(isdigit(s1[i]))
                      {
                                           create(l,s1[i]);i++;
                      }
                      create(l,s1[i]);k=i;
      }l=s.pop();
      print(l,r);cout<<endl;
      m=evaluate(l);
      cout<<"the answer is="<<m;cout<<endl;
      cin>>m;
}

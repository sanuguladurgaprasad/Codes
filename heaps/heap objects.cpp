#include<iostream>
#include<string>
using namespace std;
class student
{public:
      int rollno;
      int marks;
      string name;
};
struct hpnode
{
       student st;
       hpnode *lchild;
       hpnode *rchild;
       hpnode *parent;
};
class queue
{
      public:
             int size;
             int front;
             int rear;
             hpnode *elements[35];
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
}queue q(20);
void swap(int *p,int *q)
{
     int t=*p;
     *p=*q;
     *q=t;
}
void fn(int h[],int k)
{
     if(k!=-1)
     {
              if(k%2!=0){
                         if(h[k]<h[k/2]){
                                         swap(&h[k],&h[k/2]);
                                        }
                                        fn(h,k-1);
                         }
                         else
                         {if(h[k]<h[(k-1)/2]){swap(&h[k],&h[(k-1)/2]);}
                         fn(h,k-1);
                         }
     }
}hpnode *e,*g;
hpnode* insert(hpnode *d,int b,int y)
{int c;string u="ramu";
     if(d==NULL)
     {
                d=new hpnode;
                d->st.rollno=b;cout<<"enter name\n";cout<<"enter marks\n";cin>>c;d->st.name=u;d->st.marks=c;
                d->parent=NULL;d->lchild=NULL;d->rchild=NULL;q.enqueue(d); q.enqueue(d);         
     }
     else
     {g=q.dequeue();
     if(g!=NULL){
         if((g->lchild==NULL)&&(y%2!=0))
         {e=new hpnode;
         e->parent=g;g->lchild=e;e->st.rollno=b;cout<<"enter name\n";cout<<"enter marks\n";cin>>c;
         e->st.name=u;e->st.marks=c;
         e->lchild=NULL;e->rchild=NULL;
         q.enqueue(g->lchild);q.enqueue(g->lchild);}
     if((g->rchild==NULL)&&(y%2==0))
         {e=new hpnode;
         e->parent=g;g->rchild=e;
         e->st.rollno=b;cout<<"enter name\n";cout<<"enter marks\n";cin>>c;
         e->st.name=u;e->st.marks=c;
         e->lchild=NULL;e->rchild=NULL;q.enqueue(g->rchild);q.enqueue(g->rchild);}
     }
     }
     return d;
}
hpnode* create(int h[],int size,hpnode *d)
{cout<<"t";
     int a,b;cout<<"enter the roll no of students \n";
     for(int i=0;i<size;i++)
     {
             cin>>b;h[i]=b;fn(h,i);
     }
     for(int i=0;i<size;i++)
     {
            b=h[i];d=insert(d,b,i);    
     }
     
     return d;
}
void delet(int h[],int size,int h1[])
{
     int i=0;
     while(size!=0)

     {
         h1[i]=h[0];
         h[0]=h[size-1];
         size--;i++;
         fn(h,size-1);
     }
}
void get(hpnode *d)
{
     cout<<"rollno: "<<d->st.rollno<<endl;
     cout<<"name  : "<<d->st.name<<endl;
     cout<<"marks : "<<d->st.marks<<endl;
}
hpnode *a1;
void print2(hpnode *b,hpnode *r)
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
                       if(b->lchild!=NULL){q.enqueue(b->lchild);}
                       if(b->rchild!=NULL){q.enqueue(b->rchild);}
                }
     }
     k++;
     if(q.front!=q.rear)
     {
                        a1=q.dequeue();
     if(a1->st.rollno==-1)
     {
     q.enqueue(r);cout<<endl;
     }
     else{get(a1);}
     print2(a1,r);
     }
}
main()
{
      int e,i;hpnode *r;r=new hpnode;
      r->st.rollno=-1;
      r->parent=NULL;r->lchild=NULL;r->rchild=NULL;
      cout<<"enter how many student records u want int the heap\n";
      cin>>e;hpnode *d;d=NULL;
      int h[e],h1[e];
      d=create(h,e,d);
      cout<<"the heap insertion is\n";
      for(i=0;i<e;i++)
      {cout<<h[i]<<" "<<endl;}cout<<"the sorted way is\n";
      delet(h,e,h1);
      for(i=0;i<e;i++)
      {cout<<h1[i]<<" "<<endl;}
      while(q.front!=-1)
      {q.dequeue();}
cout<<endl;print2(d,r);
      system("pause");
}

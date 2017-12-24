#include<iostream>//u can do with queue
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
       hpnode *fchild;
       hpnode *nchild;
       hpnode *parent;
};
class queue
{
      public:
             int size;
             int front;
             int rear;
             hpnode **elements;
             queue(int);
             void enqueue(hpnode*);
             hpnode* dequeue();
};
queue::queue(int z)
{
                 size=z;front=-1;rear=-1;elements=new hpnode*[z];
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
}queue q(20);hpnode *w,*df,*rr;
hpnode* insert(hpnode *d,hpnode *w)
{int x,z,a,b;static int s1=0;static int m=0;
        if(d==NULL)
        {int a;cout<<"enter the rollno:\n";cin>>b;cout<<"enter the marks\n";cin>>a;
                   d=new hpnode;
                   d->st.rollno=b;d->st.name="ram";d->st.marks=a;d->fchild=NULL;d->nchild=NULL;
                   if(s1==0){df=d;w=df;d->parent=NULL;}s1++;if(s1>1){if(m==1){w=d;}d->parent=rr;}
        }
             cout<<"do u want "<<d->st.rollno<<"'s first child\n";
             cin>>x;
             if(x==1)
             {m=0;m++;rr=df;cout<<rr->st.rollno<<"kiin\n";df=w;d->fchild=insert(d->fchild,w);}
             cout<<"do u want"<<d->st.rollno<<"'s sibling\n ";       
             cin>>z;cout<<rr->st.rollno<<"KKKK\n";
             if(z==1){d->nchild=insert(d->nchild,rr);}
        return d;
}
void get(hpnode *d)
{if(d->parent!=NULL)
{     cout<<"parent: "<<d->parent->st.rollno<<endl;}else{cout<<"no parent\n";}
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
                k++;q.enqueue(b);q.enqueue(r);
                }
                if(k>1)
                {if(b->fchild!=NULL)
                {
                       q.enqueue(b->fchild);b=b->fchild;
                       while(b->nchild!=NULL)
                       {q.enqueue(b->nchild);b=b->nchild;}}
                }k++;
     }
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
void print(hpnode* d)
{
     if(d!=NULL){
                 print(d->fchild);
                 cout<<d->st.rollno;
                 print(d->nchild);
                 }
}
main()
{
      int e,i;
      hpnode *r,*d,*m;d=NULL;m=NULL;
      r=new hpnode;
      r->st.rollno=-1;
      r->parent=NULL;r->fchild=NULL;r->nchild=NULL;
      d=insert(d,m);
cout<<endl;print2(d,r);print(d);
	  cin>>i;
}

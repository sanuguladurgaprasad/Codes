//om ganeshaya namaha;omsairam
#include<iostream>
using namespace std;
struct gnode
{
       int tag;
       gnode *child;
       union
       {
          char data;
          gnode *fam;  
       }
       ad t;
};
class queue
{
      public:
             int size;
             int front;
             int rear;
             gnode *elements[35];
             queue(int);
            //~queue();
             void enqueue(gnode*);
             gnode* dequeue();
};
queue::queue(int z)
{
                 size=z;front=-1;rear=-1;
}gnode *g;
void queue::enqueue(gnode* x)
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
gnode* queue::dequeue()
{
    gnode *t;
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
void insert(gnode *&b)
{int x,y,h;char a;
     cout<<"if ur child want children then press 1 else 0 else 9 \n";
     cin>>x;
     if(x==1)
     {
             b=new gnode;
             b->tag=0;
             b->child=NULL;
             b->t.fam=new gnode;
             b=b->t.fam;
             cout<<"enter data\n";cin>>a;b->t.data=a;b->tag=1;b->child=NULL;
             insert(b->child);
     }
     if(x==0)
     {
            b=new gnode;
             cout<<"enter data\n";cin>>a;b->t.data=a;b->tag=1;b->child=NULL;
     } 
      if(b!=NULL){
      cout<<"do u need of "<<b->t.data<<"'s siblings\n";cin>>y;
      if(y==0){b==NULL;}
      else 
     {cout<<"enter "<<b->t.data<<"'s siblings"<<" \n ";
              insert(b->child);
     }}
}gnode *a1;
void print(gnode *b,gnode *r)
{static int i=0;
     while(b!=NULL)
     {
     if(b->tag==0){q.enqueue(b->t.fam);}else{q.enqueue(b);}b=b->child;
     }q.enqueue(r);i++;
     if(q.front!=q.rear)
     {
     a1=q.dequeue();
     if(a1->t.data==-1){q.enqueue(r);cout<<endl;print(a1->child,r);}
     else
     {
     cout<<a1->t.data;
     if((i>0)&&(a1->child!=NULL))
     {cout<<a1->child->tag;print(a1->child,r);}
     }
     }
}
main()
{
      gnode *g,*b,*r,*e;g=NULL;b=NULL;
      char a;
      b=new gnode;
             b->tag=0;
             b->child=NULL;e=b;
             b->t.fam=new gnode;
             b=b->t.fam;
             cout<<"enter data\n";cin>>a;b->t.data=a;b->tag=1;b->child=NULL;
      r=new gnode;
      r->t.data=-1;
      r->child=NULL;
      insert(b->child);
      g=e;
      print(g,r);
      cin>>a;
}

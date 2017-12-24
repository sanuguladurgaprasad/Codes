#include<iostream>
using namespace std;
struct bnode
{         
       int data;
       int roll;
       bnode *schild;
       bnode *fchild;
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
void insert(bnode *b)
{
     int x,z,k;
     if(b!=NULL)
     {
                cout<<"do u want ur first child \n";
                cin>>x;
                if(x==1)
                {if(b->fchild==NULL)
                {
                                    cout<<"enter data\n";
                                    cin>>k;
                                    b->fchild=new bnode;
                                    b->fchild->data=k;
                                    b->fchild->fchild=NULL;
                                    b->fchild->schild=NULL;
                }
                                    insert(b->fchild);
                }
                cout<<"do u want ur sibling \n";
                cin>>z;
                if(z==1)
                {if(b->schild==NULL)
                {
                                    cout<<"enter data \n";
                                    cin>>k;
                                    b->schild=new bnode;
                                    b->schild->data=k;
                                    b->schild->schild=NULL;
                                    b->schild->fchild=NULL;
                }
                insert(b->schild);
                }
     }
}bnode *r,*a1;
void print(bnode *b,bnode *t)
{
     static int k=0;
     if(b!=NULL)
     {if(k==0)
     {
              q.enqueue(b);k++;q.enqueue(t);
     }
     if(k>1)
     {
            if(b->fchild!=NULL){
             q.enqueue(b->fchild);
             b=b->fchild;
             while(b->schild!=NULL){q.enqueue(b->schild);b=b->schild;}}
     }k++;
}
if(q.front!=q.rear)
{
                   a1=q.dequeue();
                   if(a1->data==-1)
                   {
                                   cout<<endl;q.enqueue(t);
                   }
                   else
                   {
                       cout<<a1->data<<" ";
                   }
                   print(a1,t);
}
}
main()
{
      int s,r,m,c,d,e;
      bnode *b,*a,*t;
      a=new bnode;t=new bnode;
      cout<<"enter the data in the head node \n";
      cin>>s;a->data=s;t->data=-1;
      a->fchild=NULL;a->schild=NULL; t->fchild=NULL;t->schild=NULL;
      b=a;
      insert(b);
      print(b,t);
      system("pause");
}                                    
                                    

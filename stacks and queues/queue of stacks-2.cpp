#include<iostream>
using namespace std;
class queue
{
      public:
             int size;
             int front;
             int rear;
             int *elements;
             queue(int);
             queue *s;
            //~queue();
             void enqueue(int);
             int dequeue();
};
queue::queue(int z)
{
                 size=z;elements=new int[35];
}
void queue::enqueue(int x)
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
int queue::dequeue()
{
    int t;
    if(front==-1)
    {
                 cout<<"queue is empty \n";
                 return -1;
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
main()
{
      int i,l,m,a,p;
      cout<<"enter the size of the queue table \n";
      cin>>l;
      queue q(l);//queue *s;
      s=new queue(l);
	  s->front=-1;
	  s->rear=-1;s->enqueue(5);
      cout<<s->elements[0];
     /* q.front=-1;q.rear=-1;
      cout<<"enter the elements u want 2 enter into queue\n";
      cin>>m;
      for(i=0;i<m;i++)
      {
                      cin>>a;
                      q.enqueue(a);
      }
      cout<<"enter the elements to be dequeued \n";
      cin>>p;
      for(i=0;i<p;i++)
      {
                      q.dequeue();               
      }
      cout<<"now enter "<<p<<" elements\n";
      for(i=0;i<1;i++)
      {
                      cin>>a;
                      q.enqueue(a);
      }
      cout<<q.elements[q.front]<<endl;
      cout<<q.elements[q.rear]<<endl;
      if(q.rear>q.front)
      {
      for(i=q.front;i<=q.rear;i++)
      {
                      cout<<"="<< q.elements[i]<<endl;
      }
      }
      else
      {
      for(i=q.front;i<=q.size-1;i++)
      {
                                  cout<<q.elements[i]<<endl;
      }
      for(i=0;i<=q.rear;i++)
      {
                            cout<<q.elements[i]<<endl;
      }
      }*/
	  int t;cin>>t;
}

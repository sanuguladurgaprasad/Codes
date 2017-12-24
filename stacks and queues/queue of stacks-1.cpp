#include<iostream>
using namespace std;
class stack
{
      public:
             int size;
             int top;
             int elements[35];
             void push(int);
           int pop();
             stack(int);
};
class queue
{
      public:
             int size;
             int front;
             int rear;
             stack *elements;
             queue(int);
             void enqueue(stack);
             stack dequeue();
};
stack::stack(int z1)
{
size=z1;top=-1;
}
void stack::push(int x)
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
int stack::pop()
{
     if(top==-1)
     {
                cout<<"stack is empty \n";
     }
     else
     {
         return(elements[top--]);
     }
}
queue::queue(int z)
{
                 size=z;
                 elements = new *stack;
}
void queue::enqueue(stack x)
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
stack queue::dequeue()
{
    stack t(3);
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
queue *q;

stack s(3);
void in()
{
    cout<<"enter the elements in the queue of stacks\n";
    for(int i=0;i<3;i++)
    {
		s.push(i);
	}
}
main()
{
	q= new queue(3);
    in();
    q.enqueue(s);
    //ou();
}

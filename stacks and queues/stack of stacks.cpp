#include<iostream>
using namespace std;
class stack1
{
      public:
             int size;
             int top;
             int elements[35];
             void push(int);
           int pop();
             stack1(int);
};
stack1::stack1(int z)
{
size=z;top=-1;
}
void stack1::push(int x)
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
int stack1::pop()
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
class stack
{
      public:
             int size;
             int top;
             stack1 element[35];
            stack1 r;
             void push(stack1);
           stack1 pop();
             stack(int);
};
stack::stack(int z)
{
size=z;top=-1;
}
void stack::push(stack1 x)
{
     if(top==size-1)
     {
                cout<<"stack is full \n";
     }
     else
     {
     element[++top]=x;
     }
}
stack1 stack::pop()
{
     if(top==-1)
     {
                cout<<"stack is empty \n";
     }
     else
     {
         return(element[top--]);
     }
}stack1 s1(2);
stack s(2);
void in()
{int t;
     cout<<"enter\n";
     for(int i=0;i<2;i++){cin>>t;s.r.push(t);}
}
void ou()
{
     for(int i=0;i<2;i++){cout<<s.r.pop();}
}
main()
{
      for(int i=0;i<2;i++){
      in();}
     for(int i=0;i<2;i++){ 
      ou();}
      int t;
      cin>>t;
}

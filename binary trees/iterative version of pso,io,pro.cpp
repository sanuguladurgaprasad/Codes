#include<iostream>
using namespace std;
struct bnode
{         
       int data;
       int rank;
       bnode *rchild;
       bnode *lchild;
};
class stack
{
      public:
             int size;
             int top;
             bnode **elements;
             void push(bnode*);
             bnode* pop();
             stack(int);
};
stack::stack(int z)
{
size=z;
top=-1;elements=new bnode*[size];
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
}
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
}stack s1(25),s2(25); bnode *a1;   
void print(bnode *b)
{int count=1;
while((s1.top!=-1)||(count==1))
{    count++;
     if(count>2)
     {a1=s1.pop();
     b=a1;}
     while((b!=NULL)&&(b->rank!=-1))
     {
             if(b->rchild!=NULL)
             {s1.push(b->rchild);}
             s1.push(b);b->rank=-1;
             if(b->lchild!=NULL)
             {s1.push(b->lchild);}
             if((s1.elements[s1.top]->lchild==NULL)&&(s1.elements[s1.top]->rchild==NULL)){s1.elements[s1.top]->rank=-1;break;}
             if((s1.elements[s1.top]->lchild!=NULL)||(s1.elements[s1.top]->rchild!=NULL))
             {if(s1.elements[s1.top]->rank!=-1){a1=s1.pop();b=a1;}}
     }
     while(s1.elements[s1.top]->rank==-1)
     {
                       s2.push(s1.pop());
                       if(s1.top==-1)
                       {break;}
     }
}
     while(s2.top!=-1){s1.push(s2.pop());}
     while(s1.top!=-1){cout<<s1.pop()->data<<" ";}
}
main()
{
      bnode *b1,*h1;
      int a,b,c,d,e,f,k;
      h1=(bnode*)new bnode;
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
	  cin>>e;
}

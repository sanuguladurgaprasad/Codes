#include<iostream>
#include<conio.h>
using namespace std;
struct tt
{int data1;
int data2;
tt* lchild;
tt* mchild;
tt* rchild;};
class queue
{
      public:
             int size;
             int front;
             int rear;
             tt *elements[35];
             queue(int);
            //~queue();
             void enqueue(tt*);
             tt* dequeue();
};
queue::queue(int z)
{
                 size=z;front=-1;rear=-1;
}tt *g;
void queue::enqueue(tt* x)
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
tt* queue::dequeue()
{
    tt *t;
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
void swap(int &p,int &q){int d;d=p;p=q;q=d;}
tt* insert(tt *&b,int k)
{if(b!=NULL)
{if(b->data2==-1){b->data2=k;if(b->data2<b->data1){swap(b->data1,b->data2);}}
else if(k<b->data1){b->lchild=insert(b->lchild,k);}
else if((k>b->data1)&&(k<b->data2)){b->mchild=insert(b->mchild,k);}
else{b->rchild=insert(b->rchild,k);}
}
if (b==NULL)
{b=new tt;b->data1=k;b->data2=-1;b->lchild=NULL;b->rchild=NULL;b->mchild=NULL;}return b;
}tt *x;
int min1(tt *b)
{if(b->data2!=-1){
    if(b->data1>b->data2){return b->data2;}
    else {cout<<"}";return b->data1;}
}
else return b->data1;
}
int max1(tt *b)
{if(b->data2!=-1){
    if(b->data1>b->data2){cout<<"l";return b->data1;}
    else {cout<<b->data2;return b->data2;}
}
else {cout<<"*";return b->data1;}
}
tt* min(tt *b)
{
    if(b->lchild==NULL)
    {
            return b;
    }
    else
    {
        x=min(b->lchild);return x;
    }
}
tt* max(tt *b)
{
    if(b->rchild==NULL)
    {cout<<b->data2<<"$";
            if(b->data2!=-1)                      
            {cout<<"u";return b;}
            else if(b->mchild!=NULL){if((b->data1!=-1)&&(b->data2==-1)&&(b->mchild->data1==-1)&&((b->mchild->data2==-1)))
            {return b;}}
            else if((b->mchild!=NULL)&&(b->data2==-1)){x=max(b->mchild);return x;}
            else if((b->data1!=-1)){cout<<"v";return b;}
    }
    else
    {
        x=max(b->rchild);return x;
    }
}
tt *s,*x1;
tt* search(tt *b,int k)
{int n,n1=0;
	if(b->data1==k)
	{
       if((b->lchild==NULL)&&(b->mchild==NULL))
       {b->data1=b->data2;b->data2=-1;b->lchild=b->mchild;
       b->mchild=b->rchild;b->rchild=NULL;cout<<"a";}
       if((n1==0)&&(b->lchild!=NULL)){n1=1;x1=max(b->lchild);n=max1(x1);cout<<n<<"b";}
       if((b->mchild==NULL)&&(n1!=1)){n1=1;n=b->data1;cout<<"c";}
       if((n1==0)&&(b->mchild!=NULL)){x1=min(b->mchild);n1=1;n=min1(x1);cout<<n<<"d";}
       b->data1=n;if((x1->data1==n)&&(x1->data2!=-1)){cout<<"n";x1->data1=x1->data2;x1->data2=-1;x1->lchild=x1->mchild;
       x1->mchild=x1->rchild;x1->rchild=NULL;}
       else if((x1->data1==n)&&(x1->data2==-1)){cout<<"z";x1->data1=-1;}
       else if(x1->data2==n){cout<<"p";x1->data2=-1;}
       return b;
  }
	else if(b->data2==k)
	{
       if((b->mchild==NULL)&&(b->rchild==NULL)){b->data2=-1;cout<<"e";}
       if((n1==0)&&(b->mchild!=NULL)){x1=max(b->mchild);n1=2;cout<<x1->data2;n=max1(x1);cout<<n<<"f";}
       if((b->rchild==NULL)&&(n1==0)){n1=2;n=b->data2;cout<<"g";}
       if((n1==0)&&(b->rchild!=NULL)){x1=min(b->rchild);n1=2;n=min1(x1);cout<<n<<"h";}
       b->data2=n;if((x1->data1==n)&&(x1->data2!=-1)){cout<<"l";x1->data1=x1->data2;x1->data2=-1;x1->lchild=x1->mchild;
       x1->mchild=x1->rchild;x1->rchild=NULL;}
       else if((x1->data1==n)&&(x1->data2==-1)){cout<<"m";x1->data1=-1;}
       else if(x1->data2==n){cout<<"h";x1->data2=-1;}
       return b;
  }
    else if(k<b->data1){s=search(b->lchild,k);}
    else if((k>b->data1)&&(k<b->data2)){s=search(b->mchild,k);}
    else{s=search(b->rchild,k);}return s;
}tt *a1;int k1=0;
void print1(tt *b,tt *r)
{
     if(b!=NULL)
     {
                if(k1==0)
                {
                k1++;q.enqueue(b);q.enqueue(r);
                }
                if(k1>1)
                {
                       if(b->lchild!=NULL){q.enqueue(b->lchild);}
                       if(b->mchild!=NULL){q.enqueue(b->mchild);}
                       if(b->rchild!=NULL){q.enqueue(b->rchild);}
                }k1++;
     }
     if(q.front!=q.rear)
     {
                        a1=q.dequeue();
     if(a1->data1==-12)
     {
     q.enqueue(r);cout<<endl;
     }
     else{cout<<"["<<a1->data1<<","<<a1->data2<<"]";}
     print1(a1,r);
     }
}
void print(tt *b)
{
	if(b!=NULL)
	{
		print(b->lchild);if(((b->data1!=-1))&&(b->data1<10000))
		{cout<<b->data1<<" " <<"L";}
		print(b->mchild);if(((b->data2!=-1))&&(b->data2<10000))
		{cout<<b->data2<<" "<<"J";}
		print(b->rchild);
    }
}
main()
{
	tt *b,*z,*s1,*r;int a=-1,c,j;b=NULL;s=NULL;
	 r=new tt;
      r->data1=-12;
      r->lchild=NULL;r->mchild=NULL;r->rchild=NULL;
	while(a!=0)
	{cout<<"press 1 to enter,2 to print,3 to delete,0 to exit\n";
		cin>>a;
		switch(a)
		{
		case 1:cout<<"enter\n";cin>>c;b=insert(b,c);z=b;break;
		case 2:print(b);cout<<endl;while(q.front!=-1){q.dequeue();}k1=0;print1(b,r);break;
		case 3:cout<<"enter\n";cin>>c;b=z;cout<<b->data1<<"K";s1=search(b,c);
        cout<<s1->data1<<" "<<s1->data2;break;
		default:cout<<"no match found\n";break;
	    }
	}
	cin>>j;
	/*cout<<"enter the no.\n";cin>>j;
	for(a=0;a<j;a++){cin>>c;b=insert(b,c);}
	print(b);cin>>j;*/
}

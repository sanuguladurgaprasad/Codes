#include<iostream>
#include<conio.h>
using namespace std;
struct tt
{int data1;
int data2;
tt* lchild;
tt* mchild;
tt* rchild;};
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
}
int ff(tt *b,int w)
{
	int m;cout<<b->data1;
	static int g=0;
	if((b->lchild!=NULL)&&(w==0)){cout<<"a";w++;b=b->lchild;g=1;}
	if(g==1)
	{if((b->rchild!=NULL)){m=ff(b->rchild,w);}else if(b->data2!=-1){cout<<"b";return b->data2;}
	if(w==1){w++;if(b->data2==-1)
	{cout<<"d";return b->data1;}else{cout<<"c";return b->data2;}}
	else{cout<<"e";return m;}}
	if((b->mchild!=NULL)&&(w==0)){cout<<"f";w++;b=b->mchild;g=2;}
	if(g==2)
	{if(b->lchild!=NULL){m=ff(b->lchild,w);}
	else {cout<<"g";return b->data1;}if(w==1){cout<<"h";w++;return b->data1;}
	else{cout<<"j";return m;}}if(w==0){cout<<"i";return b->data1;}
}
int ff1(tt *b,int w)
{
	int m;
	static int g=0;
	if((b->mchild!=NULL)&&(w==0)){w++;b=b->mchild;g=1;}
	if(g==1)
	{if(b->rchild!=NULL){m=ff1(b->rchild,w);}else if(b->data2!=-1){return b->data2;}
	if(w==1){w++;if(b->data2==-1)
	{return b->data1;}else{return b->data2;}}
	else{return m;}}
	if((b->rchild!=NULL)&&(w==0)){w++;b=b->rchild;g=2;}
	if(g==2)
	{if(b->lchild!=NULL){m=ff1(b->lchild,w);}
	else {return b->data1;}
	if(w==1){w++;return b->data1;}
	else{return m;}}if(w==0){return b->data2;}
}
tt* search1(tt *b,tt *&s,int k)
{
	if(b->data1==k)
	{s=b;}
	else if(b->data2==k)
	{s=b;}
    else if(k<b->data1){search1(b->lchild,s,k);}
    else if((k>b->data1)&&(k<b->data2)){search1(b->mchild,s,k);}
    else{search1(b->rchild,s,k);}
}
tt *l,*l1,*b1;
void search(tt *&b,int k,tt *&s)
{int q;static int w;w=0;
	if(b->data1==k)
	{q=ff(b,w);cout<<q<<"p";l=b;cout<<l->data1<<"M";getch();
	search1(b,s,q);
	if(s->data1==q){l->data1=q;if(s->data2!=-1)
	{s->lchild=s->mchild;s->mchild=s->rchild;s->rchild=NULL;s->data1=s->data2;s->data2=-1;}
	else if((s->data2==-1)&&(s->lchild==NULL)){l1=s;cout<<"u";delete l1;}}
	else if(s->data2==q){l->data1=q;s->data2=-1;}}

	else if(b->data2==k)
	{q=ff1(b,w);cout<<q<<"h";l=b;cout<<l->data2<<"y";getch();
	search1(b,s,q);
	if(s->data1==q){l->data1=q;if(s->data2!=-1)
	{s->lchild=s->mchild;s->mchild=s->rchild;s->rchild=NULL;s->data1=s->data2;s->data2=-1;}
	else if((s->data2==-1)&&(s->lchild==NULL)){delete s;}}
	else if(s->data2==q){cout<<"J";l->data2=q;s->data2=-1;}
    }

    else if(k<b->data1){search(b->lchild,k,s);}
    else if((k>b->data1)&&(k<b->data2)){search(b->mchild,k,s);}
    else{search(b->rchild,k,s);}
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
	tt *b,*z,*s;int a=-1,c,j;b=NULL;s=NULL;
	while(a!=0)
	{cout<<"press 1 to enter,2 to print,3 to delete,0 to exit\n";
		cin>>a;
		switch(a)
		{
		case 1:cout<<"enter\n";cin>>c;b=insert(b,c);z=b;break;
		case 2:print(b);break;
		case 3:cout<<"enter\n";cin>>c;b=z;cout<<b->data1<<"K";search(b,c,s);break;
		default:cout<<"no match found\n";break;
	    }
	}
	cin>>j;
	/*cout<<"enter the no.\n";cin>>j;
	for(a=0;a<j;a++){cin>>c;b=insert(b,c);}
	print(b);cin>>j;*/
}

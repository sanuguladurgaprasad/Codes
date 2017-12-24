#include<iostream>
using namespace std;
struct node2;
struct node1
{
	node1 *next;
	node2 *bot;
	int data;
};
struct node2
{
	node2* bot;
	node1* next;
};
node1 *h;
int z;
node1* insert(node1 *l,int k)
{
	if(l==NULL)
		{   l=new node1;
			l->data=k;
			l->next=l;
			l->bot=NULL;
		}
	else if((z!=0)&&(l==h))
		{	l=new node1;
			l->data=k;
			l->next=h;
			l->bot=NULL;
		}
	else {
			z++;
			l->next=insert(l->next,k);
		}
	return l;
}
node1 *v,*u;
node2 *x,*s;
int r1=0;
node1* fn(node1 *l,int d)
{	v=l;
	s=l->bot;
	if(s==NULL)
		{	r1=1;
			s=new node2;
			s->bot=NULL;
			s->next=NULL;
			l->bot=s;
		}
	else
		{   while(s->bot!=NULL)
				{
					s=s->bot;
				}
			r1=2;
			s->bot=new node2;
			s->bot->bot=NULL;
			s->bot->next=NULL;
		}
	l=v;
	while((l->data!=d))
		{
			l=l->next;
		}
	u=l;
	if(r1==2) {
			s->bot->next=u;
		}
	if(r1==1) {
			s->next=u;
		}
	return v;
}
node1 *b1;
node1 *t;
int n=0,j;
void fn1(node1 *l)
{	node2 *s1;
	if((t->data==l->data)&&(j>0))
		{
			n++;
		}
	else if((t->data<l->data)||(j==0))
		{	s1=l->bot;
			while(s1!=NULL)
				{   j++;
					b1=s1->next;
					//if((b1->data>l->data)||(b1->data==t->data))
						fn1(s1->next);
					s1=s1->bot;
				}
		}
}
main()
{
	int a,i,c,d,b;
	cout<<"enter the no. of vertices u need\n";
	cin>>a;
	node1 *l;
	l=NULL;
	h=NULL;
	for(i=0; i<a; i++)
		{	cout<<"enter the vertices data\n";
			cin>>b;
			z=0;
			l=insert(l,b);
			h=l;
		}
	z=0;
	while((l!=h)||(z==0))
		{	z++;
			cout<<"enter the no. of edges incident frm the vertex"<<l->data<<" \n";
			cin>>b;
			for(i=0; i<b; i++)
				{   z++;
					cout<<"enter the vertex with which u need connection\n";
					cin>>d;
					r1=0;
					l=fn(l,d);
				}
			l=l->next;
		}
	l=h;
	z=0;
	//int f=0;
	while((l!=h)||(z==0))
		{	t=l;j=0;
			z++;r1=0;
			fn1(l);
			l=l->next;
			//f++;
		}
	cout<<"NO. OF CYCLES="<<n;
	cin>>a;
}

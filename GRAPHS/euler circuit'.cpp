#include<fstream>
#include<iostream>
using namespace std;
struct adj
{
	int **a;
};
struct node
{
	int deg;
};
struct ll
{
	int data;
	ll *next;
};
void printlist(ll *l)
{
	//cout<<"  the list contains: \n";
	while(l!=NULL)
		{
			cout<<l->data<<endl;
			l=l->next;
		}
}
ll* add(ll *l,int k)
{
	if(l==NULL)
		{
			l=new ll;
			l->data=k;
			l->next=NULL;
		}
	else {
			l->next=add(l->next,k);
		}
	return l;
}
ll *l1=NULL,*l;
int check(ll *l,node n[])
{	int p=-1;
	l1=NULL;
	if(l!=NULL)
		{
			if((l!=NULL)&&(n[(l->data)-1].deg!=0))
				{
					return (l->data)-1;
				}
			else {
					p=check(l->next,n);
				}
		}
	return p;
}
int y;
ll* l2,*h;
void splice(ll *h)
{	ll *t;
	l2=l1;
	int q;
	if((l!=NULL)&&(l1!=NULL))
		{	while(l2->next!=NULL) {
					l2=l2->next;
				}
			q=l2->data;
			while(l->data!=q)
				{
					l=l->next;
				}
			t=l->next;
			l->next=l1;
			l=h;
			while(l1->next!=NULL) {
					l1=l1->next;
				}
			l1->next=t;
		}
}
//l1 for new lnklist;l for the main ll;
void ec(int c,int d,adj A,node n[],ll *h)
{
	int i,j;
	for(i=0; i<d; i++)
		{
			if((A.a[c][i]!=0)&&(n[c].deg!=0))
				{	A.a[c][i]=0;
					A.a[i][c]=0;
					(n[i].deg)--;
					(n[c].deg)--;
					l1=add(l1,i+1);
					ec(i,d,A,n,h);
					break;
				}
			else if(n[c].deg==0)
				{	splice(h);
					c=check(l,n);
					if(c==-1) {
							break;
						}
					l=h;
					ec(c,d,A,n,h);
					break;
				}
		}
}
/*adj create(adj A,int d,node n[])
{	int i,j;
	(A.a)=new int*[d];
	for(i=0; i<d; i++)
		{
			A.a[i]=new int[d];
		}
	for(i=0; i<d; i++)
		{	int u=0;
			for(j=0; j<d; j++)
				{	cout<<"enter the weight of<"<<i+1<<j+1<<">edge\n";
					cin>>A.a[i][j];
					if(A.a[i][j]!=0)
						{
							u++;
						}
				}
			n[i].deg=u;
		}
	return A;
}*/
main()
{	ifstream fin;
	fin.open("untitled.txt");
	int c,i,j,d;
	adj A;
	l=new ll;
	cout<<"enter the no. of vertices\n";
	cin>>d;
	node n[d];
	(A.a)=new int*[d];
	for(i=0; i<d; i++)
		{
			A.a[i]=new int[d];
		}
	for(i=0; i<d; i++)
		{	int u=0;
			for(j=0; j<d; j++)
				{	//cout<<"enter the weight of<"<<i+1<<j+1<<">edge\n";
					fin>>A.a[i][j];
					cout<<A.a[i][j]<<endl;
					if(A.a[i][j]!=0)
						{
							u++;
						}
				}
			n[i].deg=u;
		}
	//A=create(A,d,n);
	cout<<"enter starting vertex no.(integer)\n";
	cin>>c;
	l->data=c;
	l->next=NULL;
	h=l;
	ec(c-1,d,A,n,h);
	cout<<"the euler circuit is in the order of\n";//printlist(l1);
	printlist(l);
	fin.close();
	cin>>d;
}

#include<fstream>
#include<iostream>
using namespace std;
struct adj
{
	int **a;
};
struct node
{
	char data;
	int vis;
	int pn;//postorder numbering;
};
void swap(int *p,int *q)
{
	int *g=p;
	p=q;
	q=g;
}
adj reverse(adj A,int d)
{	int i,j;
	for(i=0; i<d; i++)
		{	for(j=0; j<d; j++)
				{	if(((A.a[i][j]!=0)||(A.a[j][i]!=0))&&(i<j))
						{
							swap(A.a[i][j],A.a[j][i]);
						}
				}
		}
	return A;
}
int t=0,m=0;
int x;
int max1(node n[],int d)
{	int i,max=INT_MIN;
	for(i=0; i<d; i++)
		{
			if(max<n[i].pn) {
					max=n[i].pn;
				}
		}
	x=max;
	for(i=0; i<d; i++)
		{
			if(n[i].pn==max)
				{
					return i;
					break;
				}
		}
}
int deg(node n[],adj A,int d,int c)
{	int y=0;
	for(int i=0; i<d; i++) {
			if(A.a[c][i]==0) {
					y++;
				}
		}
	if(y==d) {
			return 1;
		}
	else return 0;
}
int start;
int a1=0,a2=0,a3=0;
void dft(int c,int d,adj A,node n[])
{int i,j;
	for(i=0; i<d; i++)
		{	n[c].vis=1;
			if((A.a[c][i]!=0)&&(n[i].vis!=1))
				{dft(i,d,A,n);
					if(m==0) {
							n[i].pn=++t;
						}
					else {
							cout<<n[i].data<<",";
							n[i].pn=0;
						}
				}
		}
	if((deg(n,A,d,c)==1)&&(c==start)) {
			n[start].vis=1;
			a3=1;
		}
	else if((c==start)&&(t>0)) {
			a3=1;
		}
	if(a3==1) {
			for(i=0; i<d; i++)
				{	a3++;
					a2++;
					if((i==0)&&(a2==1))
						{
							n[start].pn=++t;
							start=-1;
						}
					if(n[i].vis!=1)
						{	dft(i,d,A,n);
							n[i].pn=++t;
						}
						if(t==d) {
									a1=1;
									++t;
									break;
								}
				}
		}
	if(a1==1) {
			a1=0;
			for(i=0; i<d; i++)
				{
					n[i].vis=0;
				}
			m=1;
			A=reverse(A,d);
			c=max1(n,d);
			cout<<"{"<<n[c].data<<",";
			n[c].pn=0;;
			dft(c,d,A,n);
			cout<<"}"<<endl;
			for(i=0; i<d; i++)
				{
					c=max1(n,d);
					if(x==0) {
							break;
						}
					cout<<"{"<<n[c].data<<",";
					n[c].pn=0;
					dft(c,d,A,n);
					cout<<"}"<<endl;
				}
		}
}
void input(node n[],int d)
{	char s='a';
	for(int i=0; i<d; i++)
		{
			n[i].data=s;
			s++;
		}
}
int find(node n[],int s,int d)
{
	for(int i=0; i<d; i++)
		{
			if(n[i].data==s) {
					return i;
				}
		}
}
adj begin(ifstream& fin,adj A,int d)
{	int i,j;
	(A.a)=new int*[d];
	for(i=0; i<d; i++)
		{
			A.a[i]=new int[d];
		}
	for(i=0; i<d; i++)
		{	for(j=0; j<d; j++)
				{	fin>>A.a[i][j];
					cout<<A.a[i][j];
				}
			cout<<endl;
		}
	return A;
}
main()
{	ifstream fin;
	fin.open("pi.cpp");
	int c,i,j,d;
	char s;
	adj A;
	cout<<"enter the no. of vertices\n";
	cin>>d;
	node n[d];
	input(n,d);
	for(i=0; i<d; i++)
		{
			n[i].vis=0;
		}
	A=begin(fin,A,d);
	cout<<"enter starting vertex\n";
	cin>>s;
	c=find(n,s,d);
 cout<<c;
	start=c;
	cout<<"The strong components are:\n";
	dft(c,d,A,n);
	fin.close();
	cin>>d;
}

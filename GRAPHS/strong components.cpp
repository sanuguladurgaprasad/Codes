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
void dft(int c,int d,adj A,node n[])
{	//int m1=-1,m2;
	int i,j;
	for(i=0; i<d; i++)
		{	n[c].vis=1;
			if((A.a[c][i]!=0)&&(n[i].vis!=1))
				{	dft(i,d,A,n);//m1=0;m2=i;
					if(m==0) {
							n[i].pn=++t;
						}
					else {
							cout<<n[i].data<<",";
							n[i].pn=0;
						}
				}//else{m1=-1;}
		}//if((m==0)&&(m1==0)){cout<<"T";n[m2].pn=++t;m1=-1;cout<<n[m2].data<<t<<"N";}
}
void input(node n[],int d)
{	char s='a';
	cout<<"enter data in to the vertices";
	for(int i=0; i<d; i++)
		{
			n[i].data=s;
			s++;
		}
}
void swap(int *p,int *q)
{
	int *g=p;
	p=q;
	q=g;
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
	dft(c,d,A,n);
	n[c].pn=++t;
	for(i=0; i<d; i++)
		{
			if(n[i].vis!=1)
				{	dft(i,d,A,n);
					n[i].pn=++t;
				}
		}
	for(i=0; i<d; i++)
		{
			cout<<n[i].data<<n[i].pn<<endl;
		}
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
	cout<<"are the strong components\n";
	cin>>d;
}

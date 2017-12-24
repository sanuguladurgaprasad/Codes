#include<iostream>
using namespace std;
struct adj
{
	int **a;
};
struct knode
{
	int fst;//fst vertex and 2nd vertex
	int sec;
	int data;
};
void swap(knode &p,knode &q)
{
	knode t=p;
	p=q;
	q=t;
}
void fn(knode h[],int k)
{
	if(k!=-1)
		{
			{	if(k%2!=0)
					{
						if(h[k].data<h[k/2].data) {
								swap(h[k],h[k/2]);
							}
						fn(h,k-1);
					}
				else
					{	if(h[k].data<h[(k-1)/2].data)
							{
								swap(h[k],h[(k-1)/2]);
							}
						fn(h,k-1);
					}
			}
		}
}
void create(adj A,knode h[],int size,int n)
{	int k=0,i=0,j=0;
	for(k=0; k<n; k++)
		{
			for(j=0; j<n; j++)
				{	if((A.a[k][j]!=0)&&(j>k))
						{
							h[i].data=A.a[k][j];
							h[i].fst=k+1;
							h[i].sec=j+1;
							fn(h,i);
							i++;
						}
				}
		}
}
int N=0;
int find(int i,int s[])
{
	if(s[i]==-1)
		{
			return i;
		}
	else
		{
			return (find(s[i],s));
		}
}
void un(int i,int j,int s[])
{
	if(s[j]==-1)
		{
			s[j]=i;
		}
	else
		{
			s[find(i,s)]=find(j,s);
		}
}
void cal(knode h[],int size,int s[])
{	int i=0;
	while(size!=0)
		{	if(find(h[0].fst-1,s)!=find(h[0].sec-1,s))
				{
					N=N+h[0].data;
					un(find(h[0].fst-1,s),find(h[0].sec-1,s),s);
				}
			h[0]=h[size-1];
			size--;
			i++;
			fn(h,size-1);
		}
}
main()
{
	knode *h;
	cout<<"enter no. of edges\n";
	int i,c,m,n,g,d,j;
	cin>>m;
	h=new knode[m];
	adj A;
	cout<<"enter the no. of vertices\n";
	cin>>n;
	int s[n];//set for mappings;
	for(i=0; i<m; i++) {
			s[i]=-1;
		}
	cout<<"enter the wieghts to the edges\n";
	(A.a)=new int*[n];
	for(i=0; i<n; i++)
		{
			A.a[i]=new int[n];
		}
	for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
				{	cout<<"enter the weight of<"<<i+1<<j+1<<">edge\n";
					cin>>A.a[i][j];
				}
		}
	create(A,h,m,n);
	cal(h,m,s);
	cout<<"the minimum spanning tree length is="<<N;
	cin>>i;
}

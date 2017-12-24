#include<iostream>
using namespace std;
struct adj
{
	int **a;
};
struct pmnode
{
	int vis;
	int dist;
};
int min(int p,int q)
{
	if(p>q) {
			return q;
		}
	else return p;
}
int minimum(pmnode pm[],int n)
{	int min=1000,h;
	for(int i=1; i<n; i++)
		{	if((pm[i].vis!=1)&&(min>pm[i].dist))
				{
					min=pm[i].dist;
				}
		}
	for(h=0; h<n; h++)
		{	if((pm[h].vis!=1)&&(min==pm[h].dist))
				{
					break;
				}
		}
	return h;
}
void fn(adj A,pmnode pm[],int n)
{	int i,j,k=0;
	for(i=0; i<n; i++)
		{
			pm[i].vis=-1;
			pm[i].dist=1000;
		}
	i=0;
	while(k<n)
		{
			if(pm[i].vis!=1)
				{	pm[i].vis=1;
					for(j=0; j<n; j++)
						{
							if((A.a[i][j]!=0)&&(pm[j].vis!=1))
								{
									pm[j].dist=min(pm[j].dist,A.a[i][j]);
								}
						}
					i=minimum(pm,n);
					k++;
				}
		}
}
adj create(adj A,int n)
{	int i,j;
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
	return A;
}
void output(pmnode pm[],int n)
{	int i,N=0;
	for(i=1; i<n; i++)
		{
			N=N+pm[i].dist;
		}
	cout<<"the min spanning tree length is "<<N;
}
main()
{
	int c,n;
	adj A;
	cout<<"enter the no. of vertices\n";
	cin>>n;
	pmnode pm[n];
	A=create(A,n);
	fn(A,pm,n);
	output(pm,n);
	cin>>n;
}

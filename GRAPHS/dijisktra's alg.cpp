#include<iostream>
using namespace std;
struct adj
{
	int **a;
};
struct djnode
{
	int via;
	int vis;
	int dist;
};
int minimum(djnode dj[],int n)
{	int min=1000,h;
	for(int i=1; i<n; i++)
		{	if((dj[i].vis!=1)&&(min>dj[i].dist))
				{
					min=dj[i].dist;
				}
		}
	for(h=0; h<n; h++)
		{	if((dj[h].vis!=1)&&(min==dj[h].dist))
				{
					break;
				}
		}
	return h;
}
void fn(adj A,djnode dj[],int n,int s,int d)
{	int i,j;
	s=s-1;
	d=d-1;
	for(i=0; i<n; i++)
		{
			dj[i].vis=-1;
			dj[i].dist=1000;
		}
	i=0;
	dj[s].dist=0;
	while(s!=d)
		{
			if(dj[s].vis!=1)
				{	dj[s].vis=1;
					for(j=0; j<n; j++)
						{
							if((A.a[s][j]!=0)&&(dj[j].vis!=1))
								{
									if(dj[j].dist>dj[s].dist+A.a[s][j]) {
											dj[j].dist=dj[s].dist+A.a[s][j];
											dj[j].via=s+1;
										}
								}
						}
					s=minimum(dj,n);
				}
		}
}
void fn1(djnode dj[],int d)
{
	if(dj[d-1].dist!=0) {
			fn1(dj,dj[d-1].via);
			cout<<dj[d-1].via<<",";
		}
}
main()
{
	int i,c,n,s,g,d,j;
	adj A;
	cout<<"enter the no. of vertices\n";
	cin>>n;
	djnode dj[n];
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
	cout<<"enter the source and destination\n";
	cin>>s>>d;
	fn(A,dj,n,s,d);
	cout<<"the shortest path is="<<dj[d-1].dist<<" via ";
	fn1(dj,d);
	cin>>n;
}

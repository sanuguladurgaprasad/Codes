#include<fstream>
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
}int s[7];
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
int find(int i)
{
	if((s[i]==-1)||(s[i]==i))
		{
			return i;
		}
	else
		{
			return (find(s[i]));
		}
}
void un(int i,int j)
{
	if(s[j]==-1)
		{
			s[j]=i;
		}
	else
		{
			s[find(i)]=find(j);
		}
}
int dg(adj A,int k,int n)
{int u=0;
	for(int i=0;i<n;i++)
	{
			if(A.a[k][i]!=0)
			{u++;}
	}
	return u;
}
int cou(int t,int n)
{int u=0;
	for(int i=0;i<n;i++)
	{
			if((s[i]==t)&&(t!=-1)){u++;}
	}
	if(u==7){return 0;}
	else return 1;
}
int key,size,N=0;
knode *h;
void create(adj A,int n)
{    int k=0,i,l=0,j=0;
  while(cou(s[0],n)!=0)
  {  i=0;
     size=dg(A,k,n);
     h=new knode[10];
	    while()
		{
                for(j=0;j<n;j++)
				{	if(A.a[k][j]!=0)
						{A.a[k][j]=0;
							h[i].data=A.a[k][j];
							h[i].fst=k+1;
							h[i].sec=j+1;
							fn(h,i);
							i++;
						}
				}
	    }size=i;
				while(size!=0)
		        {	if(find(h[0].fst-1)!=find(h[0].sec-1))
				    {
						if(s[h[0].fst-1]!=h[0].sec-1)
						{
						cout<<"("<<h[0].fst-1<<","<<h[0].sec-1<<")";
						N=N+h[0].data;
						}
					    un(find(h[0].fst-1),find(h[0].sec-1));
					}
		        }
   }
}
main()
{ifstream fin;
fin.open("Untitled2.cpp");
	cout<<"enter no. of edges\n";
	int i,c,m,n,g,d,j;
	fin>>m;
	adj A;
	cout<<"enter the no. of vertices\n";
	fin>>n;
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
					fin>>A.a[i][j];
				}
		}
	cout<<"the min span tree with edges ";
    create(A,n);
	cout<<"and with length ="<<N;
	cin>>i;
}

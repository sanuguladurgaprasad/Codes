#include<fstream>
#include<iostream>
using namespace std;
struct adj
{
	int **a;
	int **b;
};
struct node
{
	char data;
	int ap;//whether it is a articulation point
	int vis;
	int pn;
	int low;
};int a1[7];
int min(int p,int q)
{
if(p>q){return q;}
else {return p;}
}
int find(node n[],int s,int d)
{
	for(int i=0;i<d;i++)
	{
	 		if(n[i].data==s){return i;}
	}
}int g;//for accessing indexes of array 'a1'
int deg(node n[],adj A,int d,int c,int tag)
{int y=0;
 	for(int i=0;i<d;i++){if((A.a[c][i]==0)&&(tag==0)){y++;}if((A.b[c][i]==0)&&(tag==1)){y++;}}
 	if(y==d){return 1;}
 	else return 0;
}int b=-1;
int t=0,start=-1,cou=0,kou=0;
void dft(int c,int d,adj A,node n[])
{int i,j;
     for(i=0;i<d;i++)
	 {n[c].vis=1;
	 if((A.a[c][i]==1)&&(n[i].vis!=1))
	 {A.a[i][c]=0;A.a[c][i]=0;
		 n[i].pn=++t;
		 n[i].low=n[i].pn;
         dft(i,d,A,n);
		 if((c==start)&&(deg(n,A,d,c,0)==1)){break;}
         n[c].low=min(n[i].low,n[c].low);
         if(n[i].low>=n[c].pn)
         {cou++;n[c].ap=1;cout<<n[c].data<<",";}
	 }
	 else if((A.a[c][i]==1)&&(n[i].vis==1)&&(n[i].pn<n[c].pn))
     {A.a[i][c]=0;A.a[c][i]=0;
	 n[c].low=min(n[i].pn,n[c].low);
	 }
	 }
}
void input(node n[],int d)
{char s='a';
for(int i=0;i<d;i++)
         {
 		n[i].data=s;s++;
		 }
}
adj begin(ifstream& fin,adj A,int d)
{int i,j;
 	(A.a)=new int*[d];
	for(i=0; i<d; i++)
		{
			A.a[i]=new int[d];
		}
	for(i=0; i<d; i++)
		{	for(j=0; j<d; j++)
				{	fin>>A.a[i][j];cout<<A.a[i][j];
				}
		}return A;
}
void dft1(int c,int d,adj A,node n[])
{
	 int i,j;
     for(i=d-1;i>=0;i--)
	 {
	 {n[c].vis=1;}
	 if((A.b[c][i]!=0)&&(n[i].vis!=1))
	 {if(b==0){b=-1;a1[g]=i;break;}
                    {dft1(i,d,A,n);}
	 }
	 }
}
adj copy(adj A,int d)
{int i,j;
 	(A.b)=new int*[d];
	for(i=0; i<d; i++)
		{
			A.b[i]=new int[d];
		}
	for(i=0; i<d; i++)
		{	for(j=0; j<d; j++)
				{	A.b[i][j]=A.a[i][j];
				}
		}return A;
}
main()
{	ifstream fin;
	fin.open("xx.cpp");
	int c,i,j,d;
	char s;
	adj A;
	cout<<"enter the no. of vertices\n";
	cin>>d;
	node n[d];
	input(n,d);
	for(i=0;i<d;i++)
    {n[i].vis=0;}
    cout<<"enter the values into a adjacency matrix frm file xx.cpp\n";
    A=begin(fin,A,d);
    A=copy(A,d);
	  cout<<"enter starting vertex\n";
	  cin>>s;
	  c=find(n,s,d);
	  cout<<"the articulation points are:";
	  n[c].pn=++t;n[c].low=n[c].pn;
	  start=c;
	  dft(c,d,A,n);
	  for(i=0;i<d;i++)
      {
	  n[i].vis=0;}
	  if(cou!=0){cout<<"\nthe given graph is not a biconnected graph\n";}
	  else{cout<<"the graph is biconnected";}
	   for(i=0;i<d;i++)
      {
	  n[i].vis=0;}g=0;
	  for(i=d-1;i>=0;i--)
	  {if(n[i].ap==1)
	  {b=0;dft1(i,d,A,n);g++;}}
	  cout<<"there should be an edge between "<<n[a1[0]].data<<" and "<<n[a1[1]].data<<" for the biconnectivity";
	  cin>>d;
}

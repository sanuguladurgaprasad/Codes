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
	int ap;
	int vis;
	int pn;
	int low;
};
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
}
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
cout<<"enter data in to the vertices";
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
				{	fin>>A.a[i][j];
				}
		}return A;
}
void dft1(int c,int d,adj A,node n[])
{
	 int i,j;
     for(i=0;i<d;i++)
	 {if((n[c].ap!=1)||(c==start))
	 {n[c].vis=1;}
	 if((A.b[c][i]!=0)&&(n[i].vis!=1))
	 {
         if((n[i].low<n[c].pn)||(c==start))
	        {A.b[i][c]=0;A.b[c][i]=0;cout<<n[c].data<<",";if(deg(n,A,d,i,1)==1){cout<<n[i].data<<"\n";}}
	     else{cout<<n[c].data<<endl;start=c;i=c;}
                    {dft1(i,d,A,n);}
	 }
	 else if((A.b[c][i]==1)&&(n[i].vis==1))
     {A.b[i][c]=0;A.b[c][i]=0;if(deg(n,A,d,c,1)==1){cout<<n[c].data<<"\n";}}
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
	  cout<<"the biconnected components are\n";
	   for(i=0;i<d;i++)
      {
   n[i].vis=0;}
	  start=c;
	  dft1(c,d,A,n);
	  cin>>d;
}

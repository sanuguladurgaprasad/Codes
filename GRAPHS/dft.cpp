#include<fstream>
#include<iostream>
using namespace std;
struct adj
{
	   int **a;
};
struct node
{
	   int vis;
};
int t;
void dft(int c,int d,adj A,node n[])
{
	 int i,j;n[c].vis=1;
     for(i=0;i<d;i++)
	 {
	 if((A.a[c][i]!=0)&&(n[i].vis!=1))
	 {
           cout<<i+1<<"-";cout<<++t<<endl;
		   dft(i,d,A,n);
	 }
	 }
	  for(i=0;i<d;i++)
	  {if(n[i].vis!=1)
	  {cout<<i+1<<"-"<<++t<<"\n";dft(i,d,A,n);}}
}
main()
{
	  ifstream fin;int g;
	  cout<<"directed press 0 else 1\n";cin>>g;
	  if(g==0){fin.open("pi.cpp");}
	  if(g==1){fin.open("untitled3.txt");}
	  int i,j,b,c,d;
	  adj A;
	  cout<<"enter the no. of vertices\n";
	  cin>>d;
	  node *n;
	  n=new node[d];
	  for(i=0;i<d;i++)
	  {n[i].vis=0;}
	  (A.a)=new int*[d];
	  for(i=0;i<d;i++)
	  {
		   A.a[i]=new int[d];
	  }
	  for(i=0;i<d;i++)
	  {
					  for(j=0;j<d;j++)
					  {
									  fin>>A.a[i][j];cout<<A.a[i][j]<<endl;
 				      }
	  }
	  cout<<"enter starting vertex\n";
	  cin>>c;cout<<c<<"-"<<++t<<"\n";
	  dft(c-1,d,A,n);
	  /*for(i=0;i<d;i++)
	  {if(n[i].vis!=1)
	  {cout<<i+1<<"-"<<++t<<"\n";dft(i,d,A,n);}}*/
	  cin>>i;
	  fin.close();
}

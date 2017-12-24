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
	//char parent;
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
}int g;//for array index
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
	    // n[i].parent=n[c].data;
         dft(i,d,A,n);cout<<b<<"P";if(b==0){cout<<"K"<<i;b=-1;a1[g]=i;}
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
     //cout<<A.a[i][j];cout<<endl;
				}
		}return A;
}char q[20];int w=0;
void dft1(int c,int d,adj A,node n[])
{
	 int i,j;
     for(i=0;i<d;i++)
	 {if((n[c].ap!=1)||(c==start))
	 {n[c].vis=1;}//cout<<"N";
	 if((A.b[c][i]!=0)&&(n[i].vis!=1))
	 {//cout<<"M";
	 //cout<<n[i].low<<n[c].pn<<"M";
         if((n[i].low<n[c].pn)||(c==start))
	        {A.b[i][c]=0;A.b[c][i]=0;q[w]=n[c].data;w++;cout<<n[c].data<<",";if(deg(n,A,d,i,1)==1)
			{q[w]=n[c].data;w++;q[w]='*';w++;cout<<n[i].data<<"\n";}}
	     else{q[w]=n[c].data;w++;q[w]='*';w++;cout<<n[c].data<<endl;start=c;i=c;}
                    {dft1(i,d,A,n);}
	 }
	 else if((A.b[c][i]==1)&&(n[i].vis==1))
     {A.b[i][c]=0;A.b[c][i]=0;if(deg(n,A,d,c,1)==1){q[w]=n[c].data;w++;q[w]='*';w++;cout<<n[c].data<<"\n";}}
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
     //cout<<A.b[i][j];cout<<endl;
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
	  n[i].vis=0;cout<<n[i].data<<n[i].pn<<n[i].low<<"\n";}
	  if(cou!=0){cout<<"\nthe given graph is not a biconnected graph\n";}
	  else{cout<<"the graph is biconnected";}
	  cout<<"the biconnected components are\n";
	   for(i=0;i<d;i++)
      {
	  n[i].vis=0;
	  }g=0;
	  start=c;
	  dft1(c,d,A,n);
	  for(int i=0;i<20;i++){cout<<q[i]<<" ";}
	  cin>>d;
}

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
	char parent;
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
int deg(node n[],adj A,int d,int c)
{int y=0;//cout<<"U";
 	for(int i=0;i<d;i++){if(A.a[c][i]==0){y++;}}
 	if(y==d){return 1;}
 	else return 0;
}char *b;
int t=0,start=-1,cou=0,kou=0;
void dft(int c,int d,adj A,node n[])
{int i,j;
     for(i=0;i<d;i++)
	 {n[c].vis=1;
	 if((A.a[c][i]==1)&&(n[i].vis!=1))
	 {//cout<<n[c].data<<n[i].data<<"M\n";
		 A.a[i][c]=0;A.a[c][i]=0;
		 n[i].pn=++t;
		 n[i].low=n[i].pn;
	     n[i].parent=n[c].data;
         dft(i,d,A,n);
       //cout<<"B"<<c<<deg(n,A,d,c)<<endl;
         n[c].low=min(n[i].low,n[c].low);//cout<<n[c].low<<"p\n";
         if(n[i].low>=n[c].pn)
         {cou++;cout<<n[c].data<<",";}
	 cout<<n[c].low<<n[i].low<<"X\n";
         if(n[c].low==n[i].low)
         {b[kou]=n[i].data;kou++;}
         if(n[c].low!=n[i].low){b[kou]=n[c].data;kou++;b[kou]=n[i].data;kou++;b[kou]='*';kou++;}
         if((c==start)&&(deg(n,A,d,c)==1)){b[kou]=n[c].data;break;}
	 }
	 else if((A.a[c][i]==1)&&(n[i].vis==1)&&(n[i].pn<n[c].pn))
     {//cout<<n[c].data<<n[i].data<<"L\n";
	  	 A.a[i][c]=0;A.a[c][i]=0; n[c].low=min(n[i].pn,n[c].low);//cout<<n[c].low<<"q\n";
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
}
main()
{	ifstream fin;
	fin.open("xx.cpp");
	int c,i,j,d;
	char s;
	adj A;
	cout<<"enter the no. of vertices\n";
	cin>>d;
	b=new char[d*d];
	for(int i=0;i<d*d;i++){b[i]='&';}
	node n[d];
	input(n,d);
	for(i=0;i<d;i++)
    {n[i].vis=0;}
    A=begin(fin,A,d);
	  cout<<"enter starting vertex\n";
	  cin>>s;
	  c=find(n,s,d);
	  cout<<"the articulation points are:";
	  n[c].pn=++t;n[c].low=n[c].pn;
	  start=c;
	  dft(c,d,A,n);
	  /*for(i=0;i<d;i++)
      {cout<<n[i].data<<n[i].low<<"\n";}*/
	  for(i=0;i<d;i++)
      {
	  n[i].vis=0;}
	  if(cou!=0){cout<<"\nthe given graph is not a biconnected graph\n";}
	  else{cout<<"the graph is biconnected";}
	  cout<<"the biconnected components are\n";i=0;
	  while(b[i]!='&')
	  {cout<<b[i];i++;}
	  cin>>d;
}

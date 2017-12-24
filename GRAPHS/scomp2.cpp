#include<fstream>
#include<iostream>
#include<cctype>
using namespace std;
struct adj
{
	int **a;
};
struct node
{
	char data;
	int vis;
	int dg;
	int low;
	int pn;//postorder numbering;
};
int min(int p,int q)
{
if(p>q){return q;}
else {return p;}
}
int deg(node n[],adj A,int d,int c)
{int y=0;
 	for(int i=0;i<d;i++){if(A.a[c][i]==0){y++;}}
 	if(y==d){return 1;}
 	else return 0;
}char r1='$';
int t=0,start=-1,r;
void dft(int c,int d,adj A,node n[])
{int i,j;
     for(i=0;i<d;i++)
	 {n[c].vis=1;
	 if((A.a[c][i]==1)&&(n[i].vis!=1))
	 {A.a[c][i]=0;
		 n[i].pn=++t;
		 n[i].low=n[i].pn;
	    // n[i].parent=n[c].data;
         dft(i,d,A,n);
		 //if((c==start)&&(deg(n,A,d,c)==1)){break;}
         n[c].low=min(n[i].low,n[c].low);//since it has back edges
         if((c!=start)&&(n[i].low>=n[c].pn))
         {cout<<n[c].data<<"M\n";}
         else{cout<<n[c].data<<"H,";}
         if((n[i].dg==0)){cout<<n[i].data<<"B\n";}
	 }
	 else if((A.a[c][i]==1)&&(n[i].vis==1)&&(n[i].pn<n[c].pn))
     {A.a[c][i]=0;if(r1=='$'){cout<<n[c].data<<"S,";
     n[c].low=min(n[i].low,n[c].low);}
     else if(isalpha(r1))
		  {if((n[i].pn>=r)&&(n[c].pn>=r)){
		  if(n[c].pn>n[i].pn)
		  {cout<<n[c].data<<"A,";n[c].low=min(n[i].pn,n[c].low);}}
		   	  // else {n[c].low=min(n[i].pn,n[c].low);}
     }
	 }
	 }
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
int find(node n[],int s,int d)
{
	for(int i=0; i<d; i++)
		{
			if(n[i].data==s) {
					return i;
				}
		}
}
adj begin(ifstream& fin,adj A,int d,node n[])
{	int i,j,u;
	(A.a)=new int*[d];
	for(i=0; i<d; i++)
		{
			A.a[i]=new int[d];
		}
	for(i=0; i<d; i++)
		{	u=0;for(j=0; j<d; j++)
				{	fin>>A.a[i][j];if(A.a[i][j]!=0){u++;}
					cout<<A.a[i][j];
				}n[i].dg=u;
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
	A=begin(fin,A,d,n);
	cout<<"enter starting vertex\n";
	cin>>s;
	c=find(n,s,d);start=c;
	n[c].pn=++t;n[c].low=n[c].pn;
	dft(c,d,A,n);
	for(i=0; i<d; i++)
		{
			if(n[i].vis!=1)
				{cout<<endl;start=i;n[i].pn=++t;r1=n[i].data;
				 	r=n[find(n,n[i].data,d)].pn;dft(i,d,A,n);
				}
		}
	for(i=0; i<d; i++)
		{
			cout<<endl<<n[i].data<<n[i].pn<<n[i].low;
		}
	cout<<"are the strong components\n";
	cin>>d;
}

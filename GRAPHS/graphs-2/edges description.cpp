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
	int pn;//postorder numbering;
};
struct ll
{
       char s;
       char e;
       ll *next;
};
void printlist(ll *l)
{
     while(l!=NULL)
     {
                   cout<<"("<<l->s<<","<<l->e<<")"<<endl;
                   l=l->next;
     }
}
int t=0,r;char r1='$';;
ll* add(ll *l,int k,int j)
{
     if(l==NULL)
     {
     l=(ll*)new node;
     l->s=k;
     l->e=j;
     l->next=NULL;
	 }
	 else
	 {l->next=add(l->next,k,j);}
	 return l;
}
int find(node n[],int s,int d)
{
	for(int i=0;i<d;i++)
	{
	 		if(n[i].data==s){return i;}
	}
}int e=0;
ll *l1=NULL,*l2=NULL,*l3=NULL,*l4=NULL;
//l1=tree;l2=fwd;l3=back;l4=cross;
void dft(int c,int d,adj A,node n[])
{
	 int i,j;
     for(i=0;i<d;i++)
	 {n[c].vis=1;
	 if((A.a[c][i]!=0)&&(n[i].vis!=1))
	 {n[i].pn=++t;
         l1=add(l1,n[c].data,n[i].data);
         dft(i,d,A,n);
	 }
	 else if((A.a[c][i]!=0)&&(n[i].vis==1))
     {
		  if(r1=='$'){
		  if(n[c].pn<n[i].pn)
		  {l2=add(l2,n[c].data,n[i].data);}
		  else if(n[c].pn>n[i].pn)
		  {l3=add(l3,n[c].data,n[i].data);e++;}
		  }
		  else if(isalpha(r1))
		  {
		   	   if((n[i].pn>=r)&&(n[c].pn>=r)){
		  if(n[c].pn<n[i].pn)
		  {l2=add(l2,n[c].data,n[i].data);e++;}
		  else if(n[c].pn>n[i].pn)
		  {l3=add(l3,n[c].data,n[i].data);}}
		   	   else {l4=add(l4,n[c].data,n[i].data);}
     }
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
				{	fin>>A.a[i][j];
				}
		}return A;
}
main()
{	ifstream fin;
	fin.open("pi.cpp");
	int c,i,j,d;
	char s1;
	adj A;
	cout<<"enter the no. of vertices\n";
	cin>>d;
	node n[d];
	input(n,d);
	for(i=0;i<d;i++)
    {n[i].vis=0;}
    cout<<"enter the values into adjacency matrix from file pi.cpp\n";
    A=begin(fin,A,d);
	  cout<<"enter starting vertex\n";
	  cin>>s1;
	  c=find(n,s1,d);
	  n[c].pn=++t;
	  dft(c,d,A,n);
	  for(i=0;i<d;i++)
	  {
	        if(n[i].vis!=1)
	        {n[i].pn=++t;r1=n[i].data;cout<<find(n,n[i].data,d);
			r=n[find(n,n[i].data,d)].pn;
			cout<<r;dft(i,d,A,n);
	        }
	  }
	  cout<<"tree adges are\n";printlist(l1);
      cout<<"fwd adges are\n";printlist(l2);
      cout<<"back adges are\n";printlist(l3);
      cout<<"cross adges are\n";printlist(l4);
      if(e==0){cout<<"the graph is acyclic\n";}
      else{cout<<"the graph is cyclic\n";}
	cin>>d;
}

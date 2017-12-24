#include<fstream>
#include<iostream>
using namespace std;
struct adj
{
	int **a;
};
struct ll
{
	int data;
	ll *next;
};
void printlist(ll *l)
{
	cout<<"{";
	while(l!=NULL)
		{
			cout<<l->data<<",";
			l=l->next;
		}cout<<"}";
}ll *l=NULL;
ll* add(ll *l,int k)
{
	if(l==NULL)
		{
			l=new ll;
			l->data=k;
			l->next=NULL;
		}
	else {
			l->next=add(l->next,k);
		}
	return l;
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
     cout<<A.a[i][j];cout<<endl;
				}
		}return A;
}
int t=0;
void topsort(adj A,int d)
{int i,j,count;
for(i=0;i<d;i++){count=0;
	for(j=0;j<d;j++)
	{
            if(A.a[j][i]==0){count++;}
    }
	if(count==d){l=add(l,i+1);t++;break;}
                }
                if(t!=d){
 for(j=0;j<d;j++)
 {A.a[i][j]=0;}
 for(j=0;j<d;j++){
 A.a[j][i]=-1;}//since the loop A.a[i][j]==0 repeats
 topsort(A,d);}
}
main()
{	ifstream fin;
    fin.open("dip.cpp");
	int c,i,j,d;
	char s;
	adj A;
	cout<<"enter the no. of vertices\n";
	cin>>d;
    A=begin(fin,A,d);
    topsort(A,d);
    printlist(l);
    cin>>d;
}

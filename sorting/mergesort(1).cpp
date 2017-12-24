#include<iostream>
using namespace std;
void swap(int &p,int &q)
{int t=p;
	 p=q;
	 q=t;
}
void print(int c[],int a)
{int i;
      for(i=0;i<a;i++)
	  {
	   				  cout<<c[i]<<" ";
	  }
	  cout<<endl;
}
int c[8];
void merge(int A[],int l,int m,int h)
{int i,j,k=0;
	 for(i=l,j=m+1;i<=m&&j<=h;)
	 {
		 if(A[i]<A[j]){c[k++]=A[i++];}
	     else{c[k++]=A[j++];}
     }
	 for(;i<=m;i++)
	 {c[k++]=A[i];}
	 for(;j<=h;j++)
	 {c[k++]=A[j];}
	 int g=0;
	 for(j=l;j<=h;j++)
	 {A[j]=c[g];g++;
	       if(g>k){break;}
     }
}
void mergesort(int A[],int low,int high)
{int mid;
	 if(low<high)
	 {
		 mid=(low+high)/2;
		 mergesort(A,low,mid);
		 mergesort(A,mid+1,high);
		 merge(A,low,mid,high);
	 }
}
main()
{
	  int i,a,b;
	  cout<<"enter the no. of numbers to be sorted\n";
	  cin>>a;
	  cout<<"enter the no.\n";
	  int A[a];
	  for(i=0;i<a;i++)
	  {
	   				  cin>>b;
	   				  A[i]=b;
	  }
	  mergesort(A,0,a-1);
	  cout<<"the sorted order is\n";
	  print(A,a);
	  cin>>i;
}

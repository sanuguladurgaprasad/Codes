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
void mergesort(int A[],int n)
{
 	 int size=1,k=0,l1,l2,u1,u2,i,j,x[n];
	 while(size<n)
	 {l1=0;
		 while(l1<n)
		 {
             if(l1+size<n){l2=l1+size;}else{l2=n-1;}
			 if(l1+size-1<n){u1=l1+size-1;}else{u1=n-1;}
			 if(l2+size-1<n){u2=l2+size-1;}else{u2=n-1;}
			 for(i=l1,j=l2;i<=u1&&j<=u2;)
			 {
				  if(A[i]<A[j]){x[k++]=A[i++];}
				  else{x[k++]=A[j++];}
			 }
			 for(;i<=u1;i++)
			 {x[k++]=A[i];}
             for(;j<=u2;j++)
			 {x[k++]=A[j];}
			 l1=u2+1;
			 l2=l1+size;
		 }
 	     for(i=0;i<n;i++)
		 {A[i]=x[i];}
		 size=2*size;k=0;
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
	  mergesort(A,a);
	  cout<<"the sorted order is\n";
	  print(A,a);
	  cin>>i;
}

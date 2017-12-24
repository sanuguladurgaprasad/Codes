#include<fstream>
#include<iostream>
using namespace std;
void swap(int &p,int &q)
{int t=p;
	 p=q;
	 q=t;
}
void print(int A[],int a)
{int i;
      for(i=0;i<a;i++)
	  {
	   				  cout<<A[i]<<" ";
	  }cout<<"\n";
}
int part(int A[],int low,int high)
{int t=0;
int p,l,h;
	  l=low+1;
	  h=high;
	  p=A[low];
	  while(l<=h)
	  {
				while(A[l]<p)
				{l++;}
				while(A[h]>p)
				{h--;}
				if(l<h){swap(A[l],A[h]);}
				if(t==1){break;}
				if(l==h){t=1;}
      }
      if(low<h)
      {
			   swap(A[low],A[h]);
      }
      return h;
}
void quicksort(int A[],int low,int high)
{int j;
	 if(low<high)
	 {
		 j=part(A,low,high);
		 quicksort(A,low,j-1);
		 quicksort(A,j+1,high);
	 }
}
main()
{
	  int i,a,b;ifstream fin;fin.open("p.cpp");
	  cout<<"enter the no. of numbers to be sorted\n";
	  fin>>a;
	  cout<<"enter the no.\n";
	  int A[a];
	  for(i=0;i<a;i++)
	  {
	   				  fin>>b;
	   				  A[i]=b;
	  }
	  quicksort(A,0,a-1);
	  cout<<"the sorted order is\n";
	  print(A,a);
	  cin>>i;
}

#include<iostream>
using namespace std;
void swap(int *p,int *q)
{
	 int *t;*t=*p;
	 *p=*q;
	 *q=*t;
}
main()
{
	  int i,n,j,k;
	  cout<<"enter the no. of num to be sorted\n";
	  cin>>n;cout<<"enter the no.\n";
	  int a[n];
	  for(i=0;i<n;i++)
	  {cin>>k;a[i]=k;}
	  for(i=1;i<n;i++)
	  {
					  for(j=0;j<n-1;j++)
					  {
										if(a[j]>a[j+1])
										{swap(a[j],a[j+1]);}
  					}
	  }cout<<"the sorted order is\n";
	  for(i=0;i<n;i++)
	  {cout<<a[i]<<" ";}
	  cin>>i;
}

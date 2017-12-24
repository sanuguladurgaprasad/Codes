#include<iostream>
using namespace std;
void swap(int *p,int *q)
{
	 int t;t=*p;
	 *p=*q;
	 *q=t;
}
main()
{
	  int i,n,j,k;
	  cout<<"enter the no. of num to be sorted\n";
	  cin>>n;cout<<"enter the no.\n";
	  int a[n];
	  for(i=0;i<n;i++)
	  {cin>>k;a[i]=k;}
	  for(i=0;i<n;i++)
	  {
					  for(j=i+1;j<n;j++)
					  {
										if(a[i]>a[j])
										{swap(a[j],a[i]);}
  					}
	  }cout<<"the sorted order is\n";
	  for(i=0;i<n;i++)
	  {cout<<a[i]<<" ";}
	  cin>>i;
}

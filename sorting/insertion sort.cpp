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
	  int key,i,n,j,k;
	  cout<<"enter the no. of num to be sorted\n";
	  cin>>n;cout<<"enter the no.\n";
	  int a[n];
	  for(i=0;i<n;i++)
	  {cin>>k;a[i]=k;}
	  for(i=1;i<n;i++)
	  {key=a[i];j=i-1;
					  for(j=i-1;j>=0;j--)
					  {if(key<a[j])
					            {cout<<a[j+1]<<a[j]<<"\n";a[j+1]=a[j];}
					            else {cout<<"p\n";break;}
  					}a[j+1]=key;
	  }cout<<"the sorted order is\n";
	  for(i=0;i<n;i++)
	  {cout<<a[i]<<" ";}
	  cin>>i;
}

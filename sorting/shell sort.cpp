#include<iostream>
using namespace std;
class stack
{
      public:
             int size;
             int top;
             int *element;
             void push(int);
             int pop();
             stack(int);
};
stack::stack(int z)
{
size=z;top=-1;
element=new int[z];
}
void stack::push(int x)
{
     if(top==size-1)
     {
                cout<<"stack is full \n";
     }
     else
     {
     element[++top]=x;
     }
}
int stack::pop()
{
     if(top==-1)
     {
                cout<<"stack is empty \n";
     }
     else
     {
         return(element[top--]);
     }
}
main()
{
	  int kount=0,cou=0,i,n,j,k;
	  cout<<"enter the no. of num to be sorted\n";
	  cin>>n;cout<<"enter the no.\n";
	  int a[n];
	  for(i=0;i<n;i++)
	  {cin>>k;a[i]=k;}
	  k=n;
	  while(n!=1)
	  {
				n=n/2;
				cou++;
      }n=k;cout<<n<<"H";cou++;
      stack s(100);
      s.push(1);
      for(i=2;i<100;i++)
      {kount=0;
		   for(j=1;j<=i;j++)
		   {
					 if(i%j==0){kount++;}
           }
           if(kount==2){cout<<i<<"K";s.push(i);}
           if(i>=n){cout<<"Y";break;}
      }cout<<n<<"N";
	  while(s.top!=-1)
	  {k=s.pop();cout<<k<<s.top;
					  for(j=0;j<n-1;j++)
					  {
										if(j+k<n){if(a[j]>a[j+k])
										{cout<<k<<"L";swap(a[j],a[j+k]);}}
  					  }
	  }cout<<"the sorted order is\n";
	  for(i=0;i<n;i++)
	  {cout<<a[i]<<" ";}
	  cin>>i;
}

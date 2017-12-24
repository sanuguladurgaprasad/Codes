#include<iostream>
using namespace std;
struct hpnode
{
       int data;
       hpnode *lchild;
       hpnode *rchild;
       hpnode *parent;
};
void swap(int *p,int *q)
{
     int t=*p;
     *p=*q;
     *q=t;
}
void fn(int h[],int k)
{
     if(k!=-1)
     {
              if(k%2!=0){
                         if(h[k]<h[k/2]){
                                         swap(h[k],h[k/2]);
                                        }
                                        fn(h,k-1);
                         }
                         else
                         {if(h[k]<h[(k-1)/2]){swap(h[k],h[(k-1)/2]);}
                         fn(h,(k-1));
                         }
     }
}
void create(int h[],int size)
{
     int a,b;cout<<-1/2;
     for(int i=0;i<size;i++)
     {
             cin>>a;h[i]=a;fn(h,i);
     }
}
void delet(int h[],int size,int h1[])
{
     int i=0;
     while(size!=0)
     {
         h1[i]=h[0];
         h[0]=h[size-1];
         size--;i++;
         fn(h,size-1);
     }
}
main()
{
      int e,i;
      cout<<"enter how many elements u want int the heap\n";
      cin>>e;
      int h[e],h1[e];
      create(h,e);
      cout<<"the heap insertion is\n";
      for(i=0;i<e;i++)
      {cout<<h[i]<<" "<<endl;}cout<<"the sorted way is\n";
      delet(h,e,h1);
      for(i=0;i<e;i++)
      {cout<<h1[i]<<" "<<endl;}
	  cin>>i;
}

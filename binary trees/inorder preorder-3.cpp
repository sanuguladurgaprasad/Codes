#include<iostream>
using namespace std;
struct bnode
{
     int data;
     bnode *lchild;
     bnode* rchild;
};bnode *t;
bnode* fn(int *io,int *po,int start,int end)
{static int n;
       static int i=0;if(i==0){n=end;}
       int k;cout<<"h";
       if((i>=0)&&(i<n))
       {cout<<"b";
           t=new bnode;
           t->data=po[i];
           t->lchild=NULL;
           t->rchild=NULL;
           for(k=start;k<=end;k++)
           {if(io[k]==po[i]){break;}}
           i++;cout<<k;
           if(k>0){t->lchild=fn(io,po,start,k-1);cout<<"s";}//if(i==1){cout<<"p";end=k;}
           if(k<end){cout<<"w";t->rchild=fn(io,po,k+1,end);}
           cout<<"j";return t;
       }

}
void postorder(bnode *b)
{
     postorder(b->lchild);
     postorder(b->rchild);
     cout<<b->data;
}
main()
{
      int *po,*io,a,b;
      cout<<"enter the size of the tree to be \n";
      cin>>a;
      po=new int [a];
      io=new int [a];
      for(int i=0;i<a;i++){cin>>b;io[i]=b;}
      for(int i=0;i<a;i++){cin>>b;po[i]=b;}
      fn(io,po,0,a-1);
      postorder(t);
	  char e;cin>>e;
}

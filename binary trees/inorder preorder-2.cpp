#include<iostream>
#include<conio.h>
using namespace std;
struct bnode
{
	int data;
	bnode *lchild;
	bnode* rchild;
};
void fn(int *io,int *po,int size1,bnode *&b)
{int k;
static int i=0,h,cur,pre=0;if(i==0){h=size1;}if(i<=h){
	for(k=0;k<=size1;k++){if(po[i]==io[k]){
		b=new bnode;b->data=po[i];b->lchild=NULL;b->rchild=NULL;}}
	i++;if(i==0){pre=k;}if(i!=0){cur=k;}
	if((i==0)&&(k==0)){fn(io,po,k,b);if((i==0)&&(k>0)){fn(io,po,k-1,b);}
	if(cur<pre)fn(io,po,k-1,b->lchild);
	if(cur>pre)fn(io,po,k+1;b->rchild);}
}
void postorder(bnode *b)
{if(b!=NULL){cout<<"f";
postorder(b->lchild);
postorder(b->rchild);
cout<<b->data<<endl;}
}
main()
{
	int *po,*io,a,b;bnode *b1;
	cout<<"enter the size of the tree to be \n";
	cin>>a;//b1=NULL;
	po=new int [a];
	io=new int [a];
	for(int i=0;i<a;i++){cin>>b;io[i]=b;}
	for(int i=0;i<a;i++){cin>>b;po[i]=b;}
	fn(io,po,a-1,b1);cout<<b1->data;cout<<endl;
	postorder(b1);cout<<"r";
	getch();
}

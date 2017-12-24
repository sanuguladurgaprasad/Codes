#include <iostream>
using namespace std;
struct btree
{
	int *key;
	btree **child;
};

class queue
{
      public:
             int size;
             int front;
             int rear;
             btree *elements[100];
             queue(int);
             void enqueue(btree*);
             btree* dequeue();
};
queue::queue(int z)
{
                 size=z;front=-1;rear=-1;
}
void queue::enqueue(btree *x)
{
     if(front==(rear+1)%size)
     {
                             cout<<"queue is full\n";
     }
     else
     {
     if(front==-1)
     {
                  front=0;
     }
         rear= (rear+1)%size;
         elements[rear]=x;
     }
}
btree* queue::dequeue()
{
    btree *t;
    if(front==-1)
    {
                 cout<<"queue is empty \n";
    }
    else
    {
    if(front==rear)
    {
     t=elements[front];
     front=-1;
     rear=-1;
    }
    else
    {
        t=elements[front];
        front=(front+1)%size;
    }
}
    return t;
}
queue Q(100);
int p=0,m=0,a1,k2;
btree *b1=NULL,*b2=NULL,*x2,*z;
void print(btree *b,int d)
{	int i;
	if(b!=NULL)
		{
			for(i=0; i<=(2*d)-1; i++)
				{
					{
						print(b->child[i],d);
					}
					if(b->key[i]!=-1) {
					cout<<b->key[i]<<"  ";
						}
				}
			print(b->child[2*d],d);
		}
}
btree *e;int w;//w for fn() purpose if the deleted node in the root itself
btree* split(btree *b,int k,int d,int f,int o,int q)
{	int u=0,v=0;
	e=new btree;
	e->key=new int[(2*d)+1];
	e->child=new btree*[(2*d)+2];
	for(int i=0; i<=(2*d)+1; i++) {
			e->child[i]=NULL;
		}
	for(int i=0; i<=2*d; i++)
		{	if(v==2*d)
				{
					e->key[i]=k;
					break;
				}
			if((i<2*d)&&(k<b->key[i])) {
					if(u==0) {
							e->key[i]=k;
							u++;
						}
					else {
							e->key[i]=b->key[i-1];
						}
				}
			else if(i==2*d) {
					e->key[i]=b->key[i-1];
				}
			else {
					e->key[i]=b->key[i];
					v++;
				}
		}
	if((o==2)||(q==1)) {//condition for non leaf node
			for(int i=0; i<=(2*d); i++)
				{if(k==e->key[i]) {
							e->child[i]=b1;
							e->child[i+1]=b2;
							if(i==2*d) {
									break;
								}
						}
					else
						{	if(k>e->key[i])
								{
									e->child[i]=b->child[i];
								}
							else {
									e->child[i+1]=b->child[i];
								}
						}
				}
		}
	if((q!=0)&&(q!=1)) {
			b1=new btree;
			b1->key=new int[2*d];
			for(int i=0; i<2*d; i++) {
					b1->key[i]=-1;
				}
			b1->child=new btree*[(2*d)+1];
			for(int i=0; i<=2*d; i++) {
					b1->child[i]=NULL;
				}
			b2=new btree;
			b2->key=new int[2*d];
			for(int i=0; i<2*d; i++) {
					b2->key[i]=-1;
				}
			b2->child=new btree*[(2*d)+1];
			for(int i=0; i<=2*d; i++) {
					b2->child[i]=NULL;
				}
			int m=0,n=0;
			a1=e->key[d];
			for(int i=0; i<d; i++) {
					b1->key[i]=e->key[m];
					m++;
				}
			m++;
			for(int i=0; i<d; i++) {
					b2->key[i]=e->key[m];
					m++;
				}
			for(int i=0; i<=d; i++) {
					b1->child[i]=e->child[n];
					n++;
				}
			for(int i=0; i<=d; i++) {
					b2->child[i]=e->child[n];
					n++;
				}
			if(f==1)//for the root node
				{	z=new btree;
					z->key=new int[2*d];
					for(int i=0; i<=(2*d)-1; i++) {
							z->key[i]=-1;
						}
					z->child=new btree*[(2*d)+1];
					for(int i=0; i<=2*d; i++) {
							z->child[i]=NULL;
						}
					z->key[0]=a1;
					z->child[0]=b1;
					z->child[1]=b2;
					return z;
				}
		}
	else {
			return x2;
		}
}
btree* arr(btree *b,int k,int d,int y,int g1)
{	int s=0;
	for(int h=y; h<=(2*d)-1; h++)
		{
			if(b->key[h]!=-1) {
					s++;
				}
		}
	for(int t=s; t>0; t--)
		{
			b->key[y+t]=b->key[y+t-1];
			if(g1==1) {
					b->child[y+t+1]=b->child[y+t];
				}
		}
	b->key[y]=k;
	if(g1==1) {
			b->child[y]=b1;
			b->child[y+1]=b2;
		}
	return b;
}
int cou(btree *b,int d)
{
	int count=0;
	for(int j=0; j<=(2*d)-1; j++) {
			if(b->key[j]!=-1) {
					count++;
				}
		}
	return count;
}
int kou(btree *b,int d)
{
	int kount=0;
	for(int r=0; r<=2*d; r++) {
			if(b->child[r]!=NULL) {
					kount++;
				}
		}
	return kount;
}
int fn(btree *b,int k,int d)
{	int j;
	for(j=0; j<2*d; j++)
		{
			if(k<b->key[j])
				{
					break;
				}
			else if(b->key[j]==-1)
				{
					break;
				}
			else if(k==b->key[j])
				{
					break;
				}
		}
	return j;
}
int k1;
btree* left(btree *b,int d,int k,int i)
{int j,ar[(2*d)+1],l,t1,p2,t2;
	if(kou(b->child[i],d)==0) {
			split(b->child[i],k,d,0,0,0);//for leafnode
		}
	else {
			split(b->child[i],k,d,0,0,1);//for non leaf node
		}
	for(j=1; j<=2*d; j++) {
			b->child[i]->key[j-1]=e->key[j];
		}
	if(kou(b->child[i-1],d)!=0) {
			for(j=1; j<=(2*d)+1; j++) {
					b->child[i]->child[j-1]=e->child[j];
				}
		}
	t1=b->key[i-1];
	b->key[i-1]=e->key[0];
	int ff=cou(b->child[i-1],d);
	if(kou(b->child[i-1],d)!=0) {
			b->child[i-1]->child[ff+1]=e->child[0];
		}
	b->child[i-1]->key[ff]=t1;
	return b;
}
btree* right(btree *b,int d,int k,int i)
{int j,ar[(2*d)+1],l,t1,p2,t2;
	if(kou(b->child[i],d)==0) {
			split(b->child[i],k,d,0,0,0);
		}
	else {
			split(b->child[i],k,d,0,0,1);
		}
	for(j=0; j<2*d; j++) {
			b->child[i]->key[j]=e->key[j];
		}
	if(kou(b->child[i],d)!=0) {
			for(j=0; j<=(2*d); j++) {
					b->child[i]->child[j]=e->child[j];
				}
		}
	t1=b->key[i];
	b->key[i]=e->key[(2*d)];
	int ff=cou(b->child[i+1],d);
	{
		for(j=ff; j>0; j--)
			{
				b->child[i+1]->key[j]=b->child[i+1]->key[j-1];
			}
	}
	if(kou(b->child[i],d)!=0) {
			for(j=ff+1; j>0; j--) {
					b->child[i+1]->child[j]=b->child[i+1]->child[j-1];
				}
		}
	b->child[i+1]->key[0]=t1;
	b->child[i+1]->child[0]=e->child[(2*d)+1];
	return b;
}
 btree* lef(btree *b,int d,int i)//takes no. frm left
{	int zz,j,l,p2,t2;
	p2=cou(b->child[i],d);
	t2=b->child[i]->key[p2-1];
	b->child[i]->key[p2-1]=-1;
	for(j=0; j<(2*d)-1; j++)
		{
			b->child[i+1]->key[j+1]=b->child[i+1]->key[j];
		}
	for(zz=0;zz<2*d;zz++)
	{b->child[i+1]->child[zz+1]=b->child[i+1]->child[zz];
    }b->child[i+1]->child[2*d]=NULL;
	b->child[i+1]->key[0]=b->key[i];
	b->child[i+1]->child[0]=b->child[i]->child[p2];
    b->child[i]->child[p2]=NULL;
	b->key[i]=t2;
	return b;
}
btree* rit(btree *b,int d,int i)//takes no. frm right
{	int j,l,t2,p2;
	t2=b->child[i]->key[0];
	p2=cou(b->child[i-1],d);
	b->child[i-1]->key[p2]=b->key[i];
	b->child[i-1]->key[p2]=b->key[i-1];
	b->key[i-1]=t2;
	for(j=0; j<(2*d)-1; j++) {
			b->child[i]->key[j]=b->child[i]->key[j+1];
		}
	b->child[i]->key[(2*d)-1]=-1;
	b->child[i-1]->child[p2+1]=b->child[i]->child[0];
	for(j=0; j<=(2*d)-1; j++) {
			b->child[i]->child[j]=b->child[i]->child[j+1];
		}
		b->child[i]->child[2*d]=NULL;
	return b;
}
int y1;
btree* redib(btree *b,int d,int k,int tag)
{	int t1,t2,p1,p2;cout<<"D";
	p1=fn(b,k,d);
	if(w==1){p1--;}	cout<<p1<<"WENT ";
	for(int i=p1; i<=p1; i++)
		{cout<<"OUT ";if(b->child[i]!=NULL)
				{	if((y1==1)||(kou(b->child[i],d)==0)||(tag==1))
						{if((cou(b->child[i],d)==2*d)||(tag==1))
								{
									if(i==0)
										{cout<<"GOD ";if(b->child[i+1]!=NULL)
												{	if((cou(b->child[i+1],d)>d)&&(tag==1))
														{cout<<"u";b=rit(b,d,i+1);
															   k1=1;     //i+1 since it takes frm right
														}
													else if((cou(b->child[i+1],d)!=2*d)&&(tag==0))
														{
															b=right(b,d,k,i);
															k1=1;
														}
												}
											break;
										}
									else if((b->key[i]==-1)||(i==2*d))
										{cout<<"DOG";
											if((cou(b->child[i-1],d)>d)&&(tag==1))
												{cout<<"n";//i-1 since takes frm left
													b=lef(b,d,i-1);
													k1=1;
												}
											else if((cou(b->child[i-1],d)!=2*d)&&(tag==0)) {
													b=left(b,d,k,i);
													k1=1;
												}
											break;
										}
									else {	cout<<"PIG ";if((cou(b->child[i-1],d)>d)&&(tag==1)) {
													b=lef(b,d,i-1);
													k1=1;break;
												}
											else if((cou(b->child[i-1],d)!=2*d)&&(tag==0)) {
													b=left(b,d,k,i);
													k1=1;break;
												}
											if((tag==1)&&(cou(b->child[i+1],d)>d)) {
													b=rit(b,d,i+1);
													k1=1;
												}
											else if((b->child[i+1]!=NULL)&&(tag==0)) {
													if(cou(b->child[i+1],d)!=2*d) {
															b=right(b,d,k,i);
															k1=1;
														}
												}
											break;
										}
								}
						}
				}
		}
	return b;
}

btree *A;int K;
void print2(btree *b,int d,btree *R)
{int i;
     if(b!=NULL)
     {
                if(K==0)
                {
                Q.enqueue(b);Q.enqueue(R);
                }
                K++;
                if(K>1)
                {if(b->child!=NULL){
					   for(i=0;i<kou(b,d);i++)
				 	   {
   						if(b->child[i]!=NULL){Q.enqueue(b->child[i]);}
                       }
		            }
                }
     }
     K++;//cout<<"L";
     if(Q.front!=Q.rear)
     {
                        A=Q.dequeue();
     if(A==R)
     {//cout<<"P";
     Q.enqueue(R);cout<<endl;
     }
     else{
	 for(int j=0;j<2*d;j++)
		  {
	      if(A->key[j]!=-1)
		     {cout<<A->key[j]<<" ";}
		  else{cout<<"*"<<" ";}
		  }cout<<"    ";
     }
     print2(A,d,R);
     }
}
void swap(int &p,int &q)
{
	int t=p;
	p=q;
	q=t;
}
btree *ln,*x;
int x1,m1,z1,r;//ln=Leaf Node;z1 for repeating only once;
btree* merge(btree *b,btree *h1,int d,int i)
{	int f,j,p1,p2,l,t1,p3;
	p1=cou(b->child[i],d);cout<<p1;
	b->child[i]->key[p1]=b->key[i];
	p2=cou(b->child[i+1],d);
	p1++;cout<<p2<<p1;
	p3=p1;
	for(j=i; j<(2*d)-1; j++) {cout<<"F1";
			b->key[j]=b->key[j+1];
		}
	b->key[(2*d)-1]=-1;
	for(j=0; j<p2; j++) {cout<<"F2";
			b->child[i]->key[p1]=b->child[i+1]->key[j];//p1 is incremented previously
			p1++;
		}
		for(f=0; f<=p2; f++) {cout<<"F3";
			if(kou(b->child[i],d)!=0)
				{cout<<"m";
                    b->child[i]->child[f+p3]=b->child[i+1]->child[f];
				}
		}
	for(l=i+1; l<2*d; l++) {cout<<"F4";
			b->child[l]=b->child[l+1];
		}
	b->child[2*d]=NULL;
	if((cou(h1,d)==0)) {cout<<"D";
			return (b->child[i]);
		}
	else {cout<<"T";
			return (b);
		}
}
btree* max(btree *b,int d,int i)
{	int p=0;
	if(b!=NULL) {
			if(kou(b,d)==0) {
					return b;
				}
			else
				{
					if(x1==0)
						{
							x1++;
							b=b->child[i];
							p=cou(b,d);
							x=max(b,d,p);
						}
					else
						{
							p=cou(b,d);
							x=max(b->child[p],d,p-1);
						}
					return x;
				}
		}
}
btree* s;
int s2;
btree* search(btree *b,btree *h1,int d,int k)
{	int i,index,p3,p4;
	if(b!=NULL)
		{
			for(i=0; i<2*d; i++)
				{
					if(k==b->key[i])
						{
							if(k2==1)
								{index=cou(b,d);cout<<"found2";
									s->key[s2]=b->key[index-1];
									cout<<s->key[s2]<<"&";
									b->key[index-1]=-1;
									m1=1;
									break;
								}
							if(k2==0)
							  {		//if(b==h1){w=1;}
							  cout<<"found1\n";
									ln=max(b,d,i);
									s=b;
									s2=i;
									m1=1;
									p3=cou(ln,d);
									cout<<p3<<ln->key[p3-1]<<"#";
									if(kou(b,d)!=0) {
											k2++;
											b->child[i]=search(b->child[i],h1,d,ln->key[p3-1]);
											break;
										}
									else {
											index=cou(b,d);
											s->key[s2]=b->key[index-1];
											cout<<s->key[s2]<<"&";
											b->key[index-1]=-1;
											m1=1;
											break;
										}
								}
						}
					else if((b->key[i]==-1)||(k<b->key[i]))
						{	cout<<"DON";b->child[i]=search(b->child[i],h1,d,k);
							break;
						}
					else if(i==(2*d)-1)
						{	cout<<"PIP";b->child[i+1]=search(b->child[i+1],h1,d,k);
							break;
						}
				}
			if(m1==2)
				{	int q;
					if((kou(b,d)!=0)&&(z1!=1))
						{if(b==s){w=1;}
                            q=fn(b,k,d);cout<<q<<k<<"b";
                            if(w==1){q--;}cout<<q<<"B"<<k;
							if(cou(b->child[q],d)<d){b=redib(b,d,k,1);if(w==1){w=2;}
							if(k1!=1)
								{
									for(int i=q; i<=q; i++)
										{cout<<"AOUT ";	if(cou(b->child[i],d)<d)
												{
													if(i==0)
														{cout<<"AGOD ";	if(b->child[i+1]!=NULL) {
																	if(cou(b->child[i+1],d)<=d) {
																			b=merge(b,h1,d,i);
																		}
																}
															break;
														}
													else if((b->key[i]==-1)||(i==2*d))
														{cout<<"ADOG ";	if(cou(b->child[i-1],d)<=d)
																{
																	b=merge(b,h1,d,i-1);
																}
															break;
														}
													else
														{cout<<"APIG ";
														if(b->child[i+1]!=NULL) {
																	if(cou(b->child[i+1],d)<=d) {
																			b=merge(b,h1,d,i);
																		}
																		}
														else if(cou(b->child[i-1],d)<=d)
																{
																	b=merge(b,h1,d,i-1);
																}
															break;
														}
												}
										}
								}
					}	}
				}
			if(m1==1)
				{	if((cou(b,d)>=d)&&(z1!=1))
						{z1=1;
							for(int it=0; it<cou(b,d); it++)
								{	for(int in=0; in<cou(b,d)-1; in++)
										{
											if(b->key[in]>b->key[in+1])
												{
													swap(b->key[i],b->key[in+1]);
												}
										}
								}
						}
					else {
							m1=2;
						}
				}
			cout<<"%"<<b->key[0];return b;
		}
	else {cout<<"h";
			return NULL;
		}
}
btree* insert(btree *b,btree *h1,int k,int d)
{	int count,kount,s=0;
	count=cou(b,d);
	kount=kou(b,d);
	if(b!=NULL)
		{
			for(int i=0; i<=(2*d)-1; i++)
				{	if((kount!=0))
						{	k1=0;
							b=redib(b,d,k,0);
							if(k1==1)
								{
									break;
								}
							if((k<b->key[i])||(b->key[i]==-1))
								{
									b->child[i]=insert(b->child[i],h1,k,d);
									break;
								}
							else if((b->key[(2*d)-1]!=-1)&&(b->key[(2*d)-1]<k))
								{
									b->child[2*d]=insert(b->child[2*d],h1,k,d);
									break;
								}
						}
					else if((count!=2*d)&&(kount==0))
						{	if((k<b->key[i])||(b->key[i]==-1))
								{
									if(k<b->key[i])
										{
											b=arr(b,k,d,i,0);
											break;
										}
									else if(b->key[i]==-1) {
											b->key[i]=k;
											break;
										}
								}
						}
					else if((count==2*d)&&(kount==0))
						{	if(b==h1)
								{
									b=split(b,k,d,1,0,3);
									break;
								}
							else {
									p=1;
									split(b,k,d,0,0,3);
								}
						}
					if(p==1) {
							p=2;
							break;
						}
				}
			if(p==3)
				{	int f1=fn(b,a1,d);
					if((cou(b->child[f1],d)==2*d)&&(kount!=0)&&(m!=1))
						{	k1=0;
							y1=1;
							if(m!=1) {
									b=redib(b,d,a1,0);
									if(k==1) {
											m=1;
										}
								}
							if(k1!=1) {
									if(cou(b,d)==2*d) {
											if(b==h1) {
													split(b->child[f1],a1,d,0,2,3);
													b=split(b,a1,d,1,2,3);
													m=1;
												}
										}
									else {p=3;
											split(b->child[f1],a1,d,0,2,3);
											m=1;
											if((cou(b->child[f1],d)==2*d)&&(cou(b,d)<=(2*d)-1)&&(k1!=1))
												{	if(f1==0)
														{
															if(cou(b->child[f1+1],d)==2*d)
																{
																	m=0;
																	p=2;
																}
														}
													else if((f1==2*d)||(b->key[f1]==-1)) {
															if(cou(b->child[f1-1],d)==2*d);
                                                            {
																m=0;
																p=2;
															}
														}
													else {
															if(((cou(b->child[f1+1],d)==2*d))&&(cou(b->child[f1-1],d)==2*d)) {
																	m=0;
																	p=2;
																}
														}
												}
										}
								}
						}
				}
			if(p==2)
				{	if((count!=2*d)&&(kount!=0)&&(m!=1))
						{	s=0;
							for(int y=0; y<=(2*d)-1; y++)
								{if((a1<b->key[y])||(b->key[y]==-1))
										{	m=1;
											if(a1<b->key[y])
												{	b=arr(b,a1,d,y,1);
													break;
												}
											else if((b->key[y]==-1))
												{	b->key[y]=a1;
													b->child[y]=b1;
													b->child[y+1]=b2;
													m=1;
													break;
												}
										}
								}
						}
					else if(b==h1) {
							b=split(b,a1,d,1,2,3);
							m=1;
						}
					if((kou(b,d)!=0)) {
							p=3;
						}
				}
			return b;
		}
	else {
			return NULL;
		}
}
main()
{
	int a,c,d,s1;
	cout<<"enter d and firsti element\n";
	cin>>d>>s1;
	btree *h1,*R;
    R=new btree;
    R->key=new int[2*d];
    for(int i=1;i<=(2*d)-1;i++)
    {R->key[i]=-2;}
	R->child=NULL;
	h1=new btree;
	h1->key=new int[2*d];
	h1->key[0]=s1;
	for(int i=1; i<=(2*d)-1; i++) {
			h1->key[i]=-1;
		}
	h1->child=new btree*[(2*d)+1];
	for(int i=0; i<=2*d; i++) {
			h1->child[i]=NULL;
		}
	btree *b;
	b=h1;
	cout<<"enter the no. of elements u want to insert\n";
	cin>>a;
	for(int i=0; i<a; i++)
		{	b1=NULL;
			b2=NULL;
			cout<<"enter the elements\n";
			p=0;m=0;y1=0;cin>>c;
			b=insert(b,h1,c,d);h1=b;
		}
	print(b,d);
	for(int i=0; i<=a; i++)
		{
			while(Q.front!=-1)
			{Q.dequeue();}
			cout<<"enter the element to be deleted\n";
			cin>>c;x1=0;w=0;
			m1=0;z1=0;k1=0;k2=0;
			b=search(b,h1,d,c);
			h1=b;print(b,d);K=0;cout<<"\n";
			print2(b,d,R);
		}
	int tt;
	cin>>tt;
	print(b,d);
}

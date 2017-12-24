#include <fstream>
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
				cout<<j<<"j";;
					break;
				}
		}
	return j;
}
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
							cout<<b->key[i]<<"i"<<i<<"  ";
						}
				}
			print(b->child[2*d],d);
		}
}
btree *e;int w;//w for fn() purpose if the deleted node in the root itself
btree* split(btree *b,int k,int d,int f,int o,int q)
{	int u=0,v=0;
	cout<<"s";
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
					cout<<k;
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
			cout<<e->key[i]<<"   i    ";
		}
	if((o==2)||(q==1)) {
			for(int i=0; i<=(2*d); i++)
				{
					if(k==e->key[i]) {
							e->child[i]=b1;
							e->child[i+1]=b2;
							cout<<"how";
							print(e->child[i+1],d);
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
					print(e->child[i],d);
					cout<<"Q";
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
			cout<<a1<<"        ";
			for(int i=0; i<d; i++) {
					b1->key[i]=e->key[m];
					m++;
				}if(kou(b,d)==0){b1->key[d]=a1;}
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
			if(f==1)
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
					cout<<"f";
					print(b2,d);
					print(b1,d);
					print(z,d);
					return z;
				}
		}
	else {
			//print(b2,d);
			cout<<"S";//print(b1,d);cout<<"U";
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
			cout<<y+t<<"T";
			if(g1==1) {
					b->child[y+t+1]=b->child[y+t];
				}
		}
	cout<<y<<"M";
	b->key[y]=k;
	if(g1==1) {
			b->child[y]=b1;
			b->child[y+1]=b2;
		}
	return b;
}

int k1;
btree* left(btree *b,int d,int k,int i)
{	cout<<"MOM";
	int j,ar[(2*d)+1],l,t1,p2,t2;
	if(kou(b->child[i],d)==0) {
			split(b->child[i],k,d,0,0,0);
		}
	else {
			split(b->child[i],k,d,0,0,1);
		}
	for(j=1; j<=2*d; j++) {
			b->child[i]->key[j-1]=e->key[j];
		}
	if(kou(b->child[i-1],d)!=0) {
			for(j=1; j<=(2*d)+1; j++) {
					b->child[i]->child[j-1]=e->child[j];
				}
		}
	if(kou(b->child[i-1],d)!=0)
	{t1=b->key[i-1];b->key[i-1]=e->key[0];}
	else{b->key[i-1]=e->key[0];}
	int ff=cou(b->child[i-1],d);
	if(kou(b->child[i-1],d)!=0) {
			b->child[i-1]->child[ff+1]=e->child[0];
		}
	if(kou(b->child[i-1],d)!=0)
	{b->child[i-1]->key[ff]=t1;}
	else{b->child[i-1]->key[ff]=e->key[0];}
	cout<<"L"<<t1<<i<<ff;
	return b;
}
btree* right(btree *b,int d,int k,int i)
{	cout<<"DAD";
	int j,ar[(2*d)+1],l,t1,p2,t2,ff;
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
	if(kou(b->child[i],d)!=0){
         b->key[i]=e->key[(2*d)];
	}
	else{b->key[i]=e->key[(2*d)-1];}
	ff=cou(b->child[i+1],d);
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
	for(j=(2*d)-1; j>0; j--)
		{
			b->child[i+1]->key[j]=b->child[i+1]->key[j-1];
		}
	b->child[i+1]->key[0]=b->key[i];
	for(zz=0;zz<2*d;zz++)
	{b->child[i+1]->child[zz+1]=b->child[i+1]->child[zz];
    }b->child[i+1]->child[2*d]=NULL;
	b->child[i+1]->child[0]=b->child[i]->child[p2];
    b->child[i]->child[p2]=NULL;
	if(kou(b->child[i],d)==0){b->key[i]=b->child[i]->key[p2-2];}
	else{b->key[i]=t2;}
	return b;
}
btree* rit(btree *b,int d,int i)//takes no. frm right
{	int j,l,t2,p2;
	t2=b->child[i]->key[0];
	p2=cou(b->child[i-1],d);
	if(kou(b->child[i-1],d)!=0){b->child[i-1]->key[p2]=b->key[i-1];}
	else{b->child[i-1]->key[p2]=t2;}
	b->key[i-1]=t2;
	for(j=0; j<(2*d)-1; j++) {
			b->child[i]->key[j]=b->child[i]->key[j+1];
		}
	b->child[i]->key[(2*d)-1]=-1;
	b->child[i-1]->child[p2+1]=b->child[i]->child[0];
	for(j=0; j<(2*d); j++) {
			b->child[i]->child[j]=b->child[i]->child[j+1];
		}
		b->child[i]->child[j]=NULL;
	return b;
}
int y1,z1;btree *s,*h1;
btree* redib(btree *b,int d,int k,int tag)
{	int t1,t2,p1,p2;
	cout<<"D";
	p1=fn(b,k,d);cout<<p1;
    //if(b==h1){cout<<"i";p1--;}
	cout<<p1<<"WENT ";
	for(int i=p1; i<=p1; i++)
		{	cout<<"OUT";
			if(b->child[i]!=NULL)
				{	if((y1==1)||(kou(b->child[i],d)==0)||(tag==1))
						{	cout<<cou(b->child[i],d);
							if((cou(b->child[i],d)==2*d)||(tag==1))
								{
									if(i==0)
										{	cout<<"GOD ";
											if(b->child[i+1]!=NULL)
												{	if((cou(b->child[i+1],d)>d)&&(tag==1))
														{
															cout<<"u";        //i+1 since it takes frm right
															b=rit(b,d,i+1);
															k1=1;z1=1;
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
										{	cout<<"DOG ";
											if((cou(b->child[i-1],d)>d)&&(tag==1))
												{
													cout<<"n";        //i-1 since takes frm left
													b=lef(b,d,i-1);
													k1=1;z1=1;
												}
											else if((cou(b->child[i-1],d)!=2*d)&&(tag==0)) {
													b=left(b,d,k,i);
													k1=1;
												}
											break;
										}
									else {
											cout<<"PIG ";
											if((cou(b->child[i-1],d)>d)&&(tag==1)) {
													b=lef(b,d,i-1);
													k1=1;z1=1;break;
												}
											else if((cou(b->child[i-1],d)!=2*d)&&(tag==0)) {
													b=left(b,d,k,i);
													k1=1;break;
												}
											if((tag==1)&&(cou(b->child[i+1],d)>d)) {
													b=rit(b,d,i+1);
													k1=1;z1=1;
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
btree* ar(btree *b,int d)
{int g=0;
									while(b->key[g]!=-1){g++;}
									for(int f=g;f<(2*d)-1;f++)
									{b->key[f]=b->key[f+1];}
									b->key[(2*d)-1]=-1;
									return b;
}int x1;btree *x,*ln;
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
btree* mm(btree *b,int d,int k,int q){int p4;x1=0;
ln=max(b,d,q);
									p4=cou(ln,d);if(p4!=0){
									cout<<p4<<ln->key[p4-1]<<"K";
									b->key[q]=ln->key[p4-1];}
									return b;
}
int m1,r;//ln=Leaf Node;z1 for repeating only once;
btree* merge(btree *b,btree *h1,int k,int d,int i)
{	int f,j,p1,p2,l,t1,p3,q;
   q=fn(b,k,d);
   //if(b->key[q]==k){b->key[q]=-1;}
	p1=cou(b->child[i],d);
	cout<<p1;p2=cou(b->child[i+1],d);
	if(kou(b->child[i],d)!=0)
	{if(k==b->key[q]){b=mm(b,d,k,q);}
    b->child[i]->key[p1]=b->key[i];
	p1++;
	cout<<p2<<p1;
	p3=p1;
	for(j=i; j<(2*d)-1; j++) {
			cout<<"F1";
			b->key[j]=b->key[j+1];
		}
	b->key[(2*d)-1]=-1;
	for(j=0; j<p2; j++) {
			cout<<"F2";
			b->child[i]->key[p1]=b->child[i+1]->key[j];//p1 is incremented previously
			p1++;
		}
		for(f=0; f<=p2; f++) {
			cout<<"F3"<<f+p3<<p2;
			cout<<b->key[0]<<b->child[i]->key[0];
			if(kou(b->child[i],d)!=0)
				{	cout<<"m";
					b->child[i]->child[f+p3]=b->child[i+1]->child[f];
				}
		}
	for(l=i+1; l<2*d; l++) {
			cout<<"F4";
			b->child[l]=b->child[l+1];
		}
	b->child[2*d]=NULL;}
	else {  q=fn(b,k,d);
            {b->key[q]=-1;}
	   for(j=i; j<(2*d)-1; j++) {
			cout<<"F5";
			b->key[j]=b->key[j+1];
		}b->key[(2*d)-1]=-1;
            for(j=0; j<p2; j++) {
			cout<<"F6";
			b->child[i]->key[p1]=b->child[i+1]->key[j];//p1 is incremented previously
			p1++;
		   }//b->key[i]=b->child[i]->key[cou(b->child[i],d)-1];
		   for(l=i+1; l<2*d; l++) {
			cout<<"F7";
			b->child[l]=b->child[l+1];
		}
	b->child[2*d]=NULL;
		 }
	if((cou(h1,d)==0)) {

			return (b->child[i]);
		}
	else {
			cout<<"f";
			return (b);
		}
}

int s2;
btree* search(btree *b,btree *h1,int d,int k)
{	int i,index,p3,q;
	if(b!=NULL)
		{
			for(i=0; i<2*d; i++)
				{
					if((k==b->key[i])&&(kou(b,d)==0))
						{
								cout<<"found1\n";
									//if(b==h1){w=1;}
									//s=b;
									s2=i;
									m1=1;
									//cout<<p3<<s->key[p3-1]<<"#";
									b->key[i]=-1;
									b=ar(b,d);
						}
					else if((b->key[i]==-1)||(k<=b->key[i]))
						{	cout<<"DON";
							b->child[i]=search(b->child[i],h1,d,k);
							break;
						}
					else if(i==(2*d)-1)
						{	cout<<"PIP";
							b->child[i+1]=search(b->child[i+1],h1,d,k);
							break;
						}
				}q=fn(b,k,d);cout<<q<<k<<"Q"<<b->key[q];
				/*if((k==b->key[q]))
				{b=mm(b,d,k,q);}*/
			if(m1==2)
				{	//if(b==s){w=1;}
					if((kou(b,d)!=0)&&(z1!=1))
						{
                            //q=fn(b,k,d);cout<<q<<k;
                           // if((b==h1)&&(kou(b->child[q],d)!=0)){q--;cout<<"e";}
							cout<<k<<"B"<<q;
							if(cou(b->child[q],d)<d){b=redib(b,d,k,1);
							if(k1!=1)
								{
									for(int i=q; i<=q; i++)
										{	cout<<"AOUT"<<cou(b->child[i],d);
											if(cou(b->child[i],d)<d)
												{
													if(i==0)
														{	cout<<"AGOD ";
															if(b->child[i+1]!=NULL) {
																	if(cou(b->child[i+1],d)<=d) {
																			b=merge(b,h1,k,d,i);
																		}
																}
															break;
														}
													else if((b->key[i]==-1)||(i==2*d))
														{
															cout<<"ADOG ";
															if(cou(b->child[i-1],d)<=d)
																{
																	b=merge(b,h1,k,d,i-1);
																}
															break;
														}
													else
														{	cout<<"APIG ";
															if(b->child[i+1]!=NULL) {
																	if(cou(b->child[i+1],d)<=d) {
																			b=merge(b,h1,k,d,i);
																		}
																}
																else if(cou(b->child[i-1],d)<=d)
																{
																	b=merge(b,h1,k,d,i-1);
																}
															break;
														}
												}
										}
								}
								}
						}
				}if((k==b->key[q]))
				{b=mm(b,d,k,q);}
			if(m1==1)
				{	cout<<"x"<<z1;
					if((cou(b,d)>=d)&&(z1!=1)&&(kou(b,d)==0))
						{	cout<<"e";
							z1=1;
							for(int it=0; it<cou(b,d); it++)
								{	for(int in=0; in<cou(b,d)-1; in++)
										{
											if(b->key[in]>b->key[in+1])
												{
													swap(b->key[i],b->key[in+1]);
												}
										}
								}
                       // m1=3;
						}
				else
                        {
							m1=2;
						}
				}

			cout<<"%"<<b->key[0];
			return b;
		}
	else {
			cout<<"h";
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
				{	cout<<"p";
					if((kount!=0))
						{	cout<<"t";
							k1=0;
							b=redib(b,d,k,0);
							cout<<"v"<<k1;
							if(k1==1)
								{
									cout<<"$";
									break;
								}
							if((k<b->key[i])||(b->key[i]==-1))
								{	cout<<"h";
									b->child[i]=insert(b->child[i],h1,k,d);
									break;
								}
							else if((b->key[(2*d)-1]!=-1)&&(b->key[(2*d)-1]<k))
								{
									cout<<"H";
									b->child[2*d]=insert(b->child[2*d],h1,k,d);
									break;
								}
							cout<<"L";
						}
					else if((count!=2*d)&&(kount==0))
						{	cout<<"q";
							if((k<b->key[i])||(b->key[i]==-1))
								{
									if(k<b->key[i])
										{
											b=arr(b,k,d,i,0);
											break;
										}
									else if(b->key[i]==-1) {
											cout<<"#";
											b->key[i]=k;
											break;
										}
								}
						}
					else if((count==2*d)&&(kount==0))
						{	cout<<"a";
							if(b==h1)
								{
									b=split(b,k,d,1,0,3);
									break;
								}
							else {
									p=1;
									cout<<"z";
									split(b,k,d,0,0,3);
								}
						}
					cout<<p<<"P";
					if(p==1) {
							cout<<"n";
							p=2;
							break;
						}
				}
			if(p==3)
				{	int f1=fn(b,a1,d);
					cout<<"R";
					if((cou(b->child[f1],d)==2*d)&&(kount!=0)&&(m!=1))
						{	cout<<"c"<<a1;
							k1=0;
							y1=1;
							if(m!=1) {
									b=redib(b,d,a1,0);
									if(k==1) {
											m=1;
										}
								}
							cout<<"v"<<k1;
							if(k1!=1) {
									if(cou(b,d)==2*d) {
											if(b==h1) {
													split(b->child[f1],a1,d,0,2,3);
													cout<<"G";
													b=split(b,a1,d,1,2,3);
													m=1;
												}
										}
									else {
											p=3;
											cout<<"z";
											split(b->child[f1],a1,d,0,2,3);
											m=1;
											if((cou(b->child[f1],d)==2*d)&&(cou(b,d)<=(2*d)-1)&&(k1!=1))
												{	if(f1==0)
														{
															if(cou(b->child[f1+1],d)==2*d)
																{
																	cout<<"*";
																	m=0;
																	p=2;
																}
														}
													else if((f1==2*d)||(b->key[f1]==-1)) {
															(cou(b->child[f1-1],d)==2*d);
															{
																cout<<"*";
																m=0;
																p=2;
															}
														}
													else {
															if(((cou(b->child[f1+1],d)==2*d))&&(cou(b->child[f1-1],d)==2*d)) {
																	cout<<"*";
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
				{	cout<<"eee";

					if((count!=2*d)&&(kount!=0)&&(m!=1))
						{	s=0;
							for(int y=0; y<=(2*d)-1; y++)
								{	cout<<a1<<"W"<<b->key[y];
									if((a1<b->key[y])||(b->key[y]==-1))
										{	m=1;
											if(a1<b->key[y])
												{
													cout<<"F";
													b=arr(b,a1,d,y,1);
													break;
												}
											else if((b->key[y]==-1))
												{	cout<<"Q";
													b->key[y]=a1;
													b->child[y]=b1;
													b->child[y+1]=b2;
													m=1;
													break;
												}
										}
								}
						}
					else if(b==h1) {
							cout<<"G";
							b=split(b,a1,d,1,2,3);
							m=1;
						}
					if((kou(b,d)!=0)) {
							cout<<"WAH";
							p=3;
						}
				}
			cout<<b->key[0]<<"d";
			return b;
		}
	else {
			return NULL;
		}
}
main()
{ifstream fin;
 	  fin.open("insert.cpp");
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
	cout<<h1->key[0];
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
			p=0;
			m=0;
			y1=0;
			cin>>c;
			b=insert(b,h1,c,d);
			h1=b;
			cout<<"b1 and b2 are\n";
			print(b1,d);
			cout<<"A";
			print(b,d);
			cout<<"B";
			print
			(b2,d);
			cout<<endl;
		}
	print(b,d);K=0;
	cout<<endl;print2(b,d,R);
	for(int i=0; i<=a; i++)
		{
			while(Q.front!=-1)
			{Q.dequeue();}
			cout<<"enter the element to be deleted\n";
			cin>>c;
			x1=0;
			w=0;
			m1=0;
			z1=0;
			k1=0;
			k2=0;
			b=search(b,h1,d,c);
			h1=b;
			print(b,d);cout<<endl;
			K=0;print2(b,d,R);
		}cout<<"all got deleted\n";
	int tt;cin>>tt;
}

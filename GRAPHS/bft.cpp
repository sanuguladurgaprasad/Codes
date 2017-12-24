#include<fstream>
#include<iostream>
using namespace std;
struct adj
{
	   int **a;
};
struct node
{
	   int vis;
	   int data;
};
class queue
{
      public:
             int size;
             int front;
             int rear;
             node elements[100];
             queue(int);
             void enqueue(node);
             node dequeue();
};
queue::queue(int z)
{
                 size=z;front=-1;rear=-1;
}
void queue::enqueue(node x)
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
         rear=(rear+1)%size;
         elements[rear]=x;
     }
}
node queue::dequeue()
{
    node t;
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
queue q(100);int t1=0;
node a1;int k;
void bft(int c,adj A,int d,node n[])
{int i;
   {
                if(k==0)
                {
                q.enqueue(n[c]);
                }
                k++;
                 if(k>1){for(i=0;i<d;i++)
	 {n[c].vis=1;
	 if((A.a[c][i]!=0)&&(n[i].vis!=1))
	 {
			   q.enqueue(n[i]);n[i].vis=1;
	 }
	 }
     }
	 }
     k++;
     if(q.front!=-1)
     {
                        a1=q.dequeue();
						{cout<<a1.data+1<<"-"<<++t1<<endl;}
     bft(a1.data,A,d,n);
     }
}
main()
{
	  ifstream fin;int g;
	  cout<<"directed press 0 else 1\n";cin>>g;
	  if(g==0){fin.open("untitled.txt");}
	  if(g==1){fin.open("untitled3.txt");}
	  int i,j,b,c,d;node *r;
	  r=new node[1];r[0].vis=-1;r[0].data=-1;
	  adj A;
	  cout<<"enter the no. of vertices\n";
	  cin>>d;
	  node *n;
	  n=new node[d];
	  for(i=0;i<d;i++)
	  {n[i].vis=0;n[i].data=i;}
	  (A.a)=new int*[d];
	  for(i=0;i<d;i++)
	  {
		   A.a[i]=new int[d];
	  }
	  for(i=0;i<d;i++)
	  {
					  for(j=0;j<d;j++)
					  {
									  fin>>A.a[i][j];cout<<A.a[i][j]<<endl;
 				      }
	  }
	  cout<<"enter starting vertex\n";
	  cin>>c;k=0;
	  bft(c-1,A,d,n);
	  for(i=0;i<d;i++)
	  {if(n[i].vis!=1)
	  {k=0;while(q.front!=-1){q.dequeue();}bft(i,A,d,n);}}
	  cin>>i;
	  fin.close();
}

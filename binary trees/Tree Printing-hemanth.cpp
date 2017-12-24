#include<iostream>
using namespace std;
struct bstnode
{
       bstnode *lchild;
       int data;
       bstnode *rchild;
};
class queue
{
      public:
             int size;
             int front,rear;
             bstnode **elements;
             queue();
             void enque(bstnode*);
             bstnode* deque();
};
queue::queue()
{
       front=-1;
       rear=-1;
      cout<<"\n Enter Size";
       cin>>size;
       elements=new bstnode*[size];
}
void queue::enque(bstnode *b)
{    
     if(front==(rear+1)%size)
     {
         cout<<"\n QUEUE IS FULL";
     }
     else
     {
         if(front==-1) front=0;
         rear=(rear+1)%size;
         elements[rear]=b;
     }
}
bstnode* queue::deque()
{
      bstnode *t;
    /*if(front==-1)
    {
       cout<<"\n QUEUE IS EMPTY";
       return(-1);
     }*/
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
     return(t);
}
bstnode* insert(bstnode *b,int k)
{
         if(b==NULL) { b=(bstnode*)new bstnode;b->data=k;
                        b->lchild=NULL;b->rchild=NULL;}
         else
         {
              if(k>b->data) b->rchild=insert(b->rchild,k);
              else {
                     if(k<b->data) b->lchild=insert(b->lchild,k);
                     else cout<<"Same data cannot be given again \n";
                    }
          }
   return(b);//each fn should return.............
}
bstnode *T;bstnode *p;
void countLDR(bstnode *t,int &k)
{
    if(T!=t)
     {
         T=T->lchild;
         countLDR(t,k);
         k++;
         //cout<<T->data<<" ";
         T=T->rchild;
         countLDR(t,k);
     }
    
}
queue Q;bstnode *NL;
bstnode *t;
void levelprint(bstnode *b,bstnode *NL)
{
   static int count=1;
   int i=0;
     if(b!=NULL)
     { count++;
       if(b->lchild!=NULL)   Q.enque(b->lchild);
       if(b->rchild!=NULL)   Q.enque(b->rchild);
       if(count==2) Q.enque(NL);
     }
       if(Q.front!=Q.rear)
       {
          t=Q.deque();
          if(t->data==-1) {cout<<"\n";Q.enque(NL); }
          else{ cout<<t->data<<" ";}
         levelprint(t,NL);
         }
}
int main()
{
    
    T=NULL;
    NL=NULL;
    NL=(bstnode*)new bstnode;
    p=(bstnode*)new bstnode;p=NULL;
    NL->data=-1;NL->lchild=NULL;NL->rchild=NULL;
    int ch,d;
    while(1)
    {
      cout<<"\n 1.Enter 2.Print 0.Exit: \n";
      cin>>ch;
      switch(ch)
            {
              case 1:cout<<"\n Enter the data:";cin>>d;T=insert(T,d);p=T;break;
              case 2:T=p;levelprint(T,NL);break;
              case 0:exit(0);break;
              default:cout<<"\n Invalid Input.Try again";
            }
    }
 system("pause");
 return(0);
}

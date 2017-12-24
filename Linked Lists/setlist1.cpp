#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
struct node
{
       int tag;
       union ad
       {
             char data;
             node *bottom;
       };
       node *next;
       ad q;
};
class stack
{
      public:
             int size;
             int top;
             node* elements[35];
             void push(node*);
             node* pop();
             stack(int);
};
stack::stack(int z)
{
size=z;
}
void stack::push(node *x)
{
     if(top==size-1)
     {
                cout<<"stack is full \n";
     }
     else
     {
     elements[++top]=x;
     }
}
node* stack::pop()
{
     if(top==-1)
     {
                cout<<"stack is empty \n";
     }
     else
     {
         return(elements[top--]);
     }
}
main()
{
      int i,p,f,g,n=0,k=0;
    char a[15];node *R[14];
      cin.getline(a,15);
      stack s(14);s.top=-1;
      for(i=0;i<15;i++)
      {
                if(a[i]=='(')
                {
                             n++;
                }
      }
      node *l,*h;
      h=new node;
      int count=1;cout<<n;
      for(i=0;i<14;i++)
      {
                if(isalpha(a[i]))
                { 
                         if((count!=1)&&(l->tag!=0)&&(l->q.bottom!=NULL))
                         {//cout<<"b"<<endl;
                         count++;
                         cout<<l->q.data<<endl;
                                     while(l->next!=NULL)
                                     {//cout<<"n";
                                                         l=l->next;
                                     }
                                     l->next=new node;
                                     l->next->q.data=a[i];
                                     l->next->tag=1;
                                     l->next->next=NULL;
                                     l=l->next;
                         }
                        /* if(count==1)
                         {//cout<<"l";
                                     count++;
                                     h->q.data=a[i];
                                     h->tag=1;h->next=NULL;l=h;
                         }*/
                         while((l->tag==0)&&(l->q.bottom==NULL))
                         {cout<<"p";
                                                                l->q.bottom=new node;
                                                                l->q.bottom->q.data=a[i];
                                                                l=l->q.bottom;
                                                                l->tag=1;
                                                                l->next=NULL;cout<<l->q.data<<endl;
                         }       
                }       
      if(a[i]=='(')
      {//cout<<"s";
      if(count==1)
                         {//cout<<"l";
                                     count++;
                                     h->q.bottom=NULL;
                                     h->tag=0;h->next=NULL;l=h;R[k]=l;s.push(R[k]);
                         }
                         if(count>2)
                         {
                   node *t;
                   t=new node;
                   t->next=NULL;
                   t->tag=0;
                   t->q.bottom=NULL;
                   l->next=t;
                   l=l->next;
                   R[k]=l;
                   s.push(R[k]);
                   k++;}
      }
      if(a[i]==')')
      {
                   node *j;
                   j=s.pop();
                   l=j;
      }
    }
    l=h;
    while(l!=NULL)
    {
                        if(l->tag==0)
                        {R[k]=l;s.push(R[k]);
                                     l=l->q.bottom;
                                     cout<<"("<<l->q.data<<",";                       
                                     k++;
                        }
                        else
                        {
                        cout<<l->q.data<<",";
                        }
                        l=l->next;
    }node *u;
    for(i=0;i<n;i++)
    {
             u=s.pop();
             l=u;
             while(l!=NULL)
             {
                           if(l->next!=NULL)
                           {
                          cout<<l->next->q.data<<",";
                           }
                           if(l->next->next!=NULL);
                           {l=l->next; }
             }      cout<<")"; 
    }
      system("pause");
}
      

#include "iostream"
using namespace std;
struct node
{
       int data;
       node *next;
}; 
void printlist(node *l)
{
     while(l!=NULL)
     {
                   cout<<l->data<<endl;
                   l=l->next;
     }
}

void add(node *l,int k)
{
     while(l->next!=NULL)
     {
                   l=l->next;
     }
     l->next=(node*)new node;
     l->next->data=k;
     l->next->next=NULL;
}
int po(int z,int v)
{
          int p=1;
          if(v!=0)
          {
          for(int i=0;i<v;i++)
          {
                  p=p*z;
          }
          return p;
          }
          else
          return p;
}

int digit(int e)
{
int d=0;
      while(e>0)
      {
                  e=e/10;
          d++;        
      }
      return d;
}
main()
{
      int a,b,c,d,e,f,g,i,j,k,s,u;
      node *h[10],*r[10];
      for(i=0;i<10;i++)
      {
                       
                      r[i]=NULL;h[i]=NULL;
      }
      cout<<"enter the elements \n";
      cin>>a;
      int w[a];
      for(i=0;i<a;i++)
      {
             cin>>c;
              w[i]=c;        
      }
int max=0;
      for(int i=0;i<a;i++)
      {
                      if(w[i]>max)
                      {
                                  max=w[i];
                      }
      }
      e=digit(max);
      for(g=0;g<e;g++)
      {
                      
                      for(j=0;j<a;j++)
                      {
                                      if(g==0)
                                      {
                                      b=w[j]%10;
                                      }
                                      if(g!=0)
                                      {
                                          u=w[j];
                                          w[j]=w[j]/(po(10,g));
                                          b=w[j]%10;
                                          w[j]=u;
                                      }
                                      if(r[b]!=NULL)
                                      {
                                     add(r[b],w[j]);
                                      }
                                      if(r[b]==NULL)
                                      {
                                       h[b]=(node*)new node;
                                      h[b]->data=w[j];
                                      h[b]->next=NULL;
                                      r[b]=h[b];
                                      }
                                      
                      }
                      f=0;
                      for(i=0;i<10;i++)
      {
                       r[i]=h[i];
      }
      k=0;
                      while(k<a)
                      {
                                      if(r[f]!=NULL)
                                      {
                                                    w[k]=r[f]->data;
                                                    {r[f]=r[f]->next;}
                                                    k++;
                                      }
                                      else
                                      {
                                          f++;
                                      }
                      } 
                      for(i=0;i<10;i++)
                       {
                                       if(g==e-1)
                                       {
                                                 break;
                                       }
                                       
                       r[i]=NULL;h[i]=NULL;
                       }    
      }
      for(i=0;i<10;i++)
      {
                       r[i]=h[i];
      }
      for(int i=0;i<10;i++)
      {
              printlist(r[i]);
              cout<<endl;
      }cin>>i;
}

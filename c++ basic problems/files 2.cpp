#include<iostream>
using namespace std;
struct node
{
       long data;
       node *next;
};
void add(node *&l,long k)
{
     while(l!=NULL)
     {
                   l=l->next;
     }
     l=(node*)new node;
     l->data=k;
     l->next=NULL;
}
void printlist(node *l)
{
     while(l!=NULL)
     {
                   cout<<l->data<<endl;
                   l=l->next;
     }
}
/*void sum(node *l,node *m,node *h)
{
     h=(node*)new node;
     h->data=l->data+m->data;
     h->next=NULL;   
}*/
main()
{
      node *l,*m,*h;
      long a,b;
      l=NULL;
      m=NULL;
      cout<<"enter \n";
      cin>>a>>b;
      add(l,a);
    //  add(l,59);
      add(m,b);
     h=(node*)new node;
     h->data=l->data+m->data;
     h->next=NULL;
     printlist(h);
     system("pause");
}

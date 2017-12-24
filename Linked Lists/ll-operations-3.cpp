   
      
#include<iostream>
using namespace std;
struct node
{
       int data;
       node *next;
}; 

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
void printlist(node *l)
{
     cout<<"  the list contains: \n";
     while(l!=NULL)
     {
                   cout<<l->data<<endl;
                   l=l->next;
     }
}
main()
{
      int a,b,c,d,e,f,g,r,p;
      node *h1,*h2,*l1,*l2,*l3,*h3;
      h1=(node*)new node;
      h2=(node*)new node;
      cout<<"enter theno.s \n";
      cin>>a>>b;
      h1->data=a;
      h1->next=NULL;
      h2->data=b;
      h2->next=NULL;
     l1=h1;
      l2=h2;
      cout<<"enter the no. of numbers u want to be in the lists \n";
      cin>>c>>d;
      cout<<"enter them in list1\n";
      for(int i=0;i<c;i++)
      {
              cin>>e;
              add(l1,e);
      }cout<<h1->next->next->data<<"P";
      cout<<"enter them in list2\n";
      for(int i=0;i<d;i++)
      {
              cin>>f;
              add(l2,f);
      }  
     printlist(l1);
     h3=(node*)new node;
    /* l3=h3;
     while(l1!=NULL)
      {
           l3->data=l1->data;
           l1=l1->next;
           if(l1!=NULL)
           {
                       l3->next=(node*)new node;
                       l3=l3->next;
           }
           else
           {
               l3->next=NULL;
           }
           
      }*/
      printlist(l2);l3=h3;l2=h2;
      g=0;
      while(l2!=NULL)
      {
                     
                     l1=h1;
                     while(l1!=NULL)
                     {
                                    if(l2->data==l1->data)
                                    {
                                                        l3->data=l1->data;
                                                          g++;
                                                         break;
                                    }
                                    else
                                    {
                                        p=3;
                                    }
                                    l1=l1->next;
                     }
                     l2=l2->next;
                     if((l2!=NULL)&&(g!=0)&&(g!=3))
                                    {
                                                l3->next=(node*)new node;
                                                l3=l3->next;
                                    }
                                    else
                                    {
                                        l3->next=NULL;
                                    }
                    /* if(g==0)
                     {
                             r=l2->data;
                             add(l3,r);
                     }
                     l2=l2->next;*/
                     
      }
      l3=h3;
      printlist(l3);
      system("pause");
}
                                 

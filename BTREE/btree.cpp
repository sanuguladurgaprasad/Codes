#include<iostream>
using namespace std;
struct btree
{
  int *key;
  btree **child;     
};int p=0,a1;btree *b1=NULL,*b2=NULL,*z;
void split2(btree *b,int k,int d)
{
     
}
void split(btree *b,int k,int d,int f)
{int u=0,v=0;
     btree *e;e=new btree;e->key=new int[(2*d)+1];e->child=new btree*[(2*d)+2];
      for(int i=0;i<=2*d;i++){e->child[i]=NULL;}
     for(int i=0;i<2*d;i++)
     {if(v==2*d-1){e->key[i]=k;break;}
             if(k<b->key[i]){if(u==0){e->key[i]=k;u++;}else{e->key[i]=b->key[i-1];}}
             else{e->key[i]=b->key[i];v++;}
     }
     for(int i=0;i<=2*d;i++)
     {
     if(k==e->key[i]){e->child[i]=b1;e->child[i+1]=b2;}
             else
             {if(k>e->key[i]){e->child[i]=b->child[i];}
             else{e->child[i]=b->child[i-1];}}
     }
     b1=new btree;b1->key=new int[2*d];
     for(int i=0;i<2*d-1;i++){b1->key[i]=-1;}b1->child=new btree*[(2*d)+1];
     for(int i=0;i<2*d;i++){b1->child[i]=NULL;}
     b2=new btree;b2->key=new int[2*d];
     for(int i=0;i<2*d-1;i++){b2->key[i]=-1;}b2->child=new btree*[(2*d)+1];
     for(int i=0;i<2*d;i++){b2->child[i]=NULL;}
     if((2*d)%2==0)
     {
        int m=0,n=0;
        a1=e->key[d];
        for(int i=0;i<d;i++){b1->key[i]=e->key[m];m++;}m++;
        for(int i=0;i<d;i++){b2->key[i]=e->key[m];m++;}
        for(int i=0;i<=d;i++){b1->child[i]=e->child[n];n++;}
        for(int i=0;i<=d;i++){b2->child[i]=e->child[n];n++;}
     }
     if(f==1)
     {z=new btree;b1->key=new int[2*d];
     for(int i=0;i<2*d-1;i++){z->key[i]=-1;}z->child=new btree*[(2*d)+1];
     for(int i=0;i<2*d;i++){z->child[i]=NULL;}
     z->key[0]=a1;z->child[0]=b1;z->child[1]=b2;
     }
}
void insert(btree *b,btree *h1,int k,int d)
{int count=0,kount=0,s=0;
     if(b!=NULL)
     {
         for(int j=0;j<2*d-1;j++){if(b->key[j]!=-1){count++;}}
         for(int r=0;r<2*d;r++){if(b->child[r]==NULL){kount++;}}
         for(int i=0;i<2*d-1;i++)
         {cout<<"p";
             if(kount!=0)
             {
                 if((k<b->key[i])||(b->key[i]==-1))
                 {
                        insert(b->child[i],h1,k,d);break;
                 }
             }
             else if((count!=2*d-1)&&(kount==0))
             {
                  if((k<b->key[i])||(b->key[i]==-1))
                  {
                     if(k<b->key[i])
                     {
                        for(int h=0;h<2*d-1;h++)
                        {if(b->key[h]!=-1){s++;}}
                        for(int t=s;t>0;t--){b->key[i+s]=b->key[i+s-1];}
                        b->key[i]=k; 
                     }
                     else if(b->key[i]==-1){b->key[i]=k;}
                  }
             }
             else if((count==2*d-1)&&(kount==0))
             {p=1;
               split(b,k,d,0);    
             }
             if(p==2)
             {
                  if((count==2*d-1)&&(kount!=0))
                  {
                        if(b==h1){split(b,a1,d,1);}
                        else{split(b,a1,d,0);}
                  }
                  else if((count!=2*d-1)&&(kount!=0))
                  {s=0;
                       for(int y=0;y<2*d-1;y++)
                       {
                       if((a1<b->key[y])||(b->key[y]==-1))
                       {if(a1<b->key[y])
                       {
                        for(int h=0;h<2*d-1;h++)
                        {if(b->key[h]!=-1){s++;}}
                        for(int t=s;t>0;t--){b->key[y+s]=b->key[y+s-1];}
                        b->key[y]=a1; 
                       }
                       }
                     else if(b->key[y]==-1){b->key[y]=a1;}  
                       }
                  }   
             }
             if(p==1){p=2;}
         }
     }
}
void print(btree *b,int d)
{
     if(b!=NULL)
     {
         for(int i=0;i<2*d-1;i++)
         {
              print(b->child[i],d);if(b->key[i]!=-1){cout<<b->key[i];}print(b->child[i+1],d);
         }
     }
}
main()
{
      int a,c,d;cout<<"enter d\n";cin>>d;
      btree *h1;h1=new btree;
      h1->key=new int[2*d];h1->key[0]=32;
      for(int i=1;i<2*d-1;i++){h1->key[i]=-1;}h1->child=new btree*[(2*d)+1];
      for(int i=0;i<2*d;i++){h1->child[i]=NULL;}btree *b;b=h1;
      cout<<"enter the no. of elements u want to insert\n";
      cin>>a;
      for(int i=0;i<a;i++)
      {
              cout<<"enter the elements\n";
              cin>>c;insert(b,h1,c,d);cout<<b->key[i];
      }
      print(b,d);
      system("pause");
}

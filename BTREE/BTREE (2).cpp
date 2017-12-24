#include<iostream>
using namespace std;
struct btree
{
  int *key;
  btree **child;
};
int p=0,m=0,a1;btree *b1=NULL,*b2=NULL,*x,*z;
void print(btree *b,int d)
{int i;
     if(b!=NULL)
     {
         for(i=0;i<=(2*d)-1;i++)
         {
              {print(b->child[i],d);}
              if(b->key[i]!=-1){cout<<b->key[i]<<"  ";}    
         }print(b->child[2*d],d);
     }
}
btree* split(btree *b,int k,int d,int f,int o)
{int u=0,v=0;
     btree *e;e=new btree;e->key=new int[(2*d)+1];e->child=new btree*[(2*d)+2];
      for(int i=0;i<=(2*d)+1;i++){e->child[i]=NULL;}
     for(int i=0;i<=2*d;i++)
     {if(v==2*d){e->key[i]=k;break;}
             if((i<2*d)&&(k<b->key[i])){if(u==0){e->key[i]=k;u++;}else{e->key[i]=b->key[i-1];}}
             else if(i==2*d){e->key[i]=b->key[i-1];}
             else{e->key[i]=b->key[i];v++;}
     }
     if(o==2){for(int i=0;i<=(2*d);i++)
     {
     if(k==e->key[i]){e->child[i]=b1;e->child[i+1]=b2;if(i==2*d){break;}}
             else
             {if(k>e->key[i]){e->child[i]=b->child[i];}
             else{e->child[i+1]=b->child[i];}}
     }
     }
     b1=new btree;b1->key=new int[2*d];
     for(int i=0;i<2*d;i++){b1->key[i]=-1;}b1->child=new btree*[(2*d)+1];
     for(int i=0;i<=2*d;i++){b1->child[i]=NULL;}
     b2=new btree;b2->key=new int[2*d];
     for(int i=0;i<2*d;i++){b2->key[i]=-1;}b2->child=new btree*[(2*d)+1];
     for(int i=0;i<=2*d;i++){b2->child[i]=NULL;}
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
     {z=new btree;z->key=new int[2*d];
     for(int i=0;i<=(2*d)-1;i++){z->key[i]=-1;}z->child=new btree*[(2*d)+1];
     for(int i=0;i<=2*d;i++){z->child[i]=NULL;}
     z->key[0]=a1;z->child[0]=b1;z->child[1]=b2;
     return z;}
     else{
     return x;}
}
btree* insert(btree *b,btree *h1,int k,int d)
{int count=0,kount=0,s=0;
     if(b!=NULL)
     {
         for(int j=0;j<=(2*d)-1;j++){if(b->key[j]!=-1){count++;}}
for(int r=0;r<=2*d;r++){if(b->child[r]!=NULL){kount++;}}
         for(int i=0;i<=(2*d)-1;i++)
         {//break for the purpose of if once inserted in the tree then other fn shud not be performed
             if((kount!=0))
             {
                 if((k<b->key[i])||(b->key[i]==-1))
                 {
                        b->child[i]=insert(b->child[i],h1,k,d);break;
                 }
                 else if((b->key[(2*d)-1]!=-1)&&(b->key[(2*d)-1]<k))
                 {b->child[2*d]=insert(b->child[2*d],h1,k,d);break;}
             }
             else if((count!=2*d)&&(kount==0))
             {
                  if((k<b->key[i])||(b->key[i]==-1))
                  {
                     if(k<b->key[i])
                     {
                        for(int h=i;h<2*d;h++)
                        {if(b->key[h]!=-1){s++;}}
                        for(int t=s;t>0;t--){b->key[i+t]=b->key[i+t-1];}
                        b->key[i]=k;break;
                     }
                     else if(b->key[i]==-1){b->key[i]=k;break;}
                  }
             }
             else if((count==2*d)&&(kount==0))
             {if(b==h1){b=split(b,k,d,1,0);break;}
               else{p=1;split(b,k,d,0,0);}
             }
             if(p==1){p=2;break;}
         }//m is for the purpose of going into only one fn rather than performing unnecessary ones;
             if(p==2)

             {
                  if((count==2*d)&&(kount!=0)&&(m!=1))
                  {
                        if(b==h1){b=split(b,a1,d,1,2);}
                        else{p=2;split(b,a1,d,0,2);}
                  }
                  else if((count!=2*d)&&(kount!=0)&&(m!=1))
                  {s=0;
                       for(int y=0;y<=(2*d)-1;y++)
                       {
                       if((a1<b->key[y])||(b->key[y]==-1))
                       {m=1;
                       if(a1<b->key[y])
                       {
                        for(int h=y;h<=(2*d)-1;h++)
                        if(b->key[h]!=-1){s++;}

for(int t=s;t>0;t--){b->key[y+t]=b->key[y+t-1];b->child[y+t+1]=b->child[y+t];}
b->key[y]=a1;b->child[y]=b1;b->child[y+1]=b2;break;
                       }
else if((b->key[y]==-1)){b->key[y]=a1;b->child[y]=b1;b->child[y+1]=b2;m=1;break;}
                       }
                       }
                  }
             }
         return b;
     }else{return NULL;}
}
main()
{
      int a,c,d,s1;cout<<"enter d and the first element\n";cin>>d>>s1;
      btree *h1;h1=new btree;
      h1->key=new int[2*d];h1->key[0]=s1;
      for(int i=1;i<=(2*d)-1;i++){h1->key[i]=-1;}h1->child=new btree*[(2*d)+1];
      for(int i=0;i<=2*d;i++){h1->child[i]=NULL;}btree *b;b=h1;
      cout<<"enter the no. of elements u want to insert\n";
      cin>>a;
      for(int i=0;i<a;i++)
      {
              cout<<"enter the elements\n";
p=0;m=0;cin>>c;b=insert(b,h1,c,d);h1=b;p=0;
      }
print(b,d);int tt;cin>>tt;
}

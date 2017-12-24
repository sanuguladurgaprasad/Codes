#include  <iostream>
using namespace std;
struct btree
{
  int *key;
  btree **child;
};
int p=0,m=0,a1;btree *b1=NULL,*b2=NULL,*x2,*z;
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
             else{e->child[i+1]=b->child[i];}}}
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
     return x2;}
}
void sort(int ar[],int x)
{int i,j;
     for(i=0;i<x;i++){for(j=0;j<x-1;j++){if(ar[j]>ar[j+1]){int t=ar[j];ar[j]=ar[j+1];ar[j+1]=t;}}}
}
btree* arr(btree *b,int k,int d,int y,int g1)
{int s=0;               for(int h=y;h<=(2*d)-1;h++){
                        if(b->key[h]!=-1){s++;}}
for(int t=s;t>0;t--){b->key[y+t]=b->key[y+t-1];if(g1==1){b->child[y+t+1]=b->child[y+t];}}
b->key[y]=k;if(g1==1){b->child[y]=b1;b->child[y+1]=b2;}return b;
}
int cou(btree *b,int d)
{int count=0;
for(int j=0;j<=(2*d)-1;j++){if(b->key[j]!=-1){count++;}}return count;
}
int kou(btree *b,int d)
{int kount=0;
for(int r=0;r<=2*d;r++){if(b->child[r]!=NULL){kount++;}}return kount;
}
int fn(btree *b,int k,int d)
{int j;for(j=0;j<2*d;j++)
{if(k<b->key[j]){break;}else if(b->key[j]==-1){break;}}return j;
}
btree* left(btree *b,int d,int k,int i)
{int j,ar[(2*d)+1],l,t1,p2,t2;
for(j=0;j<=(2*d)-1;j++){ar[j]=b->child[i]->key[j];}ar[2*d]=k;sort(ar,(2*d)+1);
for(j=1;j<=2*d;j++){b->child[i]->key[j-1]=ar[j];}t1=b->key[i-1];b->key[i-1]=ar[0];
for(l=0;l<2*d;l++){if(b->child[i-1]->key[l]!=-1){ar[l]=b->child[i-1]->key[l];}else{ar[l]=t1;break;}}sort(ar,l+1);
for(j=0;j<=l;j++){b->child[i-1]->key[j]=ar[j];}
return b;    
}
btree* right(btree *b,int d,int k,int i)
{int j,ar[(2*d)+1],l,t1,p2,t2;
for(j=0;j<=(2*d)-1;j++){ar[j]=b->child[i]->key[j];}ar[2*d]=k;sort(ar,(2*d)+1);
for(j=0;j<2*d;j++){b->child[i]->key[j]=ar[j];}t1=b->key[i];b->key[i]=ar[2*d];
for(l=0;l<2*d;l++){if(b->child[i+1]->key[l]!=-1){ar[l]=b->child[i+1]->key[l];}else{ar[l]=t1;break;}}sort(ar,l+1);
for(j=0;j<=l;j++){b->child[i+1]->key[j]=ar[j];}
return b;
}
int k1;
btree* redib(btree *b,int d,int k)
{int t1,t2,p1,p2;cout<<"D";
p1=fn(b,k,d);cout<<p1<<"WENT ";
  for(int i=p1;i<=p1;i++)
  {cout<<"OUT";if(b->child[i]!=NULL)
    {if(kou(b->child[i],d)==0){cout<<cou(b->child[i],d);
    if(cou(b->child[i],d)==2*d)
    {
      if(i==0){cout<<"GOD ";if(b->child[i+1]!=NULL){if(cou(b->child[i+1],d)!=2*d){b=right(b,d,k,i);k1=1;}}break;}
      else if((b->key[i]==-1)||(i==2*d)) 
      {cout<<"DOG ";if(cou(b->child[i-1],d)!=2*d){b=left(b,d,k,i);k1=1;}break;}
      else{cout<<"PIG ";if(cou(b->child[i-1],d)!=2*d){b=left(b,d,k,i);k1=1;}
       else if(b->child[i+1]!=NULL){if(cou(b->child[i+1],d)!=2*d){b=right(b,d,k,i);k1=1;}}break;}  
    }}
    } 
  }return b;
}
btree *ln,*x;int x1,m1,z1,r;//Leaf Node;z1 for repeating only once;
btree* search(btree *b,btree *h1,int d,int k,int j,int g)
{int i,p=0,index;btree *s;
if(b!=NULL)
{
       for(i=0;i<2*d;i++)
       {
        if(g==0)
        {
           if(k==b->key[i])
           {
              cout<<"found\n";ln=search(b,h1,d,k,i,1);
              index=cou(ln,d);b->key[i]=ln->key[index-1];
              ln->key[index-1]=-1;m1=1;r=ln->key[index-1];
           }   
           else if((b->key[i]==-1)||(k<b->key[i]))
           {
                b->child[i]=search(b->child[i],h1,d,k,0,0);
           }
           else if(i==(2*d)-1)
           {
                b->child[i+1]=search(b->child[i+1],h1,d,k,0,0);
           }
        }
       }
       if(g==1)
       {
           if(kou(b,d)==0){return b;}
           else
           {
               if(x1==0)
               {
                       x1++;b=b->child[j];p=cou(b,d);x=search(b->child[j],d,k,p-1,1); 
               }
               else
               {
                   p=cou(b);p=cou(b,d);x=search(b->child[j],d,k,p-1,1);
               }return x;
           }
       }
       if(m1==1)
       {int q;
            if((kou(b,d)!=0)&&(z1!=1))
            {
              for(q=0;q<2*d;q++)
              {
                    if(r<b->key[q]){break;}
                    else if(b->key[q]==-1){break;}
                    else if(q==(2*d)-1){q=2*d;break;}
              }  
            }
       }
}
}
btree* insert(btree *b,btree *h1,int k,int d)
{int count,kount,s=0;count=cou(b,d);kount=kou(b,d);
     if(b!=NULL)
     {
         for(int i=0;i<=(2*d)-1;i++)
         {
             if((kount!=0))
             {k1=0;b=redib(b,d,k);if(k1==1){break;} 
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
                     {b=arr(b,k,d,i,0);break;}
                     else if(b->key[i]==-1){b->key[i]=k;break;}
                  }
             }
             else if((count==2*d)&&(kount==0))
             {if(b==h1){b=split(b,k,d,1,0);break;}
               else{p=1;split(b,k,d,0,0);}
             }
             if(p==1){p=2;break;}
         }
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
                       {b=arr(b,a1,d,y,1);break;}
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
      int a,j,c,d,s1,g;cout<<"enter d\n";cin>>d>>s1;
      btree *h1;h1=new btree;
      h1->key=new int[2*d];h1->key[0]=s1;cout<<h1->key[0];
      for(int i=1;i<=(2*d)-1;i++){h1->key[i]=-1;}h1->child=new btree*[(2*d)+1];
      for(int i=0;i<=2*d;i++){h1->child[i]=NULL;}btree *b;b=h1;
      cout<<"enter the no. of elements u want to insert\n";
      cin>>a;
      for(int i=0;i<a;i++)
      {
              cout<<"enter the element\n";
p=0;m=0;cin>>c;b=insert(b,h1,c,d);h1=b;}
for(int i=0;i<a;i++)
{g=0,j=0;
              cout<<"enter the element to be deleted\n";
cin>>c;x1=0;m1=0;z1=0;b=search(b,h1,d,c,j,g);h1=b;}
print(b,d);system("pause");
}

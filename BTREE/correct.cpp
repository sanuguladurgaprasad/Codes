#include <iostream>
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
              if(b->key[i]!=-1){cout<<b->key[i]<<"i"<<i<<"  ";}
         }print(b->child[2*d],d);
     }
}btree *e;
btree* split(btree *b,int k,int d,int f,int o,int q)
{int u=0,v=0;cout<<"s";
     e=new btree;e->key=new int[(2*d)+1];e->child=new btree*[(2*d)+2];
      for(int i=0;i<=(2*d)+1;i++){e->child[i]=NULL;}
     for(int i=0;i<=2*d;i++)
     {if(v==2*d){e->key[i]=k;cout<<k;break;}
             if((i<2*d)&&(k<b->key[i])){if(u==0){e->key[i]=k;u++;}else{e->key[i]=b->key[i-1];}}
             else if(i==2*d){e->key[i]=b->key[i-1];}
             else{e->key[i]=b->key[i];v++;}cout<<e->key[i]<<"   i    ";
     }
     if((o==2)||(q==1)){for(int i=0;i<=(2*d);i++)
     {
     if(k==e->key[i]){e->child[i]=b1;e->child[i+1]=b2;cout<<"how";print(e->child[i+1],d);if(i==2*d){break;}}
             else
             {if(k>e->key[i]){e->child[i]=b->child[i];}
             else{e->child[i+1]=b->child[i];}}
     print(e->child[i],d);cout<<"Q";}
     }
	if((q!=0)&&(q!=1)){
     b1=new btree;b1->key=new int[2*d];
     for(int i=0;i<2*d;i++){b1->key[i]=-1;}b1->child=new btree*[(2*d)+1];
     for(int i=0;i<=2*d;i++){b1->child[i]=NULL;}
     b2=new btree;b2->key=new int[2*d];
     for(int i=0;i<2*d;i++){b2->key[i]=-1;}b2->child=new btree*[(2*d)+1];
     for(int i=0;i<=2*d;i++){b2->child[i]=NULL;}
        int m=0,n=0;
        a1=e->key[d];cout<<a1<<"        ";
        for(int i=0;i<d;i++){b1->key[i]=e->key[m];m++;}m++;
        for(int i=0;i<d;i++){b2->key[i]=e->key[m];m++;}
        for(int i=0;i<=d;i++){b1->child[i]=e->child[n];n++;}
        for(int i=0;i<=d;i++){b2->child[i]=e->child[n];n++;}
     if(f==1)
     {z=new btree;z->key=new int[2*d];
     for(int i=0;i<=(2*d)-1;i++){z->key[i]=-1;}z->child=new btree*[(2*d)+1];
     for(int i=0;i<=2*d;i++){z->child[i]=NULL;}
     z->key[0]=a1;z->child[0]=b1;z->child[1]=b2;
     cout<<"f";print(b2,d);print(b1,d);print(z,d);
     return z;}}
     else{
         //print(b2,d);
cout<<"S";//print(b1,d);cout<<"U";
     return x;}
}
btree* arr(btree *b,int k,int d,int y,int g1)
{int s=0;               for(int h=y;h<=(2*d)-1;h++){
                        if(b->key[h]!=-1){s++;}}
for(int t=s;t>0;t--){b->key[y+t]=b->key[y+t-1];cout<<y+t<<"T";if(g1==1){b->child[y+t+1]=b->child[y+t];}}
cout<<y<<"M";b->key[y]=k;if(g1==1){b->child[y]=b1;b->child[y+1]=b2;}return b;
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
}int k1;
btree* left(btree *b,int d,int k,int i)
{cout<<"MOM";int j,ar[(2*d)+1],l,t1,p2,t2;
if(kou(b->child[i],d)==0){split(b->child[i],k,d,0,0,0);}
else{split(b->child[i],k,d,0,0,1);}
for(j=1;j<=2*d;j++){b->child[i]->key[j-1]=e->key[j];}
if(kou(b->child[i-1],d)!=0){for(j=1;j<=(2*d)+1;j++){b->child[i]->child[j-1]=e->child[j];}}
t1=b->key[i-1];b->key[i-1]=e->key[0];
int ff=cou(b->child[i-1],d);if(kou(b->child[i-1],d)!=0){b->child[i-1]->child[ff+1]=e->child[0];}
b->child[i-1]->key[ff]=t1;cout<<"L"<<t1<<i<<ff;
return b;
}
btree* right(btree *b,int d,int k,int i)
{cout<<"DAD";int j,ar[(2*d)+1],l,t1,p2,t2;
if(kou(b->child[i],d)==0){split(b->child[i],k,d,0,0,0);}
else{split(b->child[i],k,d,0,0,1);}
for(j=0;j<2*d;j++){b->child[i]->key[j]=e->key[j];}
if(kou(b->child[i],d)!=0){for(j=0;j<=(2*d);j++){b->child[i]->child[j]=e->child[j];}}
t1=b->key[i];b->key[i]=e->key[(2*d)];
int ff=cou(b->child[i+1],d);
{for(j=ff;j>0;j--){b->child[i+1]->key[j]=b->child[i+1]->key[j-1];}}
if((b->child[i],d)!=0){for(j=ff+1;j>0;j--){b->child[i+1]->child[j]=b->child[i+1]->child[j-1];}}
b->child[i+1]->key[0]=t1;b->child[i+1]->child[0]=e->child[(2*d)+1];
return b;
}
int y1;
btree* redib(btree *b,int d,int k)
{int t1,t2,p1,p2;cout<<"D";
p1=fn(b,k,d);cout<<p1<<"WENT ";
  for(int i=p1;i<=p1;i++)
  {cout<<"OUT";if(b->child[i]!=NULL)
    {if((y1==1)||(kou(b->child[i],d)==0))
    {cout<<cou(b->child[i],d);
    if(cou(b->child[i],d)==2*d)
    {
      if(i==0){cout<<"GOD ";
if(b->child[i+1]!=NULL){if(cou(b->child[i+1],d)!=2*d){b=right(b,d,k,i);k1=1;}}break;}
      else if((b->key[i]==-1)||(i==2*d)) 
      {cout<<"DOG ";if(cou(b->child[i-1],d)!=2*d){b=left(b,d,k,i);k1=1;}break;}
      else {cout<<"PIG ";if(cou(b->child[i-1],d)!=2*d){b=left(b,d,k,i);k1=1;}
       else if(b->child[i+1]!=NULL){if(cou(b->child[i+1],d)!=2*d){b=right(b,d,k,i);k1=1;}}break;}  
    }}
    } 
  }return b;
}
btree* insert(btree *b,btree *h1,int k,int d)
{int count,kount,s=0;count=cou(b,d);kount=kou(b,d);
     if(b!=NULL)
     {
         for(int i=0;i<=(2*d)-1;i++)
         {cout<<"p";
             if((kount!=0))
             {cout<<"t";k1=0;b=redib(b,d,k);cout<<"v"<<k1;if(k1==1){cout<<"$";break;}
                if((k<b->key[i])||(b->key[i]==-1))
                 {cout<<"h";
                        b->child[i]=insert(b->child[i],h1,k,d);break;
                 }
                 else if((b->key[(2*d)-1]!=-1)&&(b->key[(2*d)-1]<k))
                 {cout<<"H";b->child[2*d]=insert(b->child[2*d],h1,k,d);break;}cout<<"L";
             }
             else if((count!=2*d)&&(kount==0))
             {cout<<"q";
                  if((k<b->key[i])||(b->key[i]==-1))
                  {
                     if(k<b->key[i])
                     {b=arr(b,k,d,i,0);break;}
                     else if(b->key[i]==-1){cout<<"#";b->key[i]=k;break;}
                  }
             }
             else if((count==2*d)&&(kount==0))
             {cout<<"a";if(b==h1){b=split(b,k,d,1,0,3);break;}
               else{p=1;cout<<"z";split(b,k,d,0,0,3);}
             }cout<<p<<"P"; 
             if(p==1){cout<<"n";p=2;break;}
         }
             if(p==3)
             {int f1=fn(b,a1,d);
                     cout<<"R";
                  if((cou(b->child[f1],d)==2*d)&&(kount!=0)&&(m!=1))
                  {cout<<"c"<<a1;
                        //if(b==h1){cout<<"G";b=split(b,a1,d,1,2,3);m=1;}
                       else {k1=0;y1=1;b=redib(b,d,a1);cout<<"v"<<k1;
                             if(k1!=1){p=3;cout<<"z";split(b->child[f1],a1,d,0,2,3);}m=1;
if((cou(b->child[f1],d)==2*d)&&(cou(b,d)<=(2*d)-1)&&(k1!=1))
{if(f1==0){if(cou(b->child[f1+1],d)==2*d){cout<<"*";m=0;p=2;}}
else if(f1==2*d){(cou(b->child[f1-1],d)==2*d);{cout<<"*";m=0;p=2;}}
else{if(((cou(b->child[f1+1],d)==2*d))&&(cou(b->child[f1-1],d)==2*d)){cout<<"*";m=0;p=2;}}}                        }
              }
             }
             if(p==2)
             {cout<<"eee";
             /*if(p==3)
             {int f1=fn(b,a1,d);
                     cout<<"R";
                  if((cou(b->child[f1],d)==2*d)&&(kount!=0)&&(m!=1))
                  {cout<<"c"<<a1;
                        if(b==h1){cout<<"G";b=split(b,a1,d,1,2);m=1;}
                        else{k1=0;y1=1;b=redib(b,d,a1);cout<<"v"<<k1;
                             if(k1!=1){p=3;cout<<"z";split(b->child[f1],a1,d,0,2);}m=1;}
                  }
             }
                  if(b==h1){cout<<"G";b=split(b,a1,d,1,2,3);m=1;}*/
                  if((count!=2*d)&&(kount!=0)&&(m!=1))
                  {s=0;
                       for(int y=0;y<=(2*d)-1;y++)
                       {cout<<a1<<"W"<<b->key[y];
                       if((a1<b->key[y])||(b->key[y]==-1))
                       {m=1;
                       if(a1<b->key[y])
                       {cout<<"F";b=arr(b,a1,d,y,1);break;}
                       else if((b->key[y]==-1))
                       {cout<<"Q";b->key[y]=a1;b->child[y]=b1;
                       b->child[y+1]=b2;m=1;break;}
                       }
                       }
                  }
                  
                  if((kou(b,d)!=0)){cout<<"WAH";p=3;}
             }
         cout<<b->key[0]<<"d";return b;
     }else{return NULL;}
}
main()
{
      int a,c,d,s1;cout<<"enter d and first element\n";cin>>d>>s1;
      btree *h1;h1=new btree;
      h1->key=new int[2*d];h1->key[0]=s1;cout<<h1->key[0];
      for(int i=1;i<=(2*d)-1;i++){h1->key[i]=-1;}h1->child=new btree*[(2*d)+1];
      for(int i=0;i<=2*d;i++){h1->child[i]=NULL;}btree *b;b=h1;
      cout<<"enter the no. of elements u want to insert\n";
      cin>>a;
      for(int i=0;i<a;i++)
      {b1=NULL;b2=NULL;
              cout<<"enter the elements\n";
p=0;m=0;y1=0;cin>>c;b=insert(b,h1,c,d);h1=b;
p=0;cout<<"b1 and b2 are\n";print(b1,d);cout<<"A";print(b,d);cout<<"B";print
(b2,d);cout<<endl;}
print(b,d);int tt;cin>>tt;
}

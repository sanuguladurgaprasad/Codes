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
         {if(b->key[i]!=-1){
              print(b->child[i],d);
              if(b->key[i]!=-1){cout<<b->key[i]<<"  ";}
             print(b->child[i+1],d);
                           }
        // else{print(b->child[i],d);}
         }
     }
}
btree* split(btree *b,int k,int d,int f,int o)
{int u=0,v=0;cout<<"s";
     btree *e;e=new btree;e->key=new int[(2*d)+1];e->child=new btree*[(2*d)+2];
      for(int i=0;i<=(2*d)+1;i++){e->child[i]=NULL;}
     for(int i=0;i<=2*d;i++)
     {if(v==2*d){e->key[i]=k;cout<<k;break;}
             if((i<2*d)&&(k<b->key[i])){if(u==0){e->key[i]=k;u++;}else{e->key[i]=b->key[i-1];}}
             else if(i==2*d){e->key[i]=b->key[i-1];}
             else{e->key[i]=b->key[i];v++;}cout<<e->key[i]<<"   i    ";
     }
     if(o==2){for(int i=0;i<=(2*d);i++)
     {//if(e->child[i]!=NULL){cout<<"W";print(e->child[i],d);cout<<"Q";}
     if(k==e->key[i]){e->child[i]=b1;e->child[i+1]=b2;}
             else
             {if(k>e->key[i]){e->child[i]=b->child[i];}
             else{e->child[i+1]=b->child[i];}}//if(e->child[i]!=NULL){cout<<"W";
     print(e->child[i],d);cout<<"Q";}
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
        a1=e->key[d];cout<<a1<<"        ";
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
     cout<<"f";print(b2,d);print(b1,d);print(z,d);
     return z;}
     else{
          print(b2,d);cout<<"S";print(b1,d);cout<<"U";
     return x;}
}
btree* insert(btree *b,btree *h1,int k,int d)
{int count=0,kount=0,s=0;
     if(b!=NULL)
     {
         for(int j=0;j<=(2*d)-1;j++){if(b->key[j]!=-1){count++;}}
for(int r=0;r<=2*d;r++){if(b->child[r]!=NULL){kount++;}}cout<<count<<kount;
         for(int i=0;i<=(2*d)-1;i++)
         {cout<<"p";
             if((kount!=0))//||((count==2*d)&&(b==h1)))
             {cout<<"t";
                 if((k<b->key[i])||(b->key[i]==-1))
                 {cout<<"h";
                        b->child[i]=insert(b->child[i],h1,k,d);break;
                 }
                 else if(count==2*d){b->child[2*d]=insert(b->child[2*d],h1,k,d);break;}
             }
             else if((count!=2*d)&&(kount==0))
             {cout<<"q";
                  if((k<b->key[i])||(b->key[i]==-1))
                  {
                     if(k<b->key[i])
                     {
                        for(int h=i;h<2*d;h++)
                        {if(b->key[h]!=-1){s++;}}cout<<s<<"*";
                        for(int t=s;t>0;t--){b->key[i+t]=b->key[i+t-1];}
                        b->key[i]=k;break;
                     }
                     else if(b->key[i]==-1){cout<<"#";b->key[i]=k;break;}
                  }
             }
             else if((count==2*d)&&(kount==0))
             {cout<<"a";if(b==h1){b=split(b,k,d,1,0);break;}
               else{p=1;cout<<"z";split(b,k,d,0,0);}
             }cout<<p<<"P";
             /*if(p==2)
             {cout<<"R";
                  if((count==2*d)&&(kount!=0))
                  {cout<<"c";
                        if(b==h1){b=split(b,a1,d,1,2);}
                        else{p=1;cout<<"z";split(b,a1,d,0,2);}
                  }
                  else if((count!=2*d)&&(kount!=0))
                  {s=0;cout<<"W";
                       for(int y=0;y<=(2*d)-1;y++)
                       {
                       if((a1<b->key[y])||(b->key[y]==-1))
                       {if(a1<b->key[y])
                       {
                        for(int h=0;h<=(2*d)-1;h++)
                        {if(b->key[h]!=-1){s++;}}
                        for(int t=s;t>0;t--){b->key[y+s]=b->key[y+s-1];}
                        b->key[y]=a1;
                       }
                       }
                     else if(b->key[y]==-1){cout<<"Q";b->key[y]=a1;}
                       }
                  }
             }*/if(p==1){cout<<"n";p=2;break;}
         }
             if(p==2)

             {cout<<"R";
                  if((count==2*d)&&(kount!=0))
                  {cout<<"c"<<a1;
                        if(b==h1){cout<<"G";b=split(b,a1,d,1,2);}
                        else{p=2;cout<<"z";split(b,a1,d,0,2);}
                  }
                  else if((count!=2*d)&&(kount!=0)&&(m!=1))
                  {s=0;
                       for(int y=0;y<=(2*d)-1;y++)
                       {cout<<a1<<"W"<<b->key[y];
                       if((a1<b->key[y])||(b->key[y]==-1))
                       {if(a1<b->key[y])
                       {cout<<"F";
                        for(int h=y;h<=(2*d)-1;h++)
                        if(b->key[h]!=-1){s++;}

for(int t=s;t>0;t--){b->key[y+t]=b->key[y+t-1];cout<<y+t<<"T";b->child[y+t+1]=b->child[y+t];}
cout<<y<<"M";b->key[y]=a1;b->child[y]=b1;b->child[y+1]=b2;break;
                       }
else if((b->key[y]==-1)){cout<<"Q";b->key[y]=a1;b->child[y]=b1;b->child[y+1]=b2;m=1;break;}
                       }
                       }
                  }
             }
         cout<<b->key[0]<<"d";return b;
     }else{return NULL;}
}
main()
{
      int a,c,d;cout<<"enter d\n";cin>>d;
      btree *h1;h1=new btree;
      h1->key=new int[2*d];h1->key[0]=32;cout<<h1->key[0];
      for(int i=1;i<=(2*d)-1;i++){h1->key[i]=-1;}h1->child=new btree*[(2*d)+1];
      for(int i=0;i<=2*d;i++){h1->child[i]=NULL;}btree *b;b=h1;
      cout<<"enter the no. of elements u want to insert\n";
      cin>>a;
      for(int i=0;i<a;i++)
      {
              cout<<"enter the elements\n";
p=0;m=0;cin>>c;b=insert(b,h1,c,d);h1=b;
p=0;cout<<"b1 and b2 are\n";print(b1,d);cout<<"A";print(b,d);cout<<"B";print
(b2,d);cout<<endl;
      }//cout<<b->child[1]->child[2]->key[0]<<endl;
int nt=0;print(b,d);for(int j=0;j<=(2*d)-1;j++){if(b->key[j]!=-1){nt++;}}if(nt==
2*d){print(b->child[2*d],d);}system("pause");
}

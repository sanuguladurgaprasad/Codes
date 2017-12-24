#include<iostream>
using namespace std;
int fund=0;
class A
{
      private:
              int m1,m2,m3;
              int sum();
              public:
                     int rolno,homno;
                     string name;
                     void input();
                     void output();
                     friend void display();
                     friend void contribute();
};
class B
{
      private:
              int m1,m2,m3;
              int sum();
              public:
                     int rolno,homno;
                     string name;
                     void input();
                     void output();
                     friend void display();
                     friend void contribute();
};
main()
{
      A *a;B *b;
      a=new A[10];
      b=new B[10];
     // for(int i=1;i<=10;i++)
      //{
                cout<<" enter rol,hom,nem/n";
              cin>>a->rolno;
              cin>>a->homno;
              cin>>a->name;
              a->input();
      //}
     // for(int i=1;i<=10;i++)
      //{
                cout<<"e \n";
              cin>>b->rolno;
              cin>>b->homno;
              cin>>b->name;
              b->input();
      //}
      display();
}
void display()
{
     A *a;B *b;
     //for(int i=1;i<=10;i++)
      //{
              cout<<a->rolno;
              cout<<a->homno;
              cout<<a->name;
              a->output();
              contribute();
      //}
      //for(int i=1;i<=10;i++)
      //{
              cout<<b->rolno;
              cout<<b->homno;
              cout<<b->name;
              b->output();
              contribute();
      //}
}
void contribute()
{
     int o;\
     o=rand();
     fund=fund+o;
}
void A::input()
{
     cout<<"enter the marks \n";
     cin>>m1>>m2>>m3;
}
void B::input()
{
     cout<<"enter the marks \n";
     cin>>m1>>m2>>m3;
}
void A::output()
{
     cout<<"total marks="<<m1+m2+m3;
}
void B::output()
{
     cout<<"total marks="<<m1+m2+m3;
}

#include<iostream>
#include<random>
using namespace std;
int fund=0;
class student
{
      public:
      static int fund;
      public:
             int rolno,homno;
             string name;
             void print();
             void contrib();
             student(int p,string q,int r);
      private:
              void sum();
              int m1,m2,m3;     
};
main()
{
      char t;
      student a(1,"suresh",234),b(2,"ramesh",432),c(3,"madesh",543);
      a.print();a.contrib();
      b.print();b.contrib();
      c.print();c.contrib();
student::fund;
    a.fund;
      cin>>t;
}
student::student(int p,string q,int r)
{
                     rolno=p;name=q;homno=r;
}
void student::contrib()
{
     int y;
     y=rand();
     fund=fund+y;
     cout<<fund;
}
void student::print()
{
     sum();
     cout<<"roll no : "<<rolno<<endl;
     cout<<"name    : "<<name<<endl;
     cout<<"home no.: "<<homno<<endl;
}
void student::sum()
{
     cout<<"enter marks \n";
     cin>>m1>>m2>>m3;
     cout<<"total marks="<<m1+m2+m3;
}

#include <iostream>
using namespace std;
class point
{             private:
                     int x,y;

      public:
             void get();
             void print();
             point add(point p,point q);
             
};
main()
{
      char t;
      point a,b,c;
     // cout<<"enter\n";
      a.get();
      cout<<"enter\n";
      b.get();
      c.add(a,b);
      cout<<endl;
     c.print();
      
      cin>>t;
}
void point::get()
{
     cout<<"enter x,y \n";
     cin>>x>>y;
}
void point::print()
{
     cout<<x<<"  "<<y;
}
point point::add(point p,point q)
{
      /*(*t).x=q.x+x;
      (*t).y=q.y+y;
      cout<<(*t).x<<" "<<(*t).y;*/
      x=p.x+q.x;
      y=p.y+q.y;
}
  

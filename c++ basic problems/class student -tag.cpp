#include <iostream>
using namespace std;
union addr
{
      int homno;
      char cellno[10];
};
class student
{
      public:
       int rollno;
       char name[10];
       int tag;
       int marks;
       union addr ad;
       
};
main()
      {
            char t;
            student *s;
            s=new student;
           // for(int i=0;i<5;i++)
            //{
                      int n=1;
                      do
                      {
                    cin>>s->rollno;
                    cin>>s->name;
                    cin>>s->marks;
                    cin>>s->tag;
                    if(s->tag==0)
                    {
                                    cin>>s->ad.homno;
                    }
                    else
                    cin>>s->ad.cellno;
            //}
            //for(int i=0;i<5;i++)
            //{
                    if(s->tag==0)
                    { 
                    cout<<s->rollno<<"\n";
                    cout<<s->name<<endl;
                    cout<<s->marks<<endl;
                    cout<<s->ad.homno<<endl;
                    }
                    else
                    {
                     cout<<s->rollno<<endl;
                    cout<<s->name<<endl;
                    cout<<s->marks<<endl;
                    cout<<s->ad.cellno<<endl;
                    }
 } while(n<3);          //}
            
cin>>t;
}

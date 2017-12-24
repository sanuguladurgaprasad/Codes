#include<fstream>
#include<iostream>
#include<cstdlib>
using namespace std;
main()
{
      char t;
      ifstream fin;
      ofstream fout;
      fout.open("l.cpp");
      char q,p=0;
      while(p<10)
      {
                 cin.get(q);
                 fout<<q;
                 p++;
      }
   //   fout.close("l.cpp");
      fin.open("l.cpp");
      while(fin)
      {
                fin.get(t);
                cout<<t;
      }
      fin.close();
          fout.close();
      cin>>t;
}

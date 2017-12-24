#include<fstream>
#include<iostream>
#include<cstdlib>
using namespace std;
main()
{
      char t;
     ifstream fin;
     ofstream fout;
      fin.open("11.cpp");
      fout.open("o.cpp",ios::app);
      char n;
      while(!fin.eof())
      {
                 fin.get(n);
                 cout<<n;
                 fout.put(n);
      }
      
      fin.close();
      fin.open("m.cpp");
      char s;
      while(fin)
      {
                fin.get(s);
                cout<<s;
                fout<<s;
      }
      fin.close();
      fout.close();
      cin>>t;
}

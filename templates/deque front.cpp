// deque::front
#include <iostream>
#include <deque>
using namespace std;

int main ()
{char t;
  deque<int> mydeque;

  mydeque.push_front(77);
  mydeque.push_front(17);
  mydeque.push_back(16);
mydeque.push_back(43);
  mydeque.front() -= mydeque.back();
  cout<<"mydeque is now \n" ;
for(int i=0;i<mydeque.size();i++)
  cout << mydeque.at(i) << endl;
cin>>t;
  return 0;
}

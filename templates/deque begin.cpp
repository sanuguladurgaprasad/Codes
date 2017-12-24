// deque::begin
#include <iostream>
#include <deque>
using namespace std;

int main ()
{char t;
  deque<int> mydeque;
  deque<int>::iterator it;

  for (int i=2; i<=5; i++) mydeque.push_back(i);

  cout << "mydeque contains:";

  it = mydeque.begin();
//cout<<mydeque.begin();
  while (it != mydeque.end())
    cout << " " << *(it++);

  cout << endl;
cin>>t;
  return 0;
}

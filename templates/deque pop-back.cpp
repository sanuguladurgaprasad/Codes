// deque::pop_back
#include <iostream>
#include <deque>
using namespace std;

int main ()
{char t;
  deque<int> mydeque;
  int sum (0);
  mydeque.push_back (10);
  mydeque.push_back (20);
  mydeque.push_back (30);

  while (!mydeque.empty())
  {
    sum+=mydeque.back();
    mydeque.pop_back();
    //mydeque.pop_front();;cout<<mydeque.pop_back();error generating
  }

  cout << "The elements of mydeque summed " << sum << endl;
cin>>t;
  return 0;
}

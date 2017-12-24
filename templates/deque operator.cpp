// assignment operator with deques
#include <iostream>//or "iostream"
#include <deque>
using namespace std;

int main ()
{char t;
  deque<int> first (3);      // deque with 3 zero-initialized ints
  deque<int> second (5);     // deque with 5 zero-initialized ints
  cout<<first.at(2);
  second=first;
  first=deque<int>();
  //first[2]=90;cout<<first.at(2);error generating
  cout << "Size of first: " << int (first.size()) << endl;
  cout << "Size of second: " << int (second.size()) << endl;
  cin>>t;
  return 0;
}

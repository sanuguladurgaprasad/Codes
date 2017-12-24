// deque::back
#include <iostream>
#include <deque>
using namespace std;

int main ()
{
  char t;
  deque<int> mydeque;
  mydeque.push_back(-1);

  while (mydeque.back() != -10){
	cout<<mydeque.back()<<" "<<mydeque.front();
    mydeque.push_back ( mydeque.back() -1 );
  }

  cout << "mydeque contains:\n";
  for (unsigned i=0; i<mydeque.size() ; i++)
    cout << " " << mydeque[i];

  cout << endl;
  cin>>t;
  return 0;
}

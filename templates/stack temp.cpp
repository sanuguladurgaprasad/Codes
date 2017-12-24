#include<iostream>
#include<stack>
using namespace std;
int main()
{char t;
	stack<int> mystack;
	for(int i=0;i<5;i++) mystack.push(i);
	int n=mystack.size();cout<<n<<endl;
	cout<<"popping the elements are";
	while(!mystack.empty())
	{
		cout<<" "<<mystack.top();
		mystack.pop();
	}
	cin>>t;
	return 0;
}
	

#include<iostream>
#include <queue>//or "queue"
using namespace std;
int main()
{ int myint;char t;
	queue<int> myqueue;
	do
	{
	cout<<"enter the value of myint";
    cin>>myint;
	myqueue.push(myint);
	cout<<" "<<myqueue.back();//cout<<" "<<myqueue.front();
	}while(myint!=-1);
	while(!myqueue.empty())
	{
	cout<<" "<<myqueue.front();
	
	myqueue.pop();
    }
    cin>>t;
    return 0;
}

	

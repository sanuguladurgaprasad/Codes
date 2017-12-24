#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <ctime>
using namespace std;

void print(vector<char> v){
	for(int i=0;i<v.size();i++)
		cout<<v[i];
	cout<<endl;
}

char *alp;int count=0;
void fun(string s,int start,int end,vector<char> v){
	if(start>end){
		print(v);
		count++;
	}
	if(start<=end){
		v.push_back(alp[s[start]-'1']);
		fun(s,start+1,end,v);
	}
	v.pop_back();
	if(start<end){
		int k=0;
		k+=10*(s[start]-'1'+1);
		k+=(s[start+1]-'1'+1);
		if(k<=26){
		v.push_back(alp[k-1]);
		fun(s,start+2,end,v);}		
	}
}

int main(){
	string s;
	vector<char> v;
	alp = new char[26];
	char alp2[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	alp=alp2;
	cin>>s;
	int start_s=clock();
	fun(s,0,s.length()-1,v);
	int stop_s=clock();
	cout<<count<<" time="<<(stop_s-start_s);
	return 0;
}

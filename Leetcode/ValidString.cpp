#include <iostream>
#include <string>
using namespace std;

string isValid(string s){
    // Complete this function
    int u=0,count=0,count1=0;
    int A[26]={0},arr[2];
    for(int i=0;i<s.length();i++){
        A[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(A[i]>0 && count==0){
            arr[0]=A[i];
        }
        if(A[i]!=0 && arr[0]!=A[i]&&u==0){
            u++;
            arr[1]=A[i];
        }
        if(u>0 && A[i]!=0 && arr[0]!=A[i] && arr[1]!=A[i]){
            return "NO";
        }
        if(A[i]>0)count++;
        if(A[i]!=0 && A[i]==arr[0])count1++;
    }
    for(int i=0;i<26;i++){
        cout<<A[i]<<endl;
    }
    //cout<<u<<" "<<arr[0]<<" "<<arr[1]<<" "<<count<<" "<<count1<<endl;
    if(u==1 && arr[0]==1 ||arr[1]==1)return "YES";
    if(arr[1]-arr[0]>1||arr[0]-arr[1]<-1)return "NO";
    if(u==0 || (count==2 && (arr[1]-arr[0]==1||arr[0]-arr[1]==1)))return "YES";
    if(count>2 && count1==1 && (arr[0]-arr[1]==1))return "YES";
    if(count>2 && count1>1 && (arr[1]-arr[0]==1))return "YES";
    return "NO";
}

int main() {
    string s;
    cin >> s;
    string result = isValid(s);
    cout << result << endl;
    return 0;
}


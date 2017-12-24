#include <iostream>
using namespace std;

int main(){
	int n,t,q=0;
	cin>>t;
	int b[4]={1,5,10,25};
	while(q++<t){
		cin>>n;
		long long ar[4][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<4;j++){
				if(i-(b[j])==-1){
					ar[j][i]=1;
				}
				else if(i-(b[j])>=0){
					ar[j][i]=0;
					for(int k=j;k<4;k++)
						ar[j][i]+=ar[k][i-b[j]];
				}
				else{
					ar[j][i]=0;
				}
			}
		}
		cout<<ar[0][n-1]+ar[1][n-1]+ar[2][n-1]+ar[3][n-1]<<endl;
	}
}

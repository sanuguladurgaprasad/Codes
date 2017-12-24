#include <iostream>
using namespace std;

int main(){
	int n,t,k=0;
	cin>>t;
	while(k++<t){
		cin>>n;
		long long ar[3][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				if(i-(j+1)==-1){
					ar[j][i]=1;
				}
				else if(i-(j+1)>=0){
					ar[j][i]=ar[0][i-(j+1)]+ar[1][i-(j+1)]+ar[2][i-(j+1)];
				}
				else{
					ar[j][i]=0;
				}
			}
		}
		cout<<ar[0][n-1]+ar[1][n-1]+ar[2][n-1]<<endl;
	}
}

#include <iostream>

using namespace std;
const int N = 100005;
int num[N],sum[N];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		sum[i]=sum[i-1]+num[i];
	}
	
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		cout<<sum[b]-sum[a-1]<<endl;
	}
	return 0;
} 

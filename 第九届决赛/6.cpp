#include <iostream>
#include <cstdio>

using namespace std;
#define mod 1000000007
long long sum=0;
int main(){
	int n;
	scanf("%d",&n);
	sum=n*n;
	for(int i=2;i<=n;i++){
		sum--;
		sum+=(i*i)%mod;
		//cout<<endl<<i*i<<' ';
		for(int j=i-1;j>1;j--){
			if(2*i-j>=1&&2*i-j<=n&&j>=0&&j<=n){
			sum-=2;
			sum+=(2*(j*j)%mod);
			//cout<<j*j<<' ';
			}
		}
	}
	cout<<sum;
	return 0;
}

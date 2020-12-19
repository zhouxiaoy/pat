#include <iostream>
#include <cstdio>
 
using namespace std;
const long long mod = 1000000007;

long long dp[55][55][15][15];


int main(){
	int n,m,K;
	int a[55][55];
	//代表在x，y坐标拿啦多少件宝贝最大价值是多少 
	
	cin>>n>>m>>K;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			a[i][j]++;//便于分辨当宝贝价值为0时，拿啦还是没拿 
		}
	}
	
	dp[1][1][0][0]=1;
	dp[1][1][1][a[1][1]]=1;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k<=K;k++){
				for(int l=0;l<=13;l++){
					int map = a[i][j];
					if(i==1){
						dp[i][j][k][l]=(dp[i][j-1][k][l]+dp[i][j][k][l])%mod;
						if(map>l&&k){
							dp[i][j][k][map] = (dp[i][j-1][k-1][l]+dp[i][j][k][map])%mod;
						}
					} 
					else if(j==1){
						dp[i][j][k][l]=(dp[i-1][j][k][l]+dp[i][j][k][l])%mod;
						if(map>l&&k){
							dp[i][j][k][map] = (dp[i-1][j][k-1][l]+dp[i][j][k][map])%mod;
						}
					}else{
						dp[i][j][k][l]=(((dp[i-1][j][k][l]+dp[i][j][k][l])%mod)+dp[i][j-1][k][l])%mod;
						if(map>l&&k){
							dp[i][j][k][map] = (((dp[i-1][j][k-1][l]+dp[i][j][k][map])%mod)+dp[i][j-1][k-1][l])%mod;
						}
					}
				} 
			}
		}
	}
	long long sum=0;
	for(int i=0;i<=13;i++){
		sum = (dp[n][m][K][i]+sum)%mod;
	}
	printf("%lld", sum);
	return 0;
}

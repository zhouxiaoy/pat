#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n,a;
	int s[105]={0},dp[105][105]={0};
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		s[i]=s[i-1]+a;
		dp[i][i]=a;
	}
	
	for(int i=n-1;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			dp[i][j]=max(s[j]-s[i-1]-dp[i][j-1],s[j]-s[i-1]-dp[i+1][j]);
		}
	}
	
	printf("%d %d",dp[1][n],s[n]-dp[1][n]);
	return 0;
} 

#include <iostream> 
#include <cstdio>
using namespace std;
int time[105],val[105];
int dp[1005];
int main(){
	int T,M;
	scanf("%d%d",&T,&M);
	for(int i=1;i<=M;i++){
		scanf("%d%d",&time[i],&val[i]);
	}
	for(int i=1;i<=M;i++){
		for(int j=T;j>=0;j--){
			if(j>=time[i])
				dp[j]=max(dp[j],dp[j]+val[i]);
		}
		
	}
	return 0;
}

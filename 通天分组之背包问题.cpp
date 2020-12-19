#include<bits/stdc++.h> 
using namespace std;
const int M=1010;
int dp[M],a[M],b[M],c[101][20],cc[101];
int main(){
	int m,n,C,max_c=0;
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&C);
		max_c=max(max_c,C);
		cc[C]++;
		c[C][cc[C]]=i;
	}
	for(int i=1;i<=max_c;i++){//模拟组数 
		for(int j=m;j>=0;j--){
			for(int k=1;k<=cc[i];k++){
				if(j>=a[c[i][k]])
				dp[j]=max(dp[j],dp[j-a[c[i][k]]]+b[c[i][k]]);//套用状态转移方程 
			}
		}
	}
	printf("%d\n",dp[m]); 
	return 0;
} 

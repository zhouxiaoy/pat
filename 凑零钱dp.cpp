#include <iostream>
using namespace std;
int n,m,dp[10010];
int w[10010];
bool choice[10010][10010];

int cmp(int a,int b){
	return a>b;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	sort(w+1,w+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=m;j>=w[i];j--){
			if(dp[j]<=dp[j-w[i]]+w[i]){
				choice[i][j]=true;
				dp[j]=dp[j-w[i]]+w[i];
			}
		}
	}
	
	return 0;
} 

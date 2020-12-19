#include <cstdio>
#include <iostream>
using namespace std;
int sum=0;
int dis[35];

void dfs(int n){
	if(n==31){
		sum++;
		return;
	}
	
	if(dis[n-1]==0){
		dis[n]=1;
		dfs(n+1);
		dis[n]=0;
	}
	dfs(n+1);
}
int main() {
	dfs(1);
	cout<<sum;
	return 0;
}

#include <iostream>
using namespace std;

const int dis[2][9]={{0,-2,-1,1,2,2,1,-1,-2},{0,1,2,2,1,-1,-2,-2,-1}};//马的方向 
long long dp[23][23]={0};
bool vis[23][23];

int main(){
	int mx,my,bx,by;
	cin>>bx>>by>>mx>>my;
	//将各个点往右下移动一个格子 
	bx++;
	by++;
	mx++;
	my++;
	//将可以走的地方标记为true，代表不可以走 
	for(int i=0;i<9;i++){
		int xx=dis[0][i]+mx;
		int yy = dis[1][i]+my;
		if(xx>=0&&xx<=bx+1&&yy>=0&&yy<=by+1){
			vis[xx][yy]=true;
		}
	}
	//标记第一个点为1 
	dp[1][1] = 1;
	vis[1][1] = true;

	for (int i = 1; i <= bx; i++) {
		for (int j = 1; j <= by; j++) {
			if (!vis[i][j])
			//因为之前将各个点下标往下移动了，
			//所以实际上是从1，1 下标开始遍历的
			//所以不用担心越界的问题 
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	cout<<dp[bx][by];
	return 0;
} 

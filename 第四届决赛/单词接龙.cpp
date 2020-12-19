#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
const int maxn = 100+10;
struct node{
	int x,y;
}c[maxn];//¼ÇÂ¼Â·¾¶ 
char fz[maxn][maxn],stand[] = "yizhong"; 
int vis[maxn][maxn],n;
int dir[8][2]={
	{-1,-1},
	{-1,0},
	{1,0},
	{0,-1},
	{0,1},
	{1,1},
	{1,-1},
	{-1,1}
};
void dfs(int x,int y,node c[],int k,int cur){
	if(cur==7){
		for(int i=0;i<7;i++){
			vis[c[i].x][c[i].y]=1;
		}
	}else{
		int dx = x + dir[k][0];
		int dy = y + dir[k][1];	
		if(cur==6||fz[dx][dy]==stand[cur+1]){
			c[cur].x=x;
			c[cur].y=y;
			dfs(dx,dy,c,k,cur+1);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",fz[i]);
	}
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(fz[i][j]=='y'){
				for(int k=0;k<8;k++){
					int x=i+dir[k][0];
                    int y=j+dir[k][1];
                    if(fz[x][y]=='i')
                        dfs(i,j,c,k,0);
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(vis[i][j])
				printf("%c",fz[i][j]);
			else
				printf("*");
		}
		printf("\n");
	}
	return 0;
} 

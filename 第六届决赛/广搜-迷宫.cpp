#include <iostream>
#include <memory.h>
#include <cstdio>
using namespace std;
int n,m;
char str[1005][1005];
bool vis[1005][1005];
int dis[4][2]={0,1,0,-1,1,0,-1,0};
void bfs(int x,int y,char flag){
	if(x<0||x>n||y<0||y>n)
		return;
	vis[x][y]=true;
	for(int i=0;i<4;i++){
		int xx = dis[i][0]+x;
		int yy = dis[i][1]+y;
		if(xx>=0&&xx<=n&&yy>=0&&y<=n){
			if(flag=='0'&&str[xx][yy]=='1') 
				bfs(xx,yy,'1');
			else if(flag=='1'&&str[xx][yy]=='0')
				bfs(xx,yy,'0');
		}
	}
}
int main(){

	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",str[i]);
	}
	for(int i=0;i<m;i++){
		int a,b,sum=0;
		scanf("%d %d",&a,&b);
		memset(vis,0,sizeof(vis));
		bfs(a,b,str[a][b]);
		for(int k=1;k<=n;k++){
			for(int j=1;j<=n;j++){
				if(vis[k][j]==true)
					sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
 

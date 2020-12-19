#include <iostream>
#incuede <cstdio>
using namespace std;
int fenzu[6][6];
char zimu[6][6];
bool vis[6][6];
int dis[4][2]={
	1,0,
	-1,0,
	0,1,
	0,-1
}; 
void dfs(int x,int y){
	if(x<0||x>=6||y<0||y>=6)
		return;
	if(x == 5 && y == 5){
		for(int i=0;i<6;i++){
			for(int j=0;j<6;j++){
				printf("%d",fenzu[i][j]);
			}
			cout<<endl;
		}
	}
	for(int i=0;i<4;i++){
		int xx = x+dis[i][0];
		int yy = y+dis[i][1];
		if(xx>=0&&xx<6&&yy>=0&&yy<6){
			//ÅÐ¶ÏÊÇ·ñÂú×ãÌõ¼þ
			 for(int i=0;i<6;i++){
			 	for(int j=0;j<6;j++){
			 		if('A'+i != )
			 	}
			 } 
		}
	}
}
int main(){
	int n;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			scanf("%d",&fenzu[i][j]);
		}
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y;
		char c;
		scanf("%d %d %c",&x,&y,&c);
		zimu[x][y]=c;
	}
	return 0;
} 

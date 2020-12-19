#include <iostream>
#include <cstdio>
using namespace std;

int e[205][205];//i到j的距离 
int main(){
	int n,m;//n代表城市数，m代表路径数
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		e[a][b]=e[b][a]=c;
	}
	
	int k,tot=1,v = -1,minn = 0x3f3f3f;
	cin>>k;//要判断路径的数目 
	for(int i=0;i<k;i++){
		int u,flag = 1,sum = 0;
		cin>>u;//路径经过的城市的个数 
		int next[205],vis[205]={0};//判断该结点是否走过 
		cin>>next[0];
		for(int j=1;j<u;j++){
			cin>>next[j];
			//该节点可以走下去 
			if(e[next[j-1]][next[j]]!=0){
				sum+=e[next[j-1]][next[j]];
				vis[next[j]]++;
			}else{
				flag = -2;//代表该节点走不了 
			}
		}
		if(flag != -2){
			for(int j=1;j<=n;j++){
					if(vis[j]>1&&flag == 1)
						flag = 0;//多走了 则表示不是最简环 
					else if(vis[j]<1)
						flag = -1;//没走过所有的city 
			}
			if(next[0]!=next[u-1])flag = -1;
			if(flag >=0&&minn>sum) {
				minn = sum;
				v = tot;
			}
		}
		if(flag == 1)
			printf("Path %d: %d (TS simple cycle)\n",tot++,sum);
		else if(flag == 0)
			printf("Path %d: %d (TS cycle)\n",tot++,sum);
		else if(flag == -2)
			printf("Path %d: NA (Not a TS cycle)\n",tot++);
		else
			printf("Path %d: %d (Not a TS cycle)\n",tot++,sum);
	}
	printf("Shortest Dist(%d) = %d\n",v,minn);
	return 0;
}

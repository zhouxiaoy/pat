#include <iostream>
#include <cstdio>
#include <cstring> 
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int N = 510,INF = 0x3f3f3f3f;
int h[N],e[N],ne[N],w[N],idx; 
int dist[N],ans[N];
bool vis[N];
//这里保存的是pre[i] =  j，i结点的最短节点的上一个结点为j 
vector<int> pre[N],temp[N];

int n,m,c1,c2;

void add(int a,int b,int c){
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void spfa(){
	memset(dist,0x3f,sizeof dist);
	
	dist[c1] = 0;
	vis[c1] = true;
	queue<int> q;
	q.push(c1);
	
	while(q.size()){
		int t = q.front();
		q.pop();
		vis[t] = false;
		
		for(int i = h[t]; h[t] != -1;t = ne[t]){
			int j = e[i];
			//有更小的路径 
			if(w[i] + dist[t] < dist[j]){
				dist[j] = dist[t] + w[i];
				pre[j].clear();
				pre[j].push_back(t);
				if(!vis[j]){//入队列 
					q.push(j);
					vis[j] = true;
				}
			}//有两条相同的路 
			else if(dist[t] + w[i] == dist[j]){
				pre[j] = push_back(t); 
			} 
		}
	}
}

//最短路劲 能聚集的最多的人数 
int cnt = 0;

void dfs(int x){
	if(x == c1){//找到起点了 
		int t = 0;
		for(int i = temp.size() - 1; i >= 0; i --){
			int u = temp[i];
			t += ans[u];
		}
		if(t > cnt)
			cnt = t; 
	}
	else{
		sum +=
	}
} 

int main(){
	memset(h,-1,sizeof h);
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	for(int i=0;i<n;i++)
		scanf("%d",&ans[i]);
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c),add(b,a,c);
	}
	
	spfa();
}

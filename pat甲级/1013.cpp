//dfs版本 
#include<cstdio>
#include<cstring>
#include <queue>
using namespace std;

int load[1005][1005];//保存路径 
bool vis[1005];//该节点是否被访问过 
int main(){
	int n,m,k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d", &a, &b);
		load[a][b]=load[b][a]=1;
	}
	
	for(int i=0;i<k;i++){
		memset(vis,false,sizeof vis);
		int a;
		scanf("%d", &a);
		vis[a]=true;
		
		int ans=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==false){
				queue<int> q;
				q.push(j);
				ans++;
				while(q.size()){
					int t = q.front();
					q.pop();
					for(int j=1;j<=n;j++){
						if(vis[j]==false&&load[t][j]!=0){
							vis[j]=true;
							q.push(j);
						}
					}
				}
			}
		}
		printf("%d\n", ans - 1);
	}
	return 0;
} 

//dfs版本 
/*
#include<iostream>
#include<cstring>
#include <queue>
using namespace std;

int load[1005][1005];//保存路径 
bool vis[1005];//该节点是否被访问过 
int n, m, k;

void dfs(int idx) {
	vis[idx] = true;
	for (int i = 1; i <= n; i++) {
		if (load[idx][i] == 1 && vis[i] == false) {
			dfs(i);
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		load[a][b] = load[b][a] = 1;
	}

	for (int i = 1; i <= k; i++) {
		memset(vis, false, sizeof vis);
		int a;
		scanf("%d", &a);
		vis[a] = true;
		int ans = 0;
		for (int j = 1; j <= n; j++)
			if (vis[j] == false) {
				dfs(j);
				ans++;
			}
		printf("%d\n", ans - 1);
	}
	return 0;
}
*/

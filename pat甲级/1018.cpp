//从原点到sp的过程中修正所有点，
//但是不会把多余的自行车再送回之前的点，
//比如一条路上bike数为 3 10，是send2，back5，而不是back3。

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int inf = 0x3f3f3f3f;
int wei[505],e[505][505],dis[505];
bool vis[505];
vector<int> pre[505];
vector<int> temp,path;
int minNeed = inf,minBack = inf;

void dfs(int idx){
	temp.push_back(idx);
	if(idx == 0){
		int need = 0,back = 0;
		for(int i=temp.size()-1;i>=0;i--){
			int id = temp[i];
			if(wei[id]>0)
				back+=wei[id];
			else{
				if(back> (0-wei[id]))
					back+=wei[id];
				else{
					need += ((0-wei[id])-back);
					back = 0;
				}
			}
		}
		if(need <minNeed){
			minNeed = need;
			minBack = back;
			path = temp;
		}else if(need == minNeed && back <minBack){
			minBack = back;
			path = temp;
		}
		temp.pop_back();
		return;
	}
	
	for(int i=0;i<pre[idx].size();i++)
		dfs(pre[idx][i]);
	temp.pop_back();
} 

int main(){
	memset(e,0x3f,sizeof e); 
	memset(dis,0x3f,sizeof dis);
	int cmax,n,m,sp;
	scanf("%d %d %d %d",&cmax,&n,&sp,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&wei[i]);
		wei[i]-=cmax/2;//cmax/2 
	}
	
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		e[a][b] = e[b][a] = c;
	}
	
	dis[0]= 0;
	
	for(int i=0;i<=n;i++){
		int minn = inf,u = -1;
		for(int j=0;j<=n;j++){
			if(vis[j] == false&&dis[j] < minn){
				minn = dis[j];
				u = j;
			}
		}
		
		if(u == -1)break;
		vis[u] = true;
		
		for(int j=0;j<=n;j++){
			if(vis[j]==false&&e[u][j]!=inf){
				if(dis[u]+e[u][j]<dis[j]){
					dis[j]=dis[u]+e[u][j];
					pre[j].clear();
					pre[j].push_back(u);
				}else if(dis[u] + e[u][j] == dis[j]){
					pre[j].push_back(u);
				}
			}
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=0;j<pre[i].size();j++)
			cout<<pre[i][j]<<' ';
		cout<<endl;
	}
	*/
	/* 
	int idx = sp;
	int ans = wei[sp];
	//不能递推 因为不能确保调动的车辆最小
	//虽然能保证下次这次为最小，但这次加上下次之和的结果不一定 
	while(idx>0){
		int u = 0;
		path.push_back(idx);
		for(int i=1;i<pre[idx].size();i++)
			if(abs(wei[pre[idx][i]]+ans)<abs(wei[pre[idx][u]]+ans))
				u = i;
		
		ans += wei[pre[idx][u]];
		idx = pre[idx][u];
	}
	*/ 
	dfs(sp);
	printf("%d 0",minNeed);
	for(int i=path.size()-2;i>=0;i--)
		printf("->%d",path[i]);
	printf(" %d",minBack);
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
int cmax, n, cp, m;
int minNeed = inf, minBack = inf;
int e[510][510], dis[510], weight[510];
bool visit[510];
vector<int> pre[510];
vector<int> path, temppath;

void dfs(int v) {
	temppath.push_back(v);
	if (v == 0) {
		int need = 0, back = 0;
		//找出这一条路径下需求是多的还是少的
		for (int i = temppath.size() - 1; i >= 0; i--) {
			int id = temppath[i];
			if (weight[id] > 0) {//如果该节点车辆多了，返回+=该值
				back += weight[id];
			}
			else {
				if (back > (0 - weight[id])) {//如果该节点车辆少了，但是从其他结点调车之后，总需求是多的
					back += weight[id];
				}
				else {
					need += ((0 - weight[id]) - back);//该节点车辆少了，并且总需求是少的
					back = 0;
				}
			}
		}
		//判断是否为需要最少的路径
		if (need < minNeed) {
			minNeed = need;
			minBack = back;
			path = temppath;
		}
		//判读是否是回收最少的路径
		else if (need == minNeed && back < minBack) {
			minBack = back;
			path = temppath;
		}
		//删除该节点
		temppath.pop_back();
		return;
	}
	//找出该节点之前的结点
	for (int i = 0; i < pre[v].size(); i++)
		dfs(pre[v][i]);
	temppath.pop_back();
}

int main() {
	memset(e, 0x3f, sizeof e);
	memset(dis, 0x3f, sizeof dis);
	scanf("%d %d %d %d", &cmax, &n, &cp, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &weight[i]);
		weight[i] = weight[i] - cmax / 2;
	}
	for (int i = 0; i < m; i++) {
		int a,b,c;
		scanf("%d %d %d", &a, &b,&c);
		e[b][a] = e[a][b]=c;
	}

	dis[0] = 0;
	for (int i = 0; i <= n; i++) {
		int idx = -1,minn=inf;
		for (int j = 0; j <= n; j++) {
			if (visit[j] == false && dis[j] < minn) {
				idx = j;
				minn = dis[j];
			}
		}

		if (idx == -1)break;
		visit[idx] = true;
		for (int j = 0; j <= n; j++) {
			if (visit[j] == false && e[idx][j] != inf) {
				if (dis[j] > dis[idx] + e[idx][j]) {
					dis[j] = dis[idx] + e[idx][j];
					pre[j].clear();
					pre[j].push_back(idx);
				}
				else if (dis[j] == dis[idx] + e[idx][j]) {
					pre[j].push_back(idx);
				}
			}
		}
	}
	dfs(cp);
	printf("%d 0", minNeed);
	for (int i = path.size() - 2; i >= 0; i--)
		printf("->%d", path[i]);
	printf(" %d", minBack);
	return 0;
}
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#define maxn 100005
using namespace std;

int n;
int sum[maxn]={0},visit[maxn]={0};
queue<int> q;
vector<int> MGraph[maxn]; 
void topSort(){
	//while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++){
		if(sum[i]==1){
			q.push(i);
			visit[i]=1;
		}
	}
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i=0;i<MGraph[cur].size();i++){
			int v = MGraph[cur][i];
			sum[v]--;
			if(sum[v] == 1){
				visit[v] = 1;
				q.push(v);
			} 
		}
	}
}
int main(){
	int b,a;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		MGraph[a].push_back(b);
		MGraph[b].push_back(a);
		sum[a]++;
		sum[b]++;
	}
	topSort();
	bool flag = true;
	for(int i=1;i<=n;i++){
		if(visit[i]==0){
			if(flag) {
				printf("%d",i);
				flag = false;
			}else{
				printf(" %d",i);
			}
		}
	}
	return 0;
} 

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[105];
int sum[105];//同一深度的人数 

int maxDep= -1;
void dfs(int root,int dep){
	sum[dep]++;//人数加1 
	if(v[root].size() == 0){
		maxDep = max(maxDep,dep);
		return;	
	}
	for(int i=0;i<v[root].size();i++)
		dfs(v[root][i],dep+1);
} 

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int id,k;
		scanf("%d%d",&id,&k);
		for(int j=0;j<k;j++){
			int a;
			scanf("%d",&a);
			v[id].push_back(a);
		}
	}
	
	dfs(1,0);
	
	int maxLevel = 0;
	for(int i=1;i<=maxDep;i++)
		if(sum[i]>sum[maxLevel])
			maxLevel = i;
	
	printf("%d %d\n",sum[maxLevel],maxLevel+1);
	return 0;
}

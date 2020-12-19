#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int maxdepth=-1;
int book[100]={0};
vector<int> v[100];

void dfs(int node,int dep){
	if(v[node].size()==0){
		maxdepth = max(maxdepth,dep);
		book[dep]++;
		return;	
	}
	
	for(int i=0;i<v[node].size();i++)
		dfs(v[node][i],dep+1);
}
int main(){
	int n,m,node,c,k;
	
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&node,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&c);
			v[node].push_back(c);
		}
	}
	
	dfs(1,0);
	
	printf("%d",book[0]);
	for(int i=1;i<=maxdepth;i++)
		printf(" %d",book[i]);
	return 0;
}

/*
//BFS版本 
#include <iostream>
#include <queue> 
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
	int n, m, k, node, c, maxdepth = -1, depth = 1;
	vector<int> v[100];
	int book[100] = { 0 };
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &node, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &c);
			v[node].push_back(c);
		}
	}
	queue<int> q;
	q.push(1);
	while (q.size()) { 
		int size = q.size();
		for (int j = 0; j < size; j++) {
			int t = q.front();
			q.pop();
			//if(v[t].size()==0)book[depth-1]++;
			for (int i = 0; i < v[t].size(); i++) {
				if (v[v[t][i]].size() == 0)
					book[depth]++;
				else
				q.push(v[t][i]);
			}
		}
		depth++;
	}
	if(n==1)printf("1");//如果只有根结点 
	else{
		printf("%d", book[0]);
		for (int i = 1; i < depth; i++) {
			printf(" %d", book[i]);
		}
	}
	return 0;
}
*/

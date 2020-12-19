#include <iostream>
#include <cstdio>
#include <vector>
#include <queue> 
using namespace std;

vector<int> v[100005];
int maxPeo = 0,MinDep = 0x3f3f3f;

void dfs(int root,int dep){
	if(v[root].size() == 0){
		if(dep<MinDep){ 
			MinDep = dep;
			maxPeo = 1; 
		} 
		else if(dep == MinDep)
			maxPeo++;
		return;
	}
	
	for(int i=0;i<v[root].size();i++)
		dfs(v[root][i],dep+1); 
}

int main(){
	int n;
	double p,r;
	scanf("%d%lf%lf",&n,&p,&r);
	for(int i=0;i<n;i++){
		int k,a;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&a);
			v[i].push_back(a);
		}
	}
	
	dfs(0,0);
	/* bfs 
	int dep = 0,ans = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
	    ans = q.size();
    	while(ans--){
    	    int t = q.front();
    	    q.pop();
    	    if(v[t].size() == 0){//叶子节点
    	        if(dep<MinDep){
    	            MinDep = dep;
    	            maxPeo = 1;
    	        }else if(MinDep == dep)
    	            maxPeo ++;
    	    }
    	    for(int i=0;i<v[t].size();i++)
    	        q.push(v[t][i]);
	    }
	    dep++;//层数加1
	}
	*/ 
	
	for(int i=0;i<MinDep;i++)
		p = p*(100+r)/100;	
	printf("%.4lf %d",p,maxPeo);
	return 0;
} 

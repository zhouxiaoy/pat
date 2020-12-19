#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
vector<int> v[100005];

int maxDep = -1,maxSum= 0;
void dfs(int root,int dep){
	if(v[root].size() == 0){
		if(maxDep == dep)
			maxSum++;
		else if(maxDep<dep){//这里必须时maxDep<dep  之前用的是直接else 会出现一个错误点 
			maxDep = dep;
			maxSum = 1;
		} 
		return;
	}
	for(int i=0;i<v[root].size();i++)
		dfs(v[root][i],dep+1); 
}

int main(){
	int n,root;
	double p,r;
	scanf("%d%lf%lf",&n,&p,&r);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		if(a != -1)
			v[a].push_back(i);
		else
			root = i;
	}
	
	dfs(root,0);
	
	for(int i=0;i<maxDep;i++)
		p = p*(100+r)/100;
		
	printf("%.2lf %d\n",p,maxSum);
	return 0;
} 

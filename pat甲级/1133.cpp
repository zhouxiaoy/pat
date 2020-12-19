#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct node{
	int add,data,next;
};

node temp[100000]; 

int main(){
	int root,n,k;
	scanf("%d%d%d",&root,&n,&k);
	vector<node> v[3],ve;
	node t;
	
	for(int i=0;i<n;i++){
		int idx;
		scanf("%d",&idx);
		scanf("%d%d",&temp[idx].data,&temp[idx].next);
		temp[idx].add = idx;
	}
	
	
	while(root != -1){
		if(temp[root].data<0) v[0].push_back(temp[root]);
		else if(temp[root].data <= k) v[1].push_back(temp[root]);
		else v[2].push_back(temp[root]);
		root = temp[root].next;
	}
	for(int i=0;i<3;i++)
		for(int j = 0;j<v[i].size();j++)
			ve.push_back(v[i][j]);
			
	//printf
	printf("%05d %d ",ve[0].add,ve[0].data);
	for(int i=1;i<ve.size();i++)
		printf("%05d\n%05d %d ",ve[i].add,ve[i].add,ve[i].data);
	puts("-1");
	return 0;
} 

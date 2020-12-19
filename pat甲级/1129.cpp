//很重要的一题，
//找出前k个最大的数
//用set进行 去重+ 自定义排序
//去重时候需要找到并删除，不然不会进行排序
//insert，find等默认参数是set<T>里的T 
#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int n,k;
int vis[50005];

struct node{
	int idx,cnt;
	node(int i,int cnt){
	    this->idx = i;
	    this->cnt = cnt;
	}
	bool operator <(const node &a)const{
		if(this->idx == a.idx)return false;//根据idx去重 
		else{
			if(this->cnt != a.cnt) 
			    return this->cnt > a.cnt; 
			else return this->idx < a.idx;
		}
	}
};



int main(){
	int a;
	set<node> v;
	scanf("%d%d%d",&n,&k,&a);
	vis[a]++;
	v.insert(node{a,vis[a]});
	for(int i=1;i<n;i++){
		scanf("%d",&a);
		printf("%d:",a);
		int t = 0;
		for(auto it = v.begin();it != v.end() && t < k;t++,it++)
		    printf(" %d",it->idx);
		puts("");
		//如果重复就删除
		//set重复时，不会添加，所以也不会排序
		auto it = v.find(node{a,vis[a]});
		if(it != v.end())v.erase(it);
	    
		vis[a]++;
		v.insert(node{a,vis[a]});
	}
	/*
	for(auto it = v.begin();it!=v.end();it++)
		    printf("idx = %d %d\n",it->idx,vis[it->idx]);
	*/
	return 0;
} 

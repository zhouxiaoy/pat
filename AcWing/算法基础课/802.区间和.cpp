#include <iostream>
#include <cstdio>
#include <vector> 
#include <algorithm>
using namespace std;

const int N = 3e5+5;
typedef pair<int,int> PII;
vector<int> alls;
vector<PII> query,adds;
int n,m,st[N],num[N];

int find(int x){
	int l = 0,r = alls.size()-1;
	while(l<r){
		int mid = l + r >> 1;
		if(alls[mid]>=x) r = mid;
		else l = mid + 1;
	}
	return l+1; 
}
//unique的实现 
vector<int>::iterator unique(vector<int> &a)
{
    int j = 0;
    for (int i = 0; i < a.size(); i ++ )
        if (!i || a[i] != a[i - 1])
            a[j ++ ] = a[i];
    // a[0] ~ a[j - 1] 所有a中不重复的数

    return a.begin() + j;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int x,c;
		scanf("%d %d",&x,&c);
		adds.push_back({x,c});
		alls.push_back(x);
	} 
	
	for(int i=0;i<m;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		query.push_back({l,r});
		alls.push_back(l),alls.push_back(r);
	}
	
	//去重
	sort(alls.begin(),alls.end());
	alls.erase(unique(alls.begin(),alls.end()),alls.end());
	
	//处理插入 
	for(auto x:adds){
		st[find(x.first)] += x.second;
	}
	
	//预处理前缀和 
	for(int i = 1;i<=alls.size();i++){
		num[i] = num[i-1] + st[i];
	}
	
	for(auto x:query){
		int l = find(x.first),r = find(x.second);
		printf("%d\n",num[r]-num[l-1]);
	}
	return 0;
}

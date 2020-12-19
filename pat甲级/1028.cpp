#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

struct node{
	string Id,name;
	int score;
};

int n,k;

bool cmp(node a,node b){
	if( k == 1)
		return a.Id<b.Id;
	else if( k == 2)
		return (a.name!=b.name)?(a.name<b.name):(a.Id<b.Id);
	else
		return (a.score!=b.score)?(a.score<b.score):(a.Id<b.Id);
}

int main(){
	scanf("%d %d",&n,&k);
	vector<node> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].Id>>v[i].name;
		scanf("%d",&v[i].score);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n;i++){
		cout<<v[i].Id<<' '<<v[i].name;
		printf(" %d\n",v[i].score);
	}
	return 0;
}

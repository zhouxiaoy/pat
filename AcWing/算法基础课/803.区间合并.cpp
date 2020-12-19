#include <iostream>
#include <cstdio> 
#include <algorithm>
using namespace std;

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
	return a.first<b.first;
}

int main(){
	int n;
	scanf("%d",&n);
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		v.push_back({l,r});
	}	
	
	sort(v.begin(),v.end(),cmp);
	
	int l = v[0].first,r = v[0].second,ans = 1;
	for(int i=1;i<v.size();i++){
	    if(v[i].first>r){//不是同一区间
	        ans++;
	        l = v[i].first,r = v[i].second;
	    }else{
	        r = max(r,v[i].second);
	    }
	}
	cout<<ans;
	return 0;
} 

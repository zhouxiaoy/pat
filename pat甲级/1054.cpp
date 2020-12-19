//mapµÄÊ¹ÓÃ 
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;


map<int,int> s;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int a;
			scanf("%d",&a);
			s[a]++;
		}
	}
	
	for(auto it=s.begin();it!=s.end();it++)
		if(it->second >=(n*m+1)/2){
			cout<<it->first;
			break;
		}
	return 0;
} 

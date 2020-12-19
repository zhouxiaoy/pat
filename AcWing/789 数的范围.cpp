#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	vector<int> v(n);
	for(int i=0;i<n;i++)
		scanf("%d",&v[i]);
	
	for(int u = 0;u<k;u++){
		int target;
		scanf("%d",&target);
		
		int l = 0, r = n-1;
		while(l<r){
			int mid = l + r >> 1;
			if(v[mid]>=target) r = mid;
			else l = mid + 1;
		}
		if(v[l]!=target){
			puts("-1 -1");
			continue;
		}
		int start = l;
		r = n-1;
		while(l<r){
			int mid = l + r + 1 >> 1;
			if(v[mid]<=target) l = mid;
			else r = mid -1;
		}
		printf("%d %d\n",start,l);
	}
	return 0;
}

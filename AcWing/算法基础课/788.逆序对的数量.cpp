#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;
const int N = 1e6+10;
int n,st[N],tmp[N];

LL Merge_sort(int begin,int end){
	if(begin == end) return 0;
	int mid = begin + end >> 1;
	LL res = Merge_sort(begin,mid)+Merge_sort(mid+1,end);
	
	int k = 0,i = begin,j = mid + 1;
	while(i<=mid && j<= end){
		if(st[i]<=st[j])tmp[k++] = st[i++];
		else{
			res += mid-i+1;
			tmp[k++] = st[j++];
		}
	} 
	
	while(i<=mid) tmp[k++] = st[i++];
	while(j<=end) tmp[k++] = st[j++];
	
	for(i=begin,j=0;j<k;i++,j++)st[i] = tmp[j];
	return res;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&st[i]);
		
	printf("%lld\n",Merge_sort(0,n-1));
	return 0;
}

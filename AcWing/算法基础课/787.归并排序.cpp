#include <iostream>
#include <cstdio>
using namespace std;

int n;
const int N = 1e6 + 10;
int st[N],tmp[N];

void Merge_sort(int begin,int end){
	if(begin == end) return;
	int mid = begin+end>>1;
	Merge_sort(begin,mid),Merge_sort(mid+1,end);
	
	int k=0,i=begin,j=mid+1;
	while(i<=mid&&j<=end){
		if(st[i]<=st[j])tmp[k++]=st[i++];
		else tmp[k++]=st[j++];
	}
	while(i<=mid)tmp[k++]=st[i++];
	while(j<=end)tmp[k++]=st[j++];
	
	for(i=begin,j=0;j<k;i++,j++)st[i]=tmp[j];
}

int main(){
	scanf("%d",&n);
	for(register int i=0;i<n;i++)
		scanf("%d",&st[i]);
	Merge_sort(0,n-1);
	for(register int i = 0;i<n;i++)
		printf("%d ",st[i]);
	return 0;
}

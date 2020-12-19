#include <iostream>
#include <cstdio>
using namespace std; 

int n,k;
const int N = 100005;
int st[N];

int Q_sort(int begin,int end,int search){
	if(begin==end)return st[begin];
	int l = begin -1, r = end + 1,mid = st[begin+end>>1];
	while(l<r){
		while(st[++l]<mid);
		while(st[--r]>mid);
		if(l<r)swap(st[l],st[r]);
	}
	if(r-begin+1>=search)//×ó±ßÐ¡ÓÚk
		Q_sort(begin,r,search);
	else
	 	Q_sort(r+1,end,search-(r-begin+1));
}

int main(){
	scanf("%d %d",&n,&k);
	for(register int i=0;i<n;i++){
		scanf("%d",&st[i]);
	}
	
	printf("%d",Q_sort(0,n-1,k));
	
	return 0;
}

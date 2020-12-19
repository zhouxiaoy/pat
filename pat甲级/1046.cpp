#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[200010];
int b[200010];//存储从1-i的路径之和 
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i] = a[i] + b[i-1];
	}
	for(int i=n+1;i<=2*n;i++){
		a[i]=a[i-n];//将环变成两个相同的数组相连，可模拟所有情况 
		b[i] = a[i] + b[i-1];
	}
	int m,x,y;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&x,&y);
		if(y<x)y+=n;
		int t = b[y-1]-b[x-1];//从右走的路径值 
		printf("%d\n",min(b[n]-t,t));//因为从左走和从右走之和是固定的，只要判断那边的小就行 
	} 
	return 0;
} 

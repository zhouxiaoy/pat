#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e5+5;
int sum[N];

int main(){
	int n,m,c;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
	}
	
	for(int i=0;i<m;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%d\n",sum[r]-sum[l-1]);
	}
	return 0;
}

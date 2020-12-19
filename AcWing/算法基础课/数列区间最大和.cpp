#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e5+10;
struct Node{
	int l,r;
	int maxn;
}tr[4*N];
int n,m,w[N];

void build(int u,int l,int r){
	if(l == r) 
		tr[u].l = l,tr[u].r = r,tr[u].maxn=w[l];
	else{
		int mid = l + r >> 1;
		//tr[u] = {l,r};≤ªø…”√ 
		tr[u].l = l,tr[u].r = r;
		build(u<<1,l,mid);
		build(u<<1|1,mid+1,r);
		tr[u].maxn = max(tr[u<<1].maxn,tr[u<<1|1].maxn);
	}
}

int query(int u,int l,int r){
	if(tr[u].l>=l && tr[u].r<=r) return tr[u].maxn;
	int maxn = 0;
	int mid = tr[u].l + tr[u].r >> 1;
	if(l<=mid) maxn = query(u<<1,l,r);
	if(mid<r) maxn = max(query(u<<1|1,l,r),maxn);
	return maxn;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	build(1,1,n);
	
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",query(1,a,b));
	}
	
	return 0;
} 

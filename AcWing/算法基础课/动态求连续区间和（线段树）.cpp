#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e5+10;
struct Node{
	int l,r;
	int sum;
}tr[N*4];
int n,m,w[N];

void pushup(int u){
	tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
}

void build(int u,int l,int r){
	if(l == r)tr[u] = {l,r,w[r]};
	else{
		int mid = l + r >> 1;
		tr[u] = {l,r};
		build(u<<1,l,mid),build(u<<1|1,mid+1,r);
		pushup(u);
	}
}

int query(int u,int l,int r){
	if(tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
	else{
		int sum = 0;
		int mid = tr[u].l + tr[u].r >>1;
		if(l<=mid) sum = query(u<<1,l,r);
		if(mid<r) sum += query(u<<1|1,l,r);
		return sum;
	} 
}

int modify(int u,int k,int x){
	if(tr[u].l == tr[u].r) tr[u].sum += x; 
	else{
		int mid = tr[u].l + tr[u].r >> 1;
		if(k<= mid) modify(u<<1,k,x);
		else modify(u<<1|1,k,x);
		pushup(u);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	build(1,1,n);	
	
	while(m--){
		int k,a,b;
		scanf("%d%d%d",&k,&a,&b);
		if(k == 1){
			modify(1,a,b);
		}else{
			printf("%d\n",query(1,a,b));
		}
	}
	return 0;
}  

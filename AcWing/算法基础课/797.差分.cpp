#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5+5;
int st[N];

void insert(int l,int r,int x){
	st[l] += x;
	st[r+1] -= x;
}

int main(){
	int n,m,num,l,r;
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		insert(i,i,num);
	}
	
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&l,&r,&num);
		insert(l,r,num);
	}
	
	
	for(int i=1;i<=n;i++){
		st[i]+=st[i-1];
		printf("%d ",st[i]);
	}
	return 0;
}

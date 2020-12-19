#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e5+10;
int p[N],ans[N];

int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		p[i] = i;
		ans[i] = 1;
	}
	
	for(int i=0;i<m;i++){
		char op[10];
		int a,b;
		scanf("%s",op);
		if(op[0] == 'C'){
			scanf("%d%d",&a,&b);
			a = find(a), b = find(b);
			if(a == b) continue;//如果a,b在同一个连通块,则不操作 
			p[a] = b;//将a集合并入b集合
			ans[b] += ans[a]; //b集合数量+=a集合数量（使用根节点来表示连通块的数量） 
		}else if(op[1] == '1'){
			scanf("%d%d",&a,&b);
			if(find(a) == find(b)) puts("Yes");
			else puts("No");
		}else{
			scanf("%d",&a);
			printf("%d\n",ans[find(a)]);
		}
	}
	return 0;
} 

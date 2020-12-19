#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1005;
int st[N][N];

void insert(int x1,int y1,int x2,int y2,int x){
	st[x1][y1] += x;
    st[x2 + 1][y1] -= x;
    st[x1][y2 + 1] -= x;
    st[x2 + 1][y2 + 1] += x;
}

int main(){
	int n,m,q,c;
	scanf("%d %d %d",&n,&m,&q);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&c);
			insert(i,j,i,j,c);
		}
	}
	
	for(int i=0;i<q;i++){
		int x1,x2,y1,y2;
		scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&c);
		insert(x1,y1,x2,y2,c);
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			st[i][j] += st[i][j-1] + st[i-1][j] - st[i-1][j-1];
			printf("%d ",st[i][j]);
		}
		puts("");
	}
	return 0;
} 

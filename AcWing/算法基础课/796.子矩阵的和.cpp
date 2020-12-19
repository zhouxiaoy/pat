#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e4+5;
int sum[N][N];

int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&sum[i][j]);
			sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}


	for(int i=0;i<k;i++){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		printf("%d\n",sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1] + sum[x1-1][y1-1]);
	}
	return 0;
}

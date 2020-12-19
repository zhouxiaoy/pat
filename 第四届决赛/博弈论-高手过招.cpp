#include  <iostream>
#include <cstdio>
#include <cstring>
#define N 27 
using namespace std;
int T,n;
bool vis[N];
int main(){
	scanf("%d",&T);
	while(T--){
		int ans =0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int now = 0,num;
			memset(vis,0,sizeof(vis));
			scanf("%d",&num);
			for(int j=1;j<=num;j++){
				int in;
				scanf("%d",&in);
				vis[in]=1;
			}
			int cnt=0,tot=0;
			for(int j=20;j>=0;j--){
				if(!vis[j]){
					if(tot){
						ans^=tot;
						tot=0;
					}
					cnt^=1;
				}else{
					if(cnt)
						++tot;
				}
			}
			if(tot)
			ans^=tot;
		}
		printf("%s\n",ans?"Yes":"No");
	}
	return 0;
} 

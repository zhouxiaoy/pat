#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int e[205][205];


int main(){
	int n,m,k;
	scanf("%d%d",&n,&m);
	int a,b;
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		e[a][b] = e[b][a] = 1;
	}
	
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int t;
		scanf("%d",&t);
		vector<int> v(t);
		int vis[205]={0};
		for(int j=0;j<t;j++){
			scanf("%d",&v[j]);
			vis[v[j]] = 1;
		}
		int flag = 1;//maximal clique
		for(int j=0;j<t;j++){
			for(int z=j+1;z<t;z++){
				if(e[v[j]][v[z]] == 0){
					flag = -1;//not a Clique
				    puts("Not a Clique");
                    break;
                }
			} 
			if(flag == -1)break;
		}
		if(flag == -1)continue;
        
		for(int j=1;j<=n;j++){
    		if(vis[j] == 0){
                for(int z = 0;z<t;z++){
                    if(e[j][v[z]] == 0)break;
                    if(z == t - 1) flag = 0;
                }
		    }
		    if(flag == 0){
		        puts("Not Maximal");
		        break;
		    }
	    }
        if(flag == 1)puts("Yes");
	}
	return 0;
}

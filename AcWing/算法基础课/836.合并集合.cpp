#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e5+10;
int hp[N];

int find(int x){
	if(x != hp[x]) hp[x] = find(hp[x]);
	return hp[x];
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i ++ ) hp[i] = i;
	
	for(int i=0;i<m;i++){
	    char op[2];
		int a,b;
		scanf("%s%d%d",op,&a,&b);
		if(op[0] == 'M'){
			hp[find(a)] = find(b);
		}else{
			if(find(a) == find(b)) puts("Yes");
			else puts("No");
		}
	} 
	return 0;
} 

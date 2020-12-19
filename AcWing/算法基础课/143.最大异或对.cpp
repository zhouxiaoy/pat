#include <iostream>
#include <cstdio> 
using namespace std;

const int N = 100010, M = 3000000;//M的大小要注意 
int Trie[M][2], idx, num[N];


void insert(int x){
	int p = 0;
	for(int i=30;i>=0;i--){
		int t = x >> i & 1;
		if(!Trie[p][t])
			Trie[p][t] = ++idx;
		p = Trie[p][t];
	}
}

int find(int x){
	int ans = 0, p = 0;
	for(int i=30;i>=0;i--){
		int t = x>> i & 1;
		ans *= 2;
		if(Trie[p][!t])
			p = Trie[p][!t],ans  += 1;
		else
			p = Trie[p][t];
	}
	return ans;
}

int main(){
	int n, maxx = 0; 
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		insert(num[i]);
	}
	
	for(int i=0;i<n;i++){
		maxx = max(maxx,find(num[i]));
	}
	
	printf("%d\n",maxx);
	return 0;
} 

#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100010;
int cnt[N],Trie[N][26],idx;//idx������������Ľ���ַ
// idx = 0 ����ͷ���Ҳ�ǿս�㣨�����ڣ� 
 
void insert(char str[]){
	int p = 0;
	for(int i=0; str[i]; i++){
		int u = str[i]-'a';
		if(!Trie[p][u]) Trie[p][u] = ++idx;
		p = Trie[p][u];
	}
	cnt[p]++;
}

int query(char str[]){
	int p = 0;
	for(int i=0; str[i]; i++){
		int u = str[i] - 'a';
		if(!Trie[p][u]) return 0;
		p = Trie[p][u];
	}
	return cnt[p];
}

int main(){
	int n;
	scanf("%d",&n);
	char op[2],str[N];
	while(n--){
		scanf("%s%s",op,str);
		if(op[0] == 'I') insert(str);
		else printf("%d\n",query(str));
	}
	return 0;
} 

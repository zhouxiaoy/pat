#include <iostream>
#include <cstdio>

using namespace std;
struct node{
	bool vis;
	int next;
};
node e[100000];
int main(){
	int begin,end,n;
	cin>>begin>>end>>n;
	for(int i=0;i<n;i++){
		int a,b;
		char data;
		scanf("%d %c %d", &a, &data, &b);
		e[a] = {false ,b};
	}

	for(int i=begin;i!=-1;i=e[i].next)
		e[i].vis=true;
	for(int i=end;i!=-1;i=e[i].next){
		if(e[i].vis==true){
			printf("%05d",i);
			return 0;
		}
	}
	puts("-1");
	return 0;
} 
//自己的有bug 不知道为什么错 
/* 
#include <iostream>
#include <cstdio>
using namespace std;

int e[100000], t[100000];
int main() {
	fill(t, t + 100000, -1);
	int n, a, b, flag = -1;
	char c;
	cin >> a >> b >> n;

	for (int i = 0; i < n; i++) {
		int j,k;
		cin >> j >> c >> k;
		t[j] = k;
		if (k != -1)
			e[k]++;
	}
	while (flag == -1) {
		int flag1 = -1, flag2 = -1;
		while (flag1 == -1 && t[a] != -1) {
			if (e[a] > 1)
				flag1 = a;
			a = t[a];
		}
		while (flag2 == -1 && t[b] != -1) {
			if (e[b] > 1)
				flag2 = b;
			b = t[b];
		}
		if (flag1 == -1 || flag2 == -1)
			break;

		if (flag1 == flag2) {
			flag = flag1;
		}
	}
	if (flag != -1)
		printf("%05d", flag);
	else
		puts("-1");
	return 0;
}
*/ 

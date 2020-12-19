#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e5+10;
int heap[N],cnt = 0;

void down(int x){
	int t = x;//表示最小值的下标
	if(x*2<=cnt && heap[x*2]<heap[t]) t = x*2;//最小值和左结点比较 
	if(x*2+1<=cnt && heap[x*2+1]<heap[t]) t = x*2+1;//和右节点比较 
	if(t != x){
		swap(heap[t],heap[x]);
		down(t);
	}
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m); 
	for(int i=0;i<n;i++)
		scanf("%d",&heap[++cnt]);
	
	for(int i=n/2;i;i--)  down(i);
		
	while(m--){
		printf("%d ",heap[1]);
		heap[1] = heap[cnt--];
		down(1);
	}
	
	return 0;
} 

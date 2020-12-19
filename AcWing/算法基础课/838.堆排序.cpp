#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e5+10;
int heap[N],cnt = 0;

void down(int x){
	int t = x;//��ʾ��Сֵ���±�
	if(x*2<=cnt && heap[x*2]<heap[t]) t = x*2;//��Сֵ������Ƚ� 
	if(x*2+1<=cnt && heap[x*2+1]<heap[t]) t = x*2+1;//���ҽڵ�Ƚ� 
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

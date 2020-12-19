#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e6+5; 
int n,k,st[N],q[N];

int main(){
	scanf("%d %d",&n,&k);
	for(register int i = 0;i<n;i++)
		scanf("%d",&st[i]); 
	
	int hh = 0, tt = -1;//队列头指针和尾指针 
	for(register int i = 0;i<n;i++){
		//如果当前队列不为空 并且当前的队列已满k个
		//删去队头元素 
		if(hh<=tt && i-k+1>q[hh]) hh++; 
		while(hh<=tt && st[q[tt]]>=st[i])tt--;
		q[++tt] = i;
		if(i>=k-1) printf("%d ",st[q[hh]]); 
	}
	puts("");
	
	hh = 0, tt = -1;//队列头指针和尾指针 
	for(register int i = 0;i<n;i++){
		//如果当前队列不为空 并且当前的队列已满k个
		//删去队头元素 
		if(hh<=tt && i-k+1>q[hh]) hh++; 
		while(hh<=tt && st[q[tt]]<=st[i])tt--;
		q[++tt] = i;
		if(i>=k-1) printf("%d ",st[q[hh]]); 
	}
	puts("");
	
	return 0;
} 

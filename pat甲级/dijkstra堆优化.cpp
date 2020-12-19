#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1010,M = 2010,C = 1010;

int n,m;
int h[N],e[M],ne[M],idx;
int price[N];
int dist[N][C];
bool st[N][C];

struct Ver{
	int d,c,u;
	bool operator< (const Ver &W)const{
		return d > W.d;
	}
};

void add(int a, int b,int c){
	e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

int dijkstra(int c,int start,int end){
	priority_queue<Ver>heap;
	memset(dist,0x3f,sizeof dist);
	memset(st,false,sizeof st);
	heap.push({0,start,0});
	
	while(heap.size()){
		auto t = heap.top();
		heap.pop();
		
		if(t.u == end) return t.d;
		if(st[t.u][t.c])continue;
		st[t.u][t.c] = true;
		
		if(t.c<c){
			if(dist[t.u][t.c+1]>t.d+price[t.u]){
				dist[t.u][t.c+1] = t.d+ price[t.u];
				heap.push({dist[t.u][t.c+1],t.u,t.c+1}); 
			}
		}
		
		for(int i=h[t.u];~i;i=ne[i]){
			int j = e[i];
			if(t.c>=w[i]){
				if(dist[j][t.c-w[i]]>t.d){
					dist[j][t.c-w[i]] = t.d;
					heap.push({t.d,j,t.c-w[i]});
				}
			}
		}
	}
	return -1;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&price[i]);
	memset(h,-1,sizeof h);
	
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c),add(b,a,c);	
	}
	
	int query;
	
	while(query--){
		int c,s,e;
		scanf("%d%d%d",&c,&s,&e);
		int k = dijkstra(c,s,e);
		if(t == -1)puts("impossible");
		else printf("%d\n",t);
	}
	return 0;
} 

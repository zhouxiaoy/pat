#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e5+10;
//heap是最小堆 ，hp是插入的第k个数在堆中对应的下标，ph堆中的下标对应在堆中的那个元素 
int heap[N],ans,hp[N],ph[N];
int m;

void heap_swap(int a,int b){
	swap(ph[hp[a]],ph[hp[b]]);
	swap(hp[a],hp[b]);
	swap(heap[a],heap[b]); 
} 

void down(int x){
	int t = x;
	if(x*2 <= ans && heap[x*2]<heap[t]) t = x*2;
	if(x*2+1 <= ans && heap[x*2+1]<heap[t]) t = x*2 + 1;
	if(x != t){
		heap_swap(x,t);
		down(t);
	}
}

void up(int x){
	while(x/2 && heap[x/2]>heap[x]){
		heap_swap(x,x/2);
		x >>= 1;
	}
}

//在堆中插入一个数 
void insert(int x){
	ans++;
	m++;
	heap[ans] = x;
	ph[m] = ans;
	hp[ans] = m;
	up(ans);
}

//显示堆顶元素 
int show_head(){
	return heap[1];
}

//删除堆顶元素
void del_head(){
	heap_swap(1,ans);
	ans--;
	down(1);
	
}

//删除堆中第k个插入的数 
void del_k_node(int k){
	k = ph[k];
	heap_swap(ans,k);//不能用ph[k]代替 
	ans--;
	up(k);		//因为heap_swap之后，ph[k]里的值发生了变化 
	down(k);
}
 
//修改第k个插入的数，将其变为x
void modify_k_node(int k,int x){
	heap[ph[k]] = x;
	up(ph[k]),down(ph[k]);
}
 

int main(){
	int n;
	scanf("%d",&n);
	
	while(n--){
		char op[10];
		int a ,b;
		scanf("%s",op);
		if(!strcmp(op, "I")){
			scanf("%d" ,&a);
			insert(a);
		}else if(!strcmp(op, "PM")){
			printf("%d\n",show_head());
		}else if(!strcmp(op, "DM"))
				del_head();
		else if(!strcmp(op, "D")){
				scanf("%d",&a);
				del_k_node(a);
		}
		else {
			scanf("%d %d",&a,&b);
			modify_k_node(a,b);
		}
	}
	return 0;
} 

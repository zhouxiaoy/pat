#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e5+10;
//heap����С�� ��hp�ǲ���ĵ�k�����ڶ��ж�Ӧ���±꣬ph���е��±��Ӧ�ڶ��е��Ǹ�Ԫ�� 
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

//�ڶ��в���һ���� 
void insert(int x){
	ans++;
	m++;
	heap[ans] = x;
	ph[m] = ans;
	hp[ans] = m;
	up(ans);
}

//��ʾ�Ѷ�Ԫ�� 
int show_head(){
	return heap[1];
}

//ɾ���Ѷ�Ԫ��
void del_head(){
	heap_swap(1,ans);
	ans--;
	down(1);
	
}

//ɾ�����е�k��������� 
void del_k_node(int k){
	k = ph[k];
	heap_swap(ans,k);//������ph[k]���� 
	ans--;
	up(k);		//��Ϊheap_swap֮��ph[k]���ֵ�����˱仯 
	down(k);
}
 
//�޸ĵ�k����������������Ϊx
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

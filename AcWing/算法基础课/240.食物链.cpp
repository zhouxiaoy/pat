#include <iostream>
#include <cstdio>

using namespace std;
const int N = 50010;
int p[N];

int main(){
	int k,n,ans = 0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(b>n || c>n){
			ans++;
		}else{
			if(a == 1){//��b��c֮ǰ�ǻ�ʳ��ϵ��ans++ 
				if(p[b] == c || p[c] == b)ans++;
				else{ //b c�ȼۺ��ϵ�ı� 
					
				}
			}
		}
	} 
	return 0;
} 


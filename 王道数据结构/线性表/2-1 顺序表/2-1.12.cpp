#include <iostream>
#include <cstdio>
using namespace std;

int n;
int num[1000];
//2-1.12 
//错误 这个前提时 主元素大于50%时
//例 2 2 3 3 4 4 4 5 5就不行
 /* 
int findE(){
	int times = 0,idx;//times表示主元素的个数，idx表示主元素的下标 
	for(int i=0;i<n;i++){
		if(times == 0){
			idx = i;
			times = 1;
		}else if(num[idx] == num[i]){//如果当前元素与idx相同 
			times++; 
		}
		else{
			time--;//如果与idx不同，则主元素个数减一 
		}
	}
	if(times > 0)//说明主元素> 50% 
		return idx;
	else 
		return -1;
}
*/ 
//上面的优化，只要times最后大于0就可能时主元素，反之，就没有主元素
//再验证idx是否为主元素 
int findE(){
	int times = 0,idx;//times表示主元素的个数，idx表示主元素的下标 
	for(int i=0;i<n;i++){
		if(times == 0){
			idx = i;
			times = 1;
		}else if(num[idx] == num[i]){//如果当前元素与idx相同 
			times++; 
		}
		else{
			times--;//如果与idx不同，则主元素个数减一 
		}
	}
	if(times > 0){//说明主元素> 50%
	times = 0; 	
		for(int i=0;i<n;i++){
			if(num[idx] == num[i])times++;	
		}
	}
	if(times > n/2) return idx;
	else return -1;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	} 
	int t = findE();
	if(t!=-1)
		printf("主元素为:%d\n",num[t]);
	else
		puts("没有主元素");
	return 0;
}

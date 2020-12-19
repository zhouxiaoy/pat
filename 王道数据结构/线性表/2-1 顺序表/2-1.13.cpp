#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
using namespace std;

int n;
int num[1000];
//2-1.13  
// 错误 例如 1 3 5  得到的应该时2，但是我这个算法什么都得不到 
/* 
int find_pos_Min(){
	int minn = LIN_MAX,maxx = LIN_MIN;
	for(int i=0;i<n;i++){
		if(num[i]>0 && minn>num[i])
			minn = num[i];
		if(num[i]>maxx)
			maxx = num[i];
	}
	if(minn-1>0)
		return minn -1;
	else
				
} 
*/
int find_pos_Min(){
	 vector<int> v(n+2,0);
	 for(int i=0;i<n;i++){
	 	if(num[i] <=0 || num[i] >n+1)continue;
	 	else{
	 		v[num[i]] = 1;
	 	}
	 }
	 
	 for(int i=1;i<=n+1;i++){
	 	if(v[i] == 0) return i;
	 }
} 

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	} 
	
	printf("最小未出现正整数为:%d\n",find_pos_Min());
	
	return 0;
}

#include <iostream>
#include <algorithm>
#include <cstdio> 
using namespace std;

int n,m;
int mp[205];
int num[10005],dp[10005];//����i֮ǰ���������
 

int main(){
	scanf("%d", &n);//��ȡ��Ŀ�г���������ɫ�ĸ������ò��� 
	scanf("%d", &n);
	int maxx = -1;
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d", &a);
		mp[a] = i;
	}
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		scanf("%d", &num[i]);
		if(mp[num[i]]){//i������ɫ������ϲ����ɫ������ 
			dp[i]=1;
			for(int j=0;j<i;j++){
				if(mp[num[i]]==0)continue;//j������ɫ������ϲ����ɫ������
				// i��ɫ��ϲ��˳����ڵ���j
				if(mp[num[i]]>=mp[num[j]])
					dp[i]= max(dp[i],dp[j]+1);
			}
		}
		//max���ٶȻ��if����
		maxx = max(maxx,dp[i]);
	}
	printf("%d", maxx);
	return 0;
} 

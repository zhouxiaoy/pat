#include <iostream>
#include <stack>
#include <cstdio> 
using namespace std;
int a[1005];
int main(){
	int n,m,k;
	scanf("%d%d%d",&m,&n,&k);
	for(int i=0;i<k;i++){
		stack<int> s;
		for(int j=1;j<=n;j++)scanf("%d",&a[j]);
		int x = 1,y = 1;
		//1-n һ��һ���� 
		while(x<=a[y]) {
			if(s.size()<m)//����С��m����ʾ�пռ� 
				s.push(x);//��ջ
			//����ĺ�ջ��Ԫ����ͬ����ջ��ֱ����ͬ 
			while(s.size() && a[y] == s.top()){
				s.pop();y++;
			}
			x++;
		}
		//��x == n+1 ʱ��ջΪ�վ�ƥ������ 
		if(x == n+1 && s.size() == 0)
			puts("YES");
		else puts("NO");
	}
	return 0;
} 

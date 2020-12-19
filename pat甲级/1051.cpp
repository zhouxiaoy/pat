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
		//1-n 一个一个进 
		while(x<=a[y]) {
			if(s.size()<m)//个数小于m，表示有空间 
				s.push(x);//入栈
			//输出的和栈顶元素相同，出栈，直到不同 
			while(s.size() && a[y] == s.top()){
				s.pop();y++;
			}
			x++;
		}
		//当x == n+1 时，栈为空就匹配上了 
		if(x == n+1 && s.size() == 0)
			puts("YES");
		else puts("NO");
	}
	return 0;
} 

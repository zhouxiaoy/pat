#include <iostream>
#include <cmath>
#include <cstdio>
#include <memory.h>

using namespace std;
const int maxn=30;
int n,flag[maxn];//记录字母所代表的数字 
char s[4][maxn];
bool use[maxn];//记录数字是否被使用 
int id(char ch){
	return ch-'A'+1;
} 
//x代表列，y代表行，t代表进位 
void dfs(int x,int y,int t){
	if(x==0){//从上到小，从右到左，x==0 表示搜索到了最后一行 
		if(t==0)//最后一列不能有进位（没有进位代表满足条件）
		{
			//打印 
			for(int i=1;i<n;i++){
				printf("%d ",flag[i]);
			}
			printf("%d\n",flag[n]);
		}
		return;
	}
	//减枝 
	for(int i=x-1;i>=1;i--){
		int w1 = flag[id(s[1][i])];//w1代表第一行字符串代表的数字
		int w2 = flag[id(s[2][i])];//w2是第二行
		int w3 = flag[id(s[3][i])];//w3是第三行
		if(w1==-1||w2==-1||w3==-1){
			continue;
		}
		if((w1+w2)%n!=w3&&(w1+w2+1)%n!=w3){
			return;//如果无法整除，则代表（分配的）算式是错的 
		}
	}
	//如果这个位置上还没被赋值，就进行赋值
	if(flag[id(s[y][x])] == -1){
		for(int i=n-1;i>=0;i--){
			if(!use[i]){//如果这个数字未被使用 
				if(y!=3){//且不是最后一行 
					flag[id(s[y][x])]=i;//就将这个位置附上值
					use[i] = 1;//标记这个数字被用过 
					dfs(x,y+1,t);//继续搜索下一行 
					//回溯 
					flag[id(s[y][x])] = -1;
					use[i]=0; 
				}else{//当y==3时 
					int w = flag[id(s[1][x])] + flag[id(s[2][x])] + t;//求两个数字与进位之和
					if(w%n!=i)
						continue;//不等则跳过寻找下一个数字 
					//找到这个数 （进行 赋值，标记） 
					use[i] = 1;flag[id(s[3][x])] = i;
					dfs(x-1,1,w/n);//搜索下一项，进位改变
					use[i]=0;flag[id(s[3][x])] = -1;//回溯 
				}
			}
		}
	}else{//如果这个位置已经被赋值
		if(y!=3)
			dfs(x,y+1,t); 
		else{
			int w=flag[id(s[1][x])] + flag[id(s[2][x])] + t;
			if(w%n!=flag[id(s[3][x])])
				return;
			dfs(x-1,1,w/n);//搜索下一列 ，进位需要改变 
		}
	} 
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=3;i++){
		scanf("%s",s[i]+1);
	} 
	memset(flag,-1,sizeof(flag));
	dfs(n,1,0);
	return 0;
}

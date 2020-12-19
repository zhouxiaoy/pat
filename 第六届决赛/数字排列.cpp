#include <iostream>
using namespace std;
int num[15]={0,7,4,0,0,0,0,4,0,7,0,0,0,0,0};
bool vis[7];
void dfs(int k)//代表现在填入的数字
{
	//如果是7的话就打印 
	if(k==7){
		for(int i=1;i<=14;i++){
			cout<<num[i];
		} 
		cout<<endl;
		return;
	}
	//if(k==4)dfs(k+1); 
	if(vis[k]==true){
		dfs(k+1);
		return;//要记得return; 
	} 

	for(int i=3;i<=14;i++){
		//if(i==7)continue;
		int next=k+i+1;
		if(next<=14){
			if(num[i]==0&&num[next]==0){
				num[i]=num[next]=k;
				vis[k]=true;
				dfs(k+1);
				num[i]=num[next]=0;
				vis[k]=false;
			}
		}
	}
}
//方法二：代表填入的位置
void dfs1(int k){
	if(num[k]){
		dfs1(k+1);
		return;
	}
	if(k==15){
		for (int i = 1; i <= 14; i++) {
			cout << num[i];
		}
		cout << endl;
		return;
	}
	
	for(int i=1;i<7;i++){
		if(i==4||vis[i])
			continue;
		int next=k+i+1;
		if(next<=14){
			if(num[k]==0&&num[next]==0){
				num[k]=num[next]=i;
				vis[i]=true;
				dfs1(k+1);
				num[k]=num[next]=0;
				vis[i]=false;
			}
		}
	}
} 
int main(){
	vis[4]=vis[7]=true;
	dfs1(3);
	return 0;
}

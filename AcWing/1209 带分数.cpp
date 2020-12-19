/*
	要知道什么时候使用return结束dfs ，这一题就不需要在找到后return 
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;
const int N = 10;
int n,ans = 0;
bool st[N],backup[N];

bool check(int a,int c){
	LL b = (n-a)*(LL)c;
	if(!a||!b||!c)return false;//if(!a||!b||!c)的反义不是if(a && b && c)么 
	memcpy(backup,st,sizeof st);

	while(b){
		int idx = b%10;
		b/=10;
		if(!idx || backup[idx])return false;
		else backup[idx]=true;
	}
	
	for(int i=1;i<10;i++)
		if(!backup[i])
			return false;
	
	return true;
}

void dfs_c(int a,int c){
	if(c)
		if(check(a,c)){ 
			cout<<a<<' '<<(n-a)*(LL)c<<' '<<c<<endl; 
			ans++;
			} 
	
	for(int i=1;i<10;i++){
		if(!st[i]){
			st[i]=true;
			dfs_c(a,c*10+i);
			st[i]=false;
		}
	}
}

void dfs_a(int a){
	if(a>=n)return;
	if(a) dfs_c(a,0);
	
	for(int i=1;i<10;i++){
		if(!st[i]){
			st[i]=true;
			dfs_a(a*10+i);
			st[i]=false;
		}
	}
}

int main(){
	cin>>n;
	dfs_a(0);
	cout<<ans<<endl;
	return 0;
} 


//错误 
/*
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
bool vis[10],backup[10];
int n,ans=0;

bool check(int b){
	while(b){
		if(!(b%10) || backup[b%10])
			return false;
		backup[b%10] = true;
		b = b/10;
	}
	
	for(int i=1;i<10;i++)
		if(!backup[i])
			return false;
	return true;
}

void find_c(int a,int c){
	long long b = (n-a)*(long long)c;
	if(a!=0 && b!=0 && c!=0){
		memcpy(backup,vis,sizeof vis);
		if(check(b)){
			ans++;
		    //cout<<a<<' '<<b<<' '<<c;
		}
	}
	
	for(int i=1;i<=9;i++){
		if(!vis[i]){
			vis[i]=true;
			find_c(a,c*10+i);
			vis[i]=false;
		}
	}
}

void find_a(int a){
	if(a>=n)return;
	if(a) find_c(a,0);

	for(int i=1;i<=9;i++){
		if(!vis[i]){
			vis[i]=true;
			find_a(a*10+i);
			vis[i]=false;
		}
	}
}

int main(){
	cin>>n;
	find_a(0);
	cout<<ans<<endl;
	return 0;
} 
*/ 


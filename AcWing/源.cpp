#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
bool vis[10],backup[10];
int n,ans=0;
/*
* n = a + b/c
* n*c = a*c + b
*/

bool check(int b){
	while(b){
		if(b%10==0 || backup[b%10] == true)
			return false;
		backup[b%10] = true;
		b = b/10;
	}
	
	for(int i=1;i<10;i++)
		if(backup[i] == false)
			return false;
	return true;
}

void find_c(int a,int c){
	long long b = (n-a)*(long long)c;
	if(a>0 && b>0 && c>0){
		memcpy(backup,vis,sizeof vis);
		if(check(b)){
			ans++;
		}
	}
	
	for(int i=1;i<=9;i++){
		if(vis[i] == false){
			vis[i]=true;
			find_c(a,c*10+i);
			vis[i]=false;
		}
	}
}

void find_a(int a){
	if(a>=n)return;
	if(a)
		find_c(a,0);

	for(int i=1;i<=9;i++){
		if(vis[i]==false){
			vis[i]=true;
			find_a(a*10+i);
			vis[i]=false;
		}
	}
}

int main(){
	scanf("%d",&n);
	find_a(0);
	cout<<ans<<endl;
	return 0;
} 

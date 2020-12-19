#include <iostream>
using namespace std;
int n;
long long tree[100005];
int a[100005];
int lowbit(int x){
	return x&(-x);
}

void modify(int idx,int val){
	for(int i=idx;i<=n;i+=lowbit(i)){
		tree[i]+=val;
	}
}

long long get(int idx){
	long long ans=0;
	for(int i=n;i>=idx;i-=lowbit(i)){
		ans+=a[i];
	}
}

int main(){
	
	int ans=0,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		modify(i,tree[i]);
		if(a[i]%k==0&&a[i]/k!=0){
			ans++;
		}
	}
	int temp=0;
	for(int i=1;i<=n-1;i++){
		temp=1;
		for(int j=i+temp;j<=n;j++){
			int val;
			if(i==0)
				val=get(j);
			else
				val=get(j)-get(i-1);
			if(val%k==0&&val/k!=0){
				ans++;
			}
		}
	}
	cout<<ans; 
	return 0;
} 

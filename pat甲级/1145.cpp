#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

bool isPrime(int n){
	if(n<2)return false;
	for(int i=2;i*i<=n;i++){
		if(n%i == 0)return false;
	}
	return true;
}

int main(){
	int msize,n,m,v;
	cin>>msize>>n>>m;
	vector<int> a(msize,0),b(msize,0);
	while(!isPrime(msize))msize++;
	
	for(int i=0;i<n;i++){
		cin>>v;
		int flag = 1,t;
		t = v%msize;
		for(int j=0;j*j+t<msize;j++){
			if(a[t+j*j]==0){
				a[t+j*j]=v;
				flag == 0;
			}
		}
		if(flag==1)
			printf("%d cannot be inserted.\n",v);
	}
	
	int ans=0;
	for(int i=0;i<m;i++){
		cin>>v;
		int t = v%msize;
		for(int j=0;j*j+t<msize;j++){
			ans++;
			if(a[t+j*j]==v||a[t+j*j]==0)
				break;
		}
	}
	printf("%.1f",ans*1.0/m);
	return 0;
}

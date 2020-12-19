#include <iostream>
#include <cstdio>

using namespace std;
int main(){
	int k;
	double a[1005]={0};
	int vis[1005]={0};
	for(int i=0;i<2;i++){
		cin>>k;
		int idx;
		double b;
		for(int j=0;j<k;j++){
			cin>>idx>>b;
			a[idx]+=b;
		}
	}
	int sum=0;
	for(int i=0;i<1001;i++){
		if(a[i]!=0.0)
		 	sum++;
	}
	printf("%d",sum);
	for(int i=1000;i>=0;i--){
		if(a[i]!=0.0){
			printf(" %d %.1f",i,a[i]);
		}
	}
	return 0;
} 

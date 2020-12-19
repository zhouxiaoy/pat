#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int a,m,n,ans=0;
	double b,arr[1001]={0.0},arr2[2001]={0.0};
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d %lf",&a,&b);
		arr[a]=b;
	}
	
	cin>>m;
	for(int i=0;i<m;i++){
		scanf("%d %lf",&a,&b);
		for(int j=0;j<=1000;j++)
				arr2[j+a]+=b*arr[j];
	}
	/*
	for(int i=0;i<m;i++){
		scanf("%d %lf",&a,&b);
		for(int j=0;j<=1000;j++)
                if(arr[j]!=0.0){s
                    ans++;
				    if(arr2[a+j]!=0.0)
                        ans--;          //在这里面判断会出现 之前是a 后面加上-a之后为0的可能
                    arr2[j+a]+=b*arr[j];
                }
	}
	*/	
	for(int i=2000;i>=0;i--)
		if(arr2[i]!=0.0) ans++;
	cout<<ans;	
	
	for(int i=2000;i>=0;i--){
		if(arr2[i]!=0.0)
		 printf(" %d %.1f",i,arr2[i]);
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int ans=0;
	long long a[505][505];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			scanf("%d",&a[i][j]);
			a[j][i]=a[i][j];
		}
		sort(a[i]+1,a[i]+n+1); 
	}
	for(int i=1;i<=n;i++){
		if(a[i][n-1]>ans)
		ans=a[i][n-1];
	}
	cout<<1<<endl<<ans;
	return 0;
} 

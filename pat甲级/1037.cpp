#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005],b[100005];
long long ans=0;

int main(){
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>m;
	for(int j=0;j<m;j++)
		cin>>b[j];
		
	sort(a,a+n),sort(b,b+m);
	
	for(int i=n-1,j=m-1;i>=0&&j>=0;i--,j--){
		if(a[i]<0||b[j]<0)break;
		ans = ans+a[i]*b[j];
	}
	
	for(int i=0,j=0;i<n&&j<m;i++,j++){
		if(a[i]>0||b[j]>0)break;
		ans = ans + a[i]*b[j];
	}
	printf("%lld",ans);
	return 0;
}

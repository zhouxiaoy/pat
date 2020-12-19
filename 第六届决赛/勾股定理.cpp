#include <iostream>
#include <cstdio>

using namespace std;
long long a[10000005];
int main(){
	int n,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		a[i]=i*i;//打表 
		//cout<<a[i]<<' ';
	}
	//cout<<endl;
	int left=1,right=n-1;
	while(left<=right){
		//满足勾股定理 
		if(a[left]+a[right]==a[n]){
			sum++;
			left++;
			right--; 
		}else if(a[left]+a[right]<a[n]){//小于代表需要更大的数，则left++ 	
			left++; 
		}else//大于代表需要更小的数 
			right--;
	}
	 cout<<sum;
	return 0;
}

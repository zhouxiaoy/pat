#include <iostream>
#include <cstdio>

using namespace std;
long long a[10000005];
int main(){
	int n,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		a[i]=i*i;//��� 
		//cout<<a[i]<<' ';
	}
	//cout<<endl;
	int left=1,right=n-1;
	while(left<=right){
		//���㹴�ɶ��� 
		if(a[left]+a[right]==a[n]){
			sum++;
			left++;
			right--; 
		}else if(a[left]+a[right]<a[n]){//С�ڴ�����Ҫ�����������left++ 	
			left++; 
		}else//���ڴ�����Ҫ��С���� 
			right--;
	}
	 cout<<sum;
	return 0;
}

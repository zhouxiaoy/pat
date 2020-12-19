#include  <iostream>
using namespace std;
//第一次快排 
int partition(int *a,int p,int r){
	int t=a[p];
	int begin=p,end=r;
	while(begin<end){
		while(begin<end&&a[end]>t)end--;
		a[begin]=a[end];
		while(begin<end&&a[begin]<=t) begin++;
		a[end]=a[begin];
	}	
	a[begin]=t;
	return begin;
}

int selectK(int *a,int p,int r,int k){
	int q = partition(a,p,r);//主元的下标
	
	int qK = q-p+1;//主元是第几个元素 
	if(qK == k) return a[q];
	else if(qK>k) return selectK(a,p,q-1,k);
	else return selectK(a,q+1,r,k-qK);
}
int main(){
	//求乱序数组中递增第k小的元素 
	int a[6]={1,4,3,2,6,7};
	
	int k = selectK(a,0,5,2);

	cout<<k;
	return 0;
} 

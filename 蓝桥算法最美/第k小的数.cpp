#include  <iostream>
using namespace std;
//��һ�ο��� 
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
	int q = partition(a,p,r);//��Ԫ���±�
	
	int qK = q-p+1;//��Ԫ�ǵڼ���Ԫ�� 
	if(qK == k) return a[q];
	else if(qK>k) return selectK(a,p,q-1,k);
	else return selectK(a,q+1,r,k-qK);
}
int main(){
	//�����������е�����kС��Ԫ�� 
	int a[6]={1,4,3,2,6,7};
	
	int k = selectK(a,0,5,2);

	cout<<k;
	return 0;
} 

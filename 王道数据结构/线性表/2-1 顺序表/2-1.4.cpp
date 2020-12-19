#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int num[1000];

int bsearch_1(int l,int r,int x){//��ͬ��upper_bound 
	while(l<r){
		int mid = l + r +1 >> 1;
		if(num[mid]<=x)l = mid;
		else r = mid -1;
	} 
	return l;
}

int bsearch_2(int l,int r,int x){//��ͬ��lower_bound 
	while(l<r){
		int mid = l + r >> 1;
		if(num[mid]>=x) r = mid;
		else l = mid + 1;
	}
	return l;
}

//ɾ��s��t������Ԫ�� 
bool del_s_to_t(int s,int t){
	if(n == 0){
		puts("˳���Ϊ��"); 
		return false;
	}else if(s>=t){
		puts("s��t������");
		return false; 
	}
	
	//int l = lower_bound(num,num+n,s)- num;
	//int r = upper_bound(num,num+n,s)- num;
	
	int l = bsearch_2(0,n-1,s);
	int r = bsearch_1(0,n-1,t);
	
	for(int i=l;i<=r ||i+ r-l+1<n ;i++)
		num[i] = num[i+ r-l+1];
	
	n = n-r+l-1;
	return true;
} 

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	} 
	int s,t;
	puts("������Ҫɾ��������");
	scanf("%d%d",&s,&t);
	if(del_s_to_t(s,t))
	for(int i=0;i<n;i++){
		printf("%d ",num[i]);
	}
	return 0;
}

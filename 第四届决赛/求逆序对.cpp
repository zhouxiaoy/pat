#include <iostream>
using namespace std;
int niXu=0; 
void erge(int a[],int p,int mid,int r){
	//�����������ռ����ͬλ��
	 int *helper = new int[r-p+1];
	 for(int i=p;i<r-p+1;i++){
	 	helper[i] = a[i];
	 }
	 //�������������ָ�� 
	 int left = p,right = mid+1;
	 //ԭʼ�����ָ��
	 int current =p;
	 while(left<=mid && right<=r){
	 	if(helper[left]<= helper[right]){
	 		a[current++] = helper[left++];
	 	}else{//�ұ�С 
	 		a[current++] = helper[right++];
	 		niXu+=mid-left+1;
	 	}
	 } 
	 //������������ָ�����û��ͷ���ұߵ�û��ͷҲû��ϵ��������Ϊʲô
	 while(left <= mid){
	 	a[current] = helper[left];
	 	current++;
	 	left++;
	 } 
	 delete []helper; 
}
void sort(int a[],int p,int r){
	if(p<r){
		int mid = p +((r-p)>>1);
		sort(a,p,mid);
		sort(a,mid+1,r);
		merge(a,p,mid,r);
	}
}
int main(){
	
	return 0;
} 

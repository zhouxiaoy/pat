#include <iostream>

using namespace std;
//Ѱ��ˮ�� ���ҳ�������ռ��һ�������
int solve(int arr[],int n){
	int candidate;
	int nTime =0;
	int countOfLast =0;//ͳ��������Ԫ�صĸ��� 
	for(int i=0;i<n;i++){
		//�����һ��Ԫ�رȽϵĲ���
		if(arr[i] == arr[n-1]){//��������������Ԫ��+1 
			countOfLast++;
		} 
		if(nTime == 0){
			candidate = arr[i];
			nTime = 1;
			continue;
		}
		if(arr[i] == candidate)
			nTime++;
		else
			nTime--;
	}
	if(countOfLast == n/2)
		return arr[n-1];
	else 
		return candidate;
} 
int main(){
	int n;
	int a[8]={1,2,3,6,6,6,6,3};
	cout<<solve(a,8);
	
	return 0;
}

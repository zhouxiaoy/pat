#include <iostream>

using namespace std;
//寻找水王 即找出数组中占比一半的数字
int solve(int arr[],int n){
	int candidate;
	int nTime =0;
	int countOfLast =0;//统计最后这个元素的个数 
	for(int i=0;i<n;i++){
		//和最后一个元素比较的步骤
		if(arr[i] == arr[n-1]){//如果相等则最后这个元素+1 
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

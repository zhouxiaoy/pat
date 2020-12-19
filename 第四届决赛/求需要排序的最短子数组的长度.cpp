#include <iostream>
using namespace std;
int a[100],n;
int minLength(){
	int minNum=-1,maxNum=-1;
	int max=a[0],min=a[n-1];
	for(int i=1;i<n;i++){
		if(a[i]>max)
			max=a[i];
		else if(a[i]<max)
			maxNum=i; 
	}
	//避免数组本身就是有序的  而引起数组越界 
	if(maxNum == -1)
		return 0;
	for(int i=n-2;i>=0;i--){
		if(a[i]<min)
			min=a[i];
		else if(a[i]>min)
			minNum=i;
	}
	//避免数组本身就是有序的  而引起数组越界 
	if(minNum == -1)
		return 0;
	//cout<<"maxNum:"<<maxNum<<endl;
	//cout<<"minNum:"<<minNum<<endl;
	return maxNum-minNum+1;
}
int main(){
	cout << "请输入数组的大小并输入一组数：";
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> a[i];
	cout << minLength() << endl;
	return 0;
} 

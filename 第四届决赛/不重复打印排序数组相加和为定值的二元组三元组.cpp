#include <iostream>
#include <cstdio>
using namespace std;
void printUniquePair(int arr[],int k,int n){
	if(n<2){
		return;
	}
	int left=0,right=n-1;
	while(left<right){
		if(k-arr[left]-arr[right]==0){
			printf("%d,%d\n",arr[left],arr[right]);
			left++;
			right--;
		}else if(k-arr[left]-arr[right]>0){
			left++;
		}else{
			right--;
		}
	}
}

void printRest(int *arr,int first,int left,int right,int k){
	while(left<right){
		if(arr[left]+arr[right]<k){
			left++;
		}else if(arr[left]+arr[right]>k){
			right--;
		}else{
			if(left==first+1||arr[left-1]!=arr[left]){
				//保证二元组不重复
				printf("%d,%d,%d\n",arr[first],arr[left],arr[right]); 
			}
			left++;
			right--;
		}
	}
}

void printUniqueTriad(int *arr,int k,int n){
	if(n<3)
		return;
	for(int i=0;i<n-2;i++){
		int left=i+1,right=n-1;
		if(arr[i]!=arr[i-1])
		while(left<right){
			if(k-arr[i]-arr[left]-arr[right]==0){
				printf("%d,%d,%d\n",arr[i],arr[left],arr[right]);
				left++;
				right--;
			}else if(k-arr[i]-arr[left]-arr[right]>0){
				left++;
			}else{
				right--;
			}
		}
	}
}
int main(){
	int arr[]={-8,-4,-3,0,1,2,2,4,4,4,5,8,9};
	printUniquePair(arr,10,13);
	printUniqueTriad(arr,10,13);
	return 0;
}

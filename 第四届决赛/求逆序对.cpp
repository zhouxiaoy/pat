#include <iostream>
using namespace std;
int niXu=0; 
void erge(int a[],int p,int mid,int r){
	//拷贝到辅助空间的相同位置
	 int *helper = new int[r-p+1];
	 for(int i=p;i<r-p+1;i++){
	 	helper[i] = a[i];
	 }
	 //辅助数组的两个指针 
	 int left = p,right = mid+1;
	 //原始数组的指针
	 int current =p;
	 while(left<=mid && right<=r){
	 	if(helper[left]<= helper[right]){
	 		a[current++] = helper[left++];
	 	}else{//右边小 
	 		a[current++] = helper[right++];
	 		niXu+=mid-left+1;
	 	}
	 } 
	 //这样做完后，左边指针可能没到头；右边的没到头也没关系，想想是为什么
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

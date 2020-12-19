#include <iostream>
using namespace std;
void printZ(int (*matrix)[4],int col,int row){
	int r=0,c=0,m=row,n=col;
	bool l2r = true;//从左到右
	while(r<m && c<n){
		//从左下到右下的斜线
		if(l2r){
			cout<<matrix[r][c]<<' ';
			//现在在第一行，列未到边界，这是只能向右走
			if(r == 0 && c<n-1){
				l2r = !l2r;
				c++;
				continue; 
			}
			//现在在最后一列 ，只能向下走 
			else if(r>0 && c== n-1){
				l2r = !l2r;
				r++;
				continue; 
			}
			//继续走上坡
			else{
				r--;
				c++; 
			}
		} 
		//走下坡，从右往左 
		else{
			cout<<matrix[r][c]<<' ';
			//走到第一列，只能往下走 
			if(c == 0 && r < m-1){
				l2r = !l2r;
				r++;
				continue;
			}
			//到最后一行,只能往下走 
			else if(r == m-1){
				l2r = !l2r;
				c++; 
			}
			//继续走下坡 
			else{
				c--;
				r++; 
			} 
		} 
	} 
}
int main(){
	int matrix[4][4]={
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,16}
	};
	printZ(matrix,4,4);
	return 0;
} 

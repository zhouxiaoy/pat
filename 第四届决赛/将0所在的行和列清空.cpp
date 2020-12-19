#include <iostream>
using namespace std;
int row[100],col[100];
int main(){
	int matrix[4][4]={
		{1,2,3,4},
		{5,6,0,8},
		{9,0,11,12},
		{13,14,15,16}
	};
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++)
		if(matrix[i][j]==0){
			row[i]=1;
			col[j]=1;
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(row[i]!=1&&col[j]!=1){
				cout<<matrix[i][j]<<',';
			}else{
				cout<<0<<',';
			}
		}
		cout<<endl; 
	} 
	return 0;
} 

#include <iostream>
using namespace std;
void printZ(int (*matrix)[4],int col,int row){
	int r=0,c=0,m=row,n=col;
	bool l2r = true;//������
	while(r<m && c<n){
		//�����µ����µ�б��
		if(l2r){
			cout<<matrix[r][c]<<' ';
			//�����ڵ�һ�У���δ���߽磬����ֻ��������
			if(r == 0 && c<n-1){
				l2r = !l2r;
				c++;
				continue; 
			}
			//���������һ�� ��ֻ�������� 
			else if(r>0 && c== n-1){
				l2r = !l2r;
				r++;
				continue; 
			}
			//����������
			else{
				r--;
				c++; 
			}
		} 
		//�����£��������� 
		else{
			cout<<matrix[r][c]<<' ';
			//�ߵ���һ�У�ֻ�������� 
			if(c == 0 && r < m-1){
				l2r = !l2r;
				r++;
				continue;
			}
			//�����һ��,ֻ�������� 
			else if(r == m-1){
				l2r = !l2r;
				c++; 
			}
			//���������� 
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

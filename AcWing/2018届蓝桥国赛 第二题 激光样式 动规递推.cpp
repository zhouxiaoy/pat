#include <iostream>
using namespace std;
int main(){
	int f[32][2]={0}; // f[i][0]�������г�����i�����һλ��0����û������1�ķ����� 
	f[1][0]=1;
	f[1][1]=1;
	for(int i=2;i<=30;i++){
		f[i][0]=f[i-1][0]+f[i-1][1];
		f[i][1]=f[i-1][0];
	}
	cout<<f[30][0]+f[30][1]; 
	return 0;
} 

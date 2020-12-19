#include <iostream>
using namespace std;
int main(){
	int f[32][2]={0}; // f[i][0]代表所有长度是i，最后一位是0，且没有连续1的方案数 
	f[1][0]=1;
	f[1][1]=1;
	for(int i=2;i<=30;i++){
		f[i][0]=f[i-1][0]+f[i-1][1];
		f[i][1]=f[i-1][0];
	}
	cout<<f[30][0]+f[30][1]; 
	return 0;
} 

#include <iostream>
#include <cstdio>
using namespace std;
int rec[100][100][2];
int A[100][100];
void print(int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << rec[i][j][0] << ',' << rec[i][j][1] << ' ';
		}
		cout << endl;
	}
}
void generateHelpRec(int n) {
	int N = n;//方阵的行数 
	int row = N - 1;
	//计算行的数目 
	for (int i = 0; i < N; i++) {
		for (int j = N-1; j>=0; j--) {
			if(A[j][i]){
				rec[j][i][1]=rec[j+1][i][1] + 1; 
			}
		}
	}

	//计算列的数目 
	for (int i = 0; i < N; i++) {
		for (int j = N-1; j>=0; j--) {
			if(A[i][j]){
				rec[i][j][0]=rec[i][j+1][0] + 1; 
			}
		}
	}
	//print(n);
}
int getMaxMatrix(int n){
	for(int i=n;i>=1;i--){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(rec[j][k][0]>=i&&rec[j][k][1]>=i&&rec[j+i-1][k][0]>=i&&rec[j][k+i-1][1]>=i){
					return i;
				}
			}
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
	generateHelpRec(n);
	cout<<getMaxMatrix(n);
	return 0;
}

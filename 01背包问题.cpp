#include <cstdio> 
#include <iostream>
using namespace std;

#define N 6
#define W 21

int b[N][W] = {0};
int w[6] = {0, 2, 3, 4, 5, 9};
int v[6]= {0,3,4,5,8,10};

void knapsack(){
	int k,C;
	for(k=1;k<N;k++){
		for(C=1;C<W;C++){
			if(w[k]>C)
				b[k][C]=b[k-1][C];
			else
				b[k][C] = max(b[k-1][C-w[k]]+v[k],b[k-1][C]);
		}
	}
} 

int main(){
	knapsack();
	printf("%d",b[5][20]);
	return 0;
}

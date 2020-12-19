#include <iostream>
#include <memory.h>
using namespace std;
int CaloCount(int n,int *pCount,int *pPre){
	if(n==1)
		return 0;
	if(n%2==1){
		if(pCount[n-1]==0)
				pCount[n-1] = CaloCount(n-1,pCount,pPre);
		pPre[n] = n-1;
		pCount[n] = pCount[n-1] +1;
	}
	else{
		int n2=n/2;
		if(pCount[n2] ==0)
		 	pCount[n2] = CaloCount(n2,pCount,pPre);
		if(pCount[n-1]==0)
			pCount[n-1] = CaloCount(n-1,pCount,pPre);
		
		if(pCount[n2]<pCount[n-1]){
			pPre[n] = n2;
			pCount[n] = pCount[n2]+1;
		}
		else{
			pPre[n] = n-1;
			pCount[n] = pCount[n-1] + 1;
		}
	}
	return pCount[n];
} 
int main(){
	int n=2015;
	int pCount[2016];
	int pPre[2016];
	memset(pCount+1,0,sizeof(int)*n);
	memset(pPre+1,0,sizeof(int)*n);
	cout<<CaloCount(n,pCount,pPre)<<endl<<"2015\t";
	
	//求2015的变化过程
	while(n != 0){
		cout<<pPre[n]<<'\t';
		n = pPre[n];
	} 
	return 0;
} 

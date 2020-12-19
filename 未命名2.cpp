#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int map[105][105]={0},a[105][105]={0},n,m,max=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		if(m>max)max=m;
		for(int j=0;j<10*m;j++){
			map[i][j]=1;
		}
	}
	
	int num=1,flag=-1;
	for(int i=0;i<10*max;i++){
		for(int j=0;j<n;j++){
			if(map[j][i]){
				if(flag!=j){
					a[j][i]=num++;
					flag=j;
				}
				else{
					num+=1;
					a[j][i]=num++;
					flag=j;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("#%d\n",i+1);
		for(int j=0;j<10*max;j++){
			if(a[i][j])printf("%d%c",a[i][j],(j+1)%10==0?'\n':' ');
		}
	}
	return 0;
}

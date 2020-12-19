#include <iostream>
#include <cstdio>
using namespace std;
char a[1005][1005];

void fun(int x,int y){
	if(a[x][y]!='#')return;
	
	a[x][y]='4';
	fun(x+1,y);
	fun(x-1,y);
	fun(x,y+1);
	fun(x,y-1);
}

void fun1(int x,int y){
	if(a[x][y]>='4'&&a[x][y]<='8')
	{
		a[x][y]='.';
		fun1(x+1,y);
		fun1(x-1,y);
		fun1(x,y+1);
		fun1(x,y-1);
	}
}

int main(){
	int n;
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		getchar();
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	
	int sum=0,ans=0;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]=='#'){
				fun(i,j);
				sum++;			
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]>='4'&&a[i][j]<='8'){
				if(a[i+1][j]!='.')
					a[i+1][j]++;
				if(a[i-1][j]!='.')
					a[i-1][j]++;
				if(a[i][j+1]!='.')
					a[i][j+1]++;
				if(a[i][j-1]!='.')
					a[i][j-1]++;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
				if(a[i][j]=='8')
				{
					fun1(i,j);
					ans++;
				}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	
	cout<<sum-ans;
	return 0;
}

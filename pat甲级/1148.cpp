#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
int main(){
	int n;
	int a[105];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	//模拟狼人的所有可能性 
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			vector<int> v(n+1,1),lie;//1为平民
			v[i]=v[j]=-1;//-1代表狼人  
			for(int k = 1;k <= n;k++)
				if(a[k]*v[abs(a[k])]<0)   lie.push_back(k);
			
			if(lie.size() == 2 && v[lie[0]] + v[lie[1]] == 0){
				cout<<i<<' '<<j<<endl;
				return 0;
			}
		}
	}
	puts("No Solution");
	return 0;
} 

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int a[10005];
int main(){
	int n,num;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		cin>>num;
		a[num]++;
		v.push_back(num);
	}
	for(int i=0;i<v.size();i++)
		if(a[v[i]]==1){
			cout<<v[i]<<endl;
			return 0;
		}
	puts("None");
	return 0;
} 

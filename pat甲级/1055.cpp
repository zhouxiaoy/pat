//≈≈–Ú 
#include <iostream>
#include <cstdio>
#include <string> 
#include <algorithm> 
using namespace std;

struct node{
	string name;
	int age,worth;
}a[100005];

bool cmp(node a,node b){
	if(a.worth != b.worth)
		return a.worth>b.worth;
	else if(a.age != b.age)
		return a.age<b.age; 
	else
		return a.name<b.name;
}

int main(){
	int n,m,minn,maxx,k;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		cin>>a[i].name>>a[i].age>>a[i].worth;
		
	sort(a,a+n,cmp);
	int Case = 1;
	for(int i=0;i<m;i++){
		bool flag = false;
		scanf("%d%d%d",&k,&minn,&maxx);
		printf("Case #%d:\n",Case++);
		for(int j=0,t=0;t<k && j<n;j++) 
			if(a[j].age >= minn && a[j].age <= maxx){
				cout<<a[j].name<<' '<<a[j].age<<' '<<a[j].worth<<endl;
				flag = true;
				t++;
			}
		if(!flag) puts("None");
	}
	return 0;
} 

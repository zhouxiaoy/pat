#include <iostream>
#include <cstdio>
using namespace std;
struct node{
	string name,pwd;
	bool flag = false;
};

void isChange(node & n){
	for(int i=0;i<n.pwd.size();i++){
		if(n.pwd[i] == '1'){
			n.pwd[i] = '@';
			n.flag = true;
		}
		else if(n.pwd[i] == '0'){
			n.pwd[i] = '%';
			n.flag = true;
		}
		else if(n.pwd[i] == 'l'){
			n.pwd[i] = 'L';
			n.flag = true;
		}
		else if(n.pwd[i] == 'O'){
			n.pwd[i] = 'o';
			n.flag = true;
		}
	}	
}

int main(){
	int n;
	node a[1005];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].name>>a[i].pwd;
		isChange(a[i]);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i].flag == true){
			ans++;
		}
	}
	if(ans == 0){
		if(n==1)
			puts("There is 1 account and no account is modified");
		else
			printf("There are %d accounts and no account is modified\n",n);
	}else{
		cout<<ans<<endl;
		for(int i=0;i<n;i++)
			if(a[i].flag==true)
				cout<<a[i].name<<' '<<a[i].pwd<<endl;
		
	}
	return 0;
} 

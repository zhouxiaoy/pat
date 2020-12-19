#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	cin>>str;
	int i,j,flag;
	for(i=1;i<=str.size();i++){//i表示为最小周期
		if(str.size()%i==0){//字符串的长度必须是最小周期的倍数 
			flag=1;
			for(j=i;j<str.size();j++){
				if(str[j]!=str[j%i]){//代表该周期不正确 
					flag=0;
					break;
				}
			}
			
			if(flag){//如果是1表示该周期是最小周期 
				cout<<i;
				break;
			}
		}
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <string> 
using namespace std;

/* 
int main(){
	char c;
	string str[10] = {"zero", "one", "two", "three", "four", "five", "six","seven", "eight", "nine"};
	long long num=0;
	vector<string> v;
	while(scanf("%c",&c),c!='\n'){//错误猜想这个不为\n也可能是其他的东西
								//出现段错误 那应该就是这里输入的问题 
		num+=c-'0';
	}
	while(num>0){
		v.push_back(str[num%10]);
		num=num/10;
	}
	vector<string>::iterator it=v.end();
	for(;it!=v.begin();it--){
		if(it==(v.begin()+1))
			cout<<*(it-1)<<endl;
		else
		cout<<*(it-1)<<' ';
		
	}
	return 0;
} 
*/

int main(){
	string arr[10]={"zero", "one", "two", "three", "four", "five", "six","seven", "eight", "nine"};
	string str;
	cin>>str;
	int num=0,i;
	for(i=0;i<str.size();i++){
		num+=str[i]-'0';
	}
	string st=to_string(num);
	cout<<arr[st[0]-'0'];
	for(i=1;i<st.size();i++){
		cout<<' '<<arr[st[i]-'0'];
	}
	return 0;
} 

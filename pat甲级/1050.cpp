//ϰ���˼�1 ���Գ����ˣ�����ɵ���� 
//�һ����пո��е�� 
#include <iostream>
#include <string>
using namespace std;

bool vis[300];

int main(){
	string str1,str2;
	getline(cin,str1);
	getline(cin,str2);
	for(int i=0;i<str2.size();i++){ 
		vis[str2[i]] = true;
	}
	for(int i=0;i<str1.size();i++)
		if(!vis[str1[i]])
			cout<<str1[i];
	return 0;
} 

#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	cin>>str;
	int i,j,flag;
	for(i=1;i<=str.size();i++){//i��ʾΪ��С����
		if(str.size()%i==0){//�ַ����ĳ��ȱ�������С���ڵı��� 
			flag=1;
			for(j=i;j<str.size();j++){
				if(str[j]!=str[j%i]){//��������ڲ���ȷ 
					flag=0;
					break;
				}
			}
			
			if(flag){//�����1��ʾ����������С���� 
				cout<<i;
				break;
			}
		}
	}
	return 0;
}

#include <iostream>
#include <cstring>

using namespace std;
char zd[24][3]={"°¡","°Å","²Á","´î","¶ê","·¢","¸Á","¹þ","»÷","¿¦","À¬","Âè","ÄÃ","Å¶","Å¾","ÆÚ","È»","Èö","Ëú","ÍÚ","Îô","Ñ¹","ÔÑ"};
char zm[24]={'A','B','C','D','E','F','G','H','J','K','L','M','N','O','P','Q','R','S','T','W','X','Y','Z'};

int main(){
	int n;
	cin>>n;
	string str;
	char ch[2];
	for(int i=0;i<n;i++){
		cin>>str;
		for(int k=0;k<str.size();k+=2){
			ch[0]=str[k];
			ch[1]=str[k+1];
			for(int j=0;j<24;j++){
				if(strcmp(ch,zd[j])<0){
					cout<<zm[j-1];
					break;
				}
			}
			if(k==str.size()-2)
				cout<<endl;
		} 
	}
	return 0;
}

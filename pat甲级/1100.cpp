#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
string a[13] ={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string b[13] = {"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};


int main(){
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		string str;
		getline(cin,str);
		int t = 0;
		if(str[0]>='0' && str[0]<='9'){//is earth Language 
			for(int k = 0;k<str.size();k++)
				t = t*10+(str[k]-'0');//比如 tam 是 13  而不是 tam tret
			if(t/13){	
				cout<<b[t/13];
				if(t%13 == 0) cout<<endl;
				else cout<<' '<<a[t%13]<<endl;
			}
			else
				cout<<a[t%13]<<endl;
			
		}else{// is Mars language
			int t1 = 0, t2 = 0;
			string s1 = str.substr(0, 3), s2;
			if (str.size() > 4) s2 = str.substr(4, 3);//比如 tam 是 13  而不是 tam tret 
			for (int j = 1; j <= 12; j++) {
				if (s1 == a[j] || s2 == a[j]) t2 = j;
				if (s1 == b[j]) t1 = j;//优先b[j]  比如 是tam时为3位，但要用到b数组 
			}
			cout << t1 * 13 + t2<<endl;	
			
		}
	}
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	string str;
	cin>>str>>n;
	while(--n){
		string temp="";
		temp += str[0];
		int ans = 1;
		for(int i=1;i<str.size();i++){
			if(str[i] == str[i-1])
				ans++;
			else{
				temp += (char)(ans+'0');
				temp += str[i];
				ans = 1;
			}
		}
		temp += (char)(ans+'0');
		str = temp;
		//cout<<str<<endl;
	}
	cout<<str;
	return 0;
}
 

#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	string max,min,max_num="00:00:00",min_num="24:60:60";
	
	for(int i=0;i<n;i++){
		string str,str1,str2;
		cin>>str>>str1>>str2;
		if(str1<=min_num){
			min_num=str1;
			min=str;
		}
		if(str2>max_num){
			max=str;		
			max_num=str2;
		}
	}
	cout<<min<<' '<<max; 
	return 0;
} 

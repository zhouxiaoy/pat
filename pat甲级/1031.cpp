#include <iostream>
#include <string>

using namespace std;
int main(){
	string str;
	cin>>str;
	int n = (str.size()+2)/3;
	int m = str.size()-2*(n-1); 
	//cout<<n<<' '<<str.size()-2*(n-1)<<endl;
	int temp = n;
	while(temp>1){
		cout<<str[n-temp];
		for(int i=0;i<m-2;i++)
			cout<<' ';
		cout<<str[str.size()-1-(n-temp)]<<endl;
		temp--;
	}
	for(int i=n-1;i<n+m-1;i++)
		cout<<str[i];
	return 0;
} 

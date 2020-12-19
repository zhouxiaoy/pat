#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	 int T,K,flag=true;
	 cin>>T>>K;
	 int n1,b,t,n2;
	 for(int i=0;i<K;i++){
	 	cin>>n1>>b>>t>>n2;
	 	if(flag==false)
	 		continue;
	 	if(t<=T){
	 		if((n2-n1>0&&b==1)||(n2-n1<0&&b==0)){
	 			T+=t;
	 			cout<<"Win "<<t<<"!  Total = "<<T<<"."<<endl;
	 		}else{
	 			T-=t;
	 			cout<<"Lose "<<t<<".  Total = "<<T<<"."<<endl;
	 			if(T==0){
	 				flag=false;
	 				cout<<"Game Over."<<endl;
	 			}
			}
	 	}else{
	 			cout<<"Not enough tokens.  Total = "<<T<<"."<<endl;
	 	}
	 }
	return 0;
}

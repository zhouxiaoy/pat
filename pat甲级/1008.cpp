#include <iostream>

using namespace std;

int main(){
	int n,next,acc=0,up=6,down=4,time=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>next;
		time+=5;
		if(next>acc)time+=(next-acc)*up;
		else if(next<acc)time+=(acc-next)*down;
		acc=next;
		//cout<<time<<endl; 
	}
	cout<<time<<endl;
	return 0;
}

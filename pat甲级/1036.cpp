#include<iostream>
#include <cstdio>
using namespace std;
struct peo{
	string name,ID;
	char gender;
	int grade;
};
int main(){
	int n;
	cin>>n;
	int F=-1,M=101;
	peo f,m;
	for(int i=0;i<n;i++){
		peo a;
		cin>>a.name>>a.gender>>a.ID>>a.grade;
		if(a.gender == 'M')//ÊÇÄÐº¢
		{
			if(a.grade<M){
				M = a.grade;
				m = a;
			}
		}else{
			if(a.grade>F){
				F = a.grade;
				f = a;
			}
		}
	}
	int flag = 0;
	if(F == -1){//Å®º¢È±Ï¯ 
		puts("Absent");
		flag = 1; 
	}else{
		cout<<f.name<<' '<<f.ID<<endl;
	}
	if(M == 101){//ÄÐº¢È±Ï¯ 
		puts("Absent");
		flag =1; 
	}else{
		cout<<m.name<<' '<<m.ID<<endl;
	} 
	if(flag == 1)
		puts("NA");
	else
		cout<<f.grade-m.grade<<endl; 
	return 0;
} 

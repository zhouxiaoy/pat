#include <iostream>
#include <cstdio>
#include <stack> 
using namespace std;

int n = 1,m = 6;
int a[10] = {1,2,3,4,5,6,7,8,9,10};
stack<int> s;
void visit(int idx,int b){
	if(idx >= b)return;
	if(a[idx] == m)return;
	s.push(a[idx]);
	visit(a,idx*2+1,b);//visit×ó×ÓÊ÷
	s.pop();
	visit(a,idx*2+2,b);//visitÓÒ×ÓÊ÷ 
	s.pop();
}



int main(){
	visit(0,10);
	while(s.size()){
		cout<<s.top()<<' ';
		s.pop();
	} 
	return 0;
}

#include <iostream>
using namespace std;
int fun(int x,int y){//x����δ��վ�ĳ�������y����δ��ջ�ĳ����� 
	if(x==0)
		return 1;
	if(y==0)
		return fun(x-1,1);
	return fun(x-1,y+1) + fun(x,y-1);
}
int main(){
		cout<<fun(16,0); 
	return 0;
}

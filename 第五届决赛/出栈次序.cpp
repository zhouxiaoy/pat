#include <iostream>
using namespace std;
int fun(int x,int y){//x代表未进站的车数量，y代表未出栈的车数量 
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

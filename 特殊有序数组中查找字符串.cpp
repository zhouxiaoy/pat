#include <iostream>
#include <string>
using namespace std;
int fun(const string *a,int k,const string b)
{
	int begin=0,end=k-1;
	while(begin<=end){
		int mid=begin+((end-begin)>>1);
		while(a[mid]=="")mid++;
	if(mid>end)
	return -1;
	if(a[mid].compare(b)>0)end=mid-1;
	else if(a[mid].compare(b)<0)begin=mid+1;
	else return mid;
	}
	return -1;
}
int main()
{
	string strs[]={"a","","ac","","ad","b","","ba"};
	string str;
	cin>>str;
	cout<<fun(strs,8,str);
	return 0;
}

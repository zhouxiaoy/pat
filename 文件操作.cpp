#include <cstdio>
#include <climits>
#include <fstream>
#include <iostream>
using namespace std;
int main(){
	//д����
	char data[256]; 
	ofstream Write("Hello.txt",ios::trunc);
	char a='a';
	for(int i=0;i<26;i++)
		Write<<i<<'\t'<<char(a+i)<<"\n";
	Write.close();
	ifstream Read("Hello.txt");
	int i=0;
	//���ж�ȡ 
	/*
	while(!Read.eof())
	{
		Read.getline(data,256,'\n');
		cout<<data<<endl; 
	}
	*/
	int c; 
	//���ֶ�ȡ 
	while(!Read.eof()){
		Read>>c;
		cout<<c;
		Read>>a;
		cout<<a<<endl;
	}
	Read.close();
	return 0;
} 

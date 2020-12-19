#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;
string st[8],st1[8];
queue<string> q;
queue<int> b;
map<string,int> mp;
string str,str1;
int length=0;
void bfs(){
	string s,ss;
	int i,m;
	while(q.empty()==false &&q.front() !=str1 && b.front()<=10){
		if(mp[q.front()]==1){
			q.pop();
			b.pop();
			continue;
		}
		mp[q.front()]=1;
		for(i=0;i<length;i++){
			s = q.front();
			while(1){
				m = s.find(st[i]);
				if(m==-1)break;
				ss = q.front();
				ss.replace(m,st[i].size(),st1[i]);
				q.push(ss);
				b.push(b.front()+1);
				s[m]='~'; 
			}
		}
		q.pop();
		b.pop();
	}
	if(q.empty()==true||b.front()>10){
		cout<<"NO ANSWER!";
		return;
	}else{
		cout<<b.front();
		return;
	}
	
}
int main(){
	
	cin>>str>>str1;
	
	while(cin>>st[length]>>st1[length])length++;
	
	/*
	cout<<"-------------------"<<endl;
	for(int i=0;i<length;i++)
		cout<<st[i]<<' '<<st1[i]<<endl;
	*/
	q.push(str);
	b.push(0);
	bfs();
	return 0;
} 

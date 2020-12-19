#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int n,k,res=0;
const int N = 100010;
int d[N]; 
queue<int> q;

void bfs(){
	while(q.size()){

		int t = q.front();
		q.pop();
		
		int a = t + 1;
		if(d[a]==-1){
			d[a]=d[t]+1;
			q.push(a);
		}
		
		int b = t + k;
		if(d[b]==-1){
			d[b]=d[t]+1;
			q.push(a);
		}
	}
	
}

int main(){
	cin>>n>>k;
	
	memset(d,-1,sizeof d);
	d[0]=0;
	q.push(0);
	
	bfs();
	
	for(int i=0;i<n;i++) {
	//cout<<i<<' '<<d[i]<<endl;
	res = max(d[i],res);
	}
	cout<<res<<endl;
	return 0;
}

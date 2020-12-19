#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct node{
	int x,y;
};

vector<node> v;
int main(){
	int n,m,k;
	cin>>n>>m;
	v.resize(m);
	for(int i=0;i<m;i++)
		cin>>v[i].x>>v[i].y;
	
	cin>>k;
	while(k>0){
		int color[1005],flag = 1;
		set<int> st;
		for(int i=0;i<n;i++){
			cin>>color[i];
			st.insert(color[i]);
		}
		
		for(int i=0;i<n;i++){
			if(color[v[i].x] == color[v[i].y]){
				flag = 0;
				break;
			}
		}
		if(flag == 1)
			printf("%d-coloring\n",st.size());
		else
			puts("No");
		k--;
	}
	return 0;
}

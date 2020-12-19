#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    
	for(int i=0;i<n;i++)
    	cin>>v[i];
    for(int i=0;i<k;i++){
    	int t;
    	cin>>t;
    	int l = 0, r = n-1,mid;
    	while(l<r){//����<=t�����ֵ
    		mid = l + r + 1 >> 1;
			if(v[mid]<=t) l = mid;
			else r = mid -1; 
    	}
    	
    	if(v[l]!=t) {
			puts("-1 -1");
			continue;
		}
		 
    	int end = l;//�������ֵ 
    	l = 0;//��������
		while(l<r){//��>=t����Сֵ 
			mid = l + r >> 1;
			if(v[mid]>=t) r = mid;
			else l = mid + 1; 
		}
		cout<<l<<' '<<end<<endl;
    }	
    return 0;
}

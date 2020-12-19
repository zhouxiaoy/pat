#include <iostream>
#include <cstdio>

using namespace std;
 
const int N = 10010, M = 100010;

int n, m;
int ne[N];
char s[M], p[N];

int main()
{
    cin >> m >> s + 1 >> n >> p + 1;
	//����next���� 
	for(int i = 2, j = 0; i <= m; i ++){
		while(j && s[j+1] != s[i]) j = ne[j];
		if(s[j+1]  == s[i]) j++;
		ne[i] = j;
	}
	
	for(int i=0;i<=m;i++)
		cout<<ne[i]<<' ';
	cout<<endl;
	//ģʽƥ�����
	for(int i = 1, j = 0; i <= n; i ++){
		while(j && p[i] != s[j+1]) j = ne[j];
		if(s[j+1] == p[i]) j++;
		//ƥ��ɹ� 
		if(j == m){
			printf("%d ",i-m);
			j = ne[j]; 
		}
	} 
    return 0;
}

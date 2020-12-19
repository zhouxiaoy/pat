#include <iostream>
#include <string>
using namespace std;

int f(string &a,string &temp,int N){
    int point = -1,index = -1;
    for(int i=0;i<a.size();i++){
        if(a[i] == '.'){
            point = i;
        }else if(index != -1 && temp.size()<N){
            temp+=a[i];
        }else if(index == -1 && a[i] != '0'){
            index = i;
            temp+=a[i];
        }
    }
    //������0
    while(temp.size()<N)temp+="0";
    if(index == -1)return 0;//������aΪ0
    point -= index;
    //point>0 �����һλ��Ϊ0������С����֮ǰ���������֮��
    return point ? point : point+1;
}

int main(){
    int n;
    string a,b,tempA="",tempB="";
    cin>>n>>a>>b;
    int expA = f(a,tempA,n),expB = (b,tempB,n);
    if(expA == expB && tempA == tempB){
        cout<<"YES 0."<<tempA<<"*10^"<<expA;
    }
    else{
        cout<<"NO 0."<<tempA<<"*10^"<<expA;
        cout<<'*'<<tempB;
        if(expB > 1)cout<<"*10^"<<expB;
        
        
    }
        
    return 0;
}

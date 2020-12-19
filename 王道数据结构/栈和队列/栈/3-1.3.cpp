#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;

bool f(const string &a){
    int ans=0;
    for(int i=0;i<a.size();i++){
        if(a[i] == 'I')
            ans++;
        else{
            if(ans > 0)ans--;
            else return false;
        }
    }
    if(ans == 0)
        return true;
    else 
        return false;
}

int main(){
    int m;
    string str;
    cin>>n>>m;
    while(m --){
        cin>>str;
        if(f(str))
            cout<<"  Yes"<<endl;
        else 
            cout<<"  No"<<endl;
        
    }
    return 0;
}

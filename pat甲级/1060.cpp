//最怕的题目 浮点数的处理（字符串） 


#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

int getPosition(string a){
    int t = -1;
    for(int i=0;i<a.size();i++)
	    if(a[i] == '.'){
	        t = i;break;
	    }
	return t;
}

int main(){
	int n; 
	string a,b;
	cin>>n>>a>>b;
	int dec_a,dec_b;//小数点的位置
	dec_a = getPosition(a);//也可以直接用find函数
	dec_b = getPosition(b);
	
	int t1 = 0,t2 = 0;
	
	if(dec_a != -1) t1 = a.size()-dec_a - 1, a.erase(dec_a,1);
	if(dec_b != -1) t2 = b.size()-dec_b - 1, b.erase(dec_b,1);
	//cout<<t1<<' '<<t2<<endl;
	
	if (t1 > t2)
	    b.insert(b.size()-1, t1 - t2, '0');
	else if(t1 < t2)
	    a.insert(a.size()-1, t2 - t1, '0');
	cout<<a<<' '<<b<<endl;
	bool flag = true;
	if(a.size() != b.size())flag = false;
	for(int i=0;i<n;i++){
	    if(a[i]!=b[i]){
	        flag = false;
	        break;
	    }
	}
	if(flag)
	    printf("YES 0.");
	else printf("NO 0.");
	for(int i=0;i<n;i++)
	   if(i<b.size())
	        printf("%c",b[i]);
	   else
	        printf("0");
	printf("*10^%d",a.size() - max(t1,t2));
	
	if(!flag){
	printf(" 0.");
	for(int i=0;i<n;i++)
	   if(i<b.size())
	        printf("%c",b[i]);
	   else
	        printf("0");
	printf("*10^%d",b.size() - max(t1,t2));
	}
	return 0;
} 

//网上的比较容易理解的 
/*
#include<bits/stdc++.h>
using namespace std;
int f(const string&s,string&temp,int N){//将字符串s的N位有效数字存储在字符串temp中，并返回指数
    int point=s.size(),index=-1;//point指示字符串s中小数点的位置，初始化为字符串s最后一位，index指示s中第一位非零数字的位置，初始化为-1
    for(int i=0;i<s.size();++i)//遍历字符串s
        if(s[i]=='.')//找出小数点位置
            point=i;
        else if(index!=-1&&temp.size()<N)//将s中最多N位有效数字存储在temp中
            temp+=s[i];
        else if(index==-1&&s[i]!='0'){//找到字符串s第一位非零数字的位置
            index=i;
            temp+=s[i];
        }
    while(temp.size()<N)//temp长度小于N，即有效数字位数小于N
        temp+="0";//在字符串末尾加足够的0保证有N位有效数字
    if(index==-1)//没有找到非零数字，说明字符串s表示的数是0
        return 0;//指数为0，返回
    point-=index;//小数点位置减去第一位非零数字位置得到指数
    return point<0?point+1:point;//当前point为负数，返回point+1；否则返回point
}
int main(){
    int N;
    string A,B,Atemp="",Btemp="";
    cin>>N>>A>>B;//读取数据
    int Aexp=f(A,Atemp,N),Bexp=f(B,Btemp,N);//得到有效数字和指数
    if(Aexp==Bexp&&Atemp==Btemp)//有效数字和指数均相等
        cout<<"YES 0."<<Atemp<<"*10^"<<Aexp;//两数相等，输出YES和科学计算法表示的字符串
    else//否则输出NO和科学计算法表示的字符串
        cout<<"NO 0."<<Atemp<<"*10^"<<Aexp<<" 0."<<Btemp<<"*10^"<<Bexp;
    return 0;
}
*/ 

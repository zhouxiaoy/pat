#include<iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int sum[1000000];
int main(){
	long long n,l,r;
	scanf("%lld %lld %lld",&n,&l,&r);
	long long sum = r-l + 1;
	long long a = (long)sqrt(l-1);
	long long b = (long)sqrt(r);
	cout<<sum-(b-a);
	return 0;
	/*
	由题意得，所有光源的初始状态是关闭的，
	若要想使其最终是打开的状态，那么必须
	要经过奇数次这样的操作，而操作的次数
	其实就是光源的约数个数。因为没有”1
	的倍数进行的操作“，所以约数要减去1，
	即如果编号为n的光源，其有偶数个约数，
	那么最终这个光源是打开的。 已知完全
	平方数有奇数个约数，非完全平方数有
	偶数个约数。（因为如果一个数x不是
	完全平方数，那么其约数一定是成对出
	现的，即一定有偶数个约数；而完全平方
	数，除去哪偶数个约数外，还有一个完全
	平方根，那么“偶+1=奇“） 那么问题的
	答案就是给定区间[L,R]的非完全平方数的
	个数，区间[L,R]内的完全平方数的个数用
	A表示，非完全平方数的个数用B表示，则有
	B =（R-L+1) - A 。 对于给定的数M，[1,M]
	内的其完全平方数有(int)sqrt(M)。
	则A=(int)sqrt(R)-(int)sqrt(L-1) 
	最终问题的答案就是（R-L+1)-((long)sqrt(R)-(long)sqrt(L-1))
	*/ 
} 

#include <iostream>
#include <cmath>
 using namespace std;
 int main(){
 	
 	for(double i=2.000001;i<3.0;i+=0.000001){
 		if(pow(i,i)>10){
 			cout<<i;
 			break;
 		}
 	}
 	//ÑéÖ¤ 
 	/*
 	double a=2.50619;
 	double b=2.50618;
 	cout<<pow(a,a)<<endl;
 	cout<<pow(b,b);
 	*/
 	return 0;
 }

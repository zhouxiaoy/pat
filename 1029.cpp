#include <iostream>
#include<string>
#include<cctype>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int newhash[128] = {0};
	string str1;
	string str2;
	cin >> str1 >> str2;
	for(int i = 0;i < str2.size();i++){
		newhash[toupper(str2[i])] = 1;
	}
	for(int i = 0;i < str1.size();i++){
		if(!newhash[toupper(str1[i])]){
			cout << (char)toupper(str1[i]);
			newhash[toupper(str1[i])] = 1;
		}
	}
	return 0;
}

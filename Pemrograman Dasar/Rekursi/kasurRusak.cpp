#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string str){
	int len = str.size();
	char sub[100] = str[0:len];
	return ((str[0] == str[len-1]) && (isPalindrome(sub)))
}

int main(){
	string str;
	
	cin >> str;
	
	if (isPalindrome(str)){
		cout << "YA" << endl;
	} else {
		cout << "BUKAN" << endl;
	}
}

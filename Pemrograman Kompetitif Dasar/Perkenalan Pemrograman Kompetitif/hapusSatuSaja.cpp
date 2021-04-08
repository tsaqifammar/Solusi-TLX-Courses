#include<iostream>
#include<cmath>
using namespace std;

string solusi(string s1, string s2){
	int len1 = s1.size(), len2 = s2.size();
	if (len1 <= len2){
		return "Wah, tidak bisa :(";
	}
	int i1 = 0, i2 = 0;
	int beda = 0;
	while (i1 < len1 && i2 < len2 && beda <= 1){
		if (s1[i1] == s2[i2]){
			i1++;
			i2++;
		} else {
			i1++;
			beda++;
		}
	}
	if (beda > 1){
		return "Wah, tidak bisa :(";
	} 
	return "Tentu saja bisa!";
}

int main(){
	string s1, s2;
	
	cin >> s1;
	cin >> s2;
	cout << solusi(s1, s2) << endl;
}

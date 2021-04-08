#include<bits/stdc++.h>
using namespace std;

string solusi(string s, string x){
	int len = s.size();
	int len2 = x.size();
	int posAs = s.find_first_of("*");
	string jawaban = "";
	
	int i = len-1, j = len2 -1;
	bool ea = true;
	if (len2 < len - 1){
		ea = false;
	} else {
		while(i != posAs){
			if (s[i] != x[j]) {
				ea = false; break;
			}
			i--; j--;
		}
		i = 0; j = 0;
		while(i != posAs){
			if (s[i] != x[j]) {
				ea = false; break;
			}
			i++; j++;
		}
	}
		
	jawaban = ((ea) ? x : "");
	
	return jawaban;
}

int main(){
	string s;
	cin >> s;
	int t;
	cin >> t;
	while(t--){
		string x;
		cin >> x;
		string hasil = solusi(s, x);
		cout << ((hasil != "") ? hasil + "\n" : "");
	}
	return 0;
}

#include<iostream>
#include<string>
using namespace std;

int main(){
	string s1, s2;
	
	cin >> s1 >> s2;
	
	bool ada = true;
	int yesNo[100];
	
	while(ada){
		ada = false;
		int len1 = s1.size();
		int len2 = s2.size();
		for (int i = 0; i < len1-len2+1; i++){
			if (s1.substr(i, len2) == s2) {
				s1.erase(i, len2);
				ada = true;
				break;
			}
		}
	}
	cout << s1 << endl;
}

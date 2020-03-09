#include<iostream>
using namespace std;

int main(){
	string str;
	int d;
	cin >> str;
	cin >> d;
	
	int len = str.size();
	for (int i = 0; i < len; i++){
		if (int(str[i]) + d <= 122){
			str[i] += d;
		} else {
			str[i] = (str[i] + d)%122 + 96;
		}
	}
	cout << str << endl;
}

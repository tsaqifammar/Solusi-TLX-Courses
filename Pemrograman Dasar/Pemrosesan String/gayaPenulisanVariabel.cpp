#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;
	
	cin >> str;
	
	int len = str.size();
	
	for (int i = 0; i < len; i++){
		if (str[i] == '_'){
			str.erase(i, 1);
			str[i] -= 32;
			len--;
		} else if (str[i] >= 65 && str[i] <= 90){
			str.insert(i, "_");
			str[i+1] += 32;
			len++;
		}
	}
	cout << str << endl;
}

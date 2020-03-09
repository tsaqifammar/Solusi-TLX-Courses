#include<iostream>
#include<cstring>
using namespace std;

int main(){
	char s[101];
	scanf("%s", s);
	for (int i = 0; i < strlen(s); i++){
		if ((s[i] <= 90) && (s[i] >= 65)){
			s[i] += 32; 
		} else if ((s[i] <= 122) && (s[i] >= 97)) {
			s[i] -= 32;
		}
	}
	cout << s << endl;
	return 0;
}

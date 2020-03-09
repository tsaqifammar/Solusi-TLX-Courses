#include<iostream>
#include<cstdio>
using namespace std;

char str[1000];

const char* toBiner(int n){
	int x;
	if (n == 1){
		return "1";
	}
	if (n%2 == 1){
		x = 1;
	} else {
		x = 0;
	}
	const char* y;
	y = toBiner(n/2);
	sprintf(str, "%s%d", y, x);
	return str;
}

int main(){
	int n;
	cin >> n;
	
	cout << toBiner(n) << endl;
}

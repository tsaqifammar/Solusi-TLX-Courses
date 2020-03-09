#include<iostream>
using namespace std;

void print(int n){
	if (n == 1){
		cout << "*" << endl;
	} else {
		print(n-1);
		for (int i = 0; i < n; i++){
			cout << "*";
		}
		cout << endl;
		print(n-1);
	}
}

int main(){
	int n;
	cin >> n;
	
	print(n);
}

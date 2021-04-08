#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int kpk(int x, int y){
	int gcd = abs(__gcd(x, y));
	return x*y/gcd;
}

int main(){
	int t;
	int kpkNow;
	cin >> t;
	cin >> kpkNow;
	for (int i = 1; i < t; i++){
		int x;
		cin >> x;
		kpkNow = kpk(kpkNow, x);
	}
	cout << kpkNow << endl;
}

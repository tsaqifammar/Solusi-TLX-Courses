#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

char buffer[1000];

bool isPrime (int x) {
	for (int i = 2; i <= sqrt(x); i++){
		if (x%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int n, x;
	int tambah, retVal, ketemu;
	cin >> n;
	ketemu = 1;
	for (int i = 2; i <= n; i++){
		if (isPrime(i)){
			x = n;
			tambah = 0;
			while (x%i == 0){
				tambah++;
				x /= i;
			}
			if (tambah >= 1){
				if (ketemu == 1) {
					ketemu++;
					if (tambah == 1){
						retVal = sprintf(buffer, "%d", i);
					} else if (tambah > 1){
						retVal = sprintf(buffer, "%d^%d", i, tambah);
					}
				} else {
					if (tambah == 1){
						retVal = sprintf(buffer, "%s x %d", buffer, i);
					} else if (tambah > 1){
						retVal = sprintf(buffer, "%s x %d^%d", buffer, i , tambah);
					}
				}
			}
		}
	}
	cout << buffer << endl;
	return 0;
}

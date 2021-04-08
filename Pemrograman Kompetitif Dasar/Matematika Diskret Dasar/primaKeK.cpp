#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
int p[MAXN];
vector<long long> prime;
void generatePrime(){
	for (int i = 0; i < MAXN; i++){
		p[i] = i+1;
	}
	
	for (int i = 2; i*i <= MAXN; i++){
		if (p[i-1] == i){
			for (int j = i*i; j <= MAXN; j += i){
				p[j-1] = i;
			}
		}
	}
	for (int i = 2; i < MAXN; i++){
		if (p[i-1] == i) {
			prime.push_back(i);
		}
	}
}

int nthPrime(int n){
	return prime[n-1];
}

int main(){
	generatePrime();
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		cout << nthPrime(x) << "\n";
	}
	return 0;
}

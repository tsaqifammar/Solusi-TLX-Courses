#include "bits/stdc++.h"
using namespace std;

using ll = long long;

ll powmod(ll a, ll b, ll n){
	a %= n;
	if (a == 0) return 0;
	ll ans = 1;
	while(b > 0){
		if (b & 1) ans = (ans*a)%n;
		a = (a * a) % n;
		b /= 2;
	}
	return ans;
}

// a^b^c = (((a^b)^b)^b)^b...)^b    c times of ^b's

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	ll a, b, c, n;
	cin >> a >> b >> c >> n;
	ll hasil = a;
	for (int i = 0; i < c; i++)
		hasil = powmod(hasil,b,n);
	cout << hasil + 1 << '\n';
}

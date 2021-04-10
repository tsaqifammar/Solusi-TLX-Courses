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

ll pow3(ll a, ll b, ll c, ll n){
	if (a == 0) return 0;
	if (a == 1 && b == 0) return 1;
	if (b == 1 && c == 0) return (a % n);
	if (c == 1) return powmod(a,b,n);
	return powmod(pow3(a,b,c-1,n), b, n);
}

// a^b^c = a^(b^(c-1) * b) = (a^b^(c-1))^b

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	ll a, b, c, n;
	cin >> a >> b >> c >> n;
	cout << pow3(a,b,c,n) + 1 << '\n';
}

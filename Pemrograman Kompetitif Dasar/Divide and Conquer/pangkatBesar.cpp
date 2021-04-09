#include "bits/stdc++.h"
using namespace std;

using ll = long long;

bool over = false;

ll powmod(ll a, ll b, ll p){
	a %= p;
	if (a == 0) return 0;
	ll ans = 1;
	while(b > 0){
		if (b & 1){
			ans = ans*a;
			if (ans >= p){
				ans %= p;
				over = true;
			}
		}
		a = (a * a);
		b /= 2;
		if (b > 0 && a >= p){
			a %= p;
			over = true;
		}
	}
	return ans;
}

string makeSixDigit(ll x){
	string strX = to_string(x);
	while(strX.size() < 6)
		strX = '0' + strX;
	return strX;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	ll a, b;
	cin >> a >> b;
	ll ans = powmod(a,b,1000000);
	if (!over)
		cout << ans << '\n';
	else
		cout << makeSixDigit(ans) << '\n';
}

/*
ll powmod(ll a, ll b, ll p){
	a %= p;
	if (a == 0) return 0;
	ll ans = 1;
	while(b > 0){
		if (b & 1) ans = (ans*a)%p;
		a = (a * a) % p;
		b /= 2;
	}
	return ans;
}
*/

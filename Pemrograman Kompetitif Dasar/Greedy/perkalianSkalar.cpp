#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n;
	cin >> n;
	ll a[n], b[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(a, a+n);
	sort(b, b+n, greater<>());
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += a[i]*b[i];
	cout << ans << '\n';
}

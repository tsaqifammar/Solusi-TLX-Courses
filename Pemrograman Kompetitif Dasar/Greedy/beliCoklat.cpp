#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n;
	ll d;
	cin >> n >> d;
	pll arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr+n);
	ll cnt = 0, k;
	for (int i = 0; i < n; i++){
		if (d < arr[i].first)
			break;
		k = min(d/arr[i].first, arr[i].second);

		d -= k*arr[i].first;
		cnt += k;
	}
	cout << cnt << '\n';
}

// take the cheapest ones first

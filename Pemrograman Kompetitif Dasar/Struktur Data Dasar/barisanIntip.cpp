#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n;
	cin >> n;
	// stack of {Hi,Ai}'s
	stack<pair<ll,ll>> st;

	ll h, a, sum = 0;
	for (int i = 0; i < n; i++){
		cin >> h;

		a = 1;
		while(!st.empty() && st.top().first <= h){
			a += st.top().second;
			st.pop();
		}
		st.push({h,a});
		sum += a;
	}
	cout << sum << '\n';
}

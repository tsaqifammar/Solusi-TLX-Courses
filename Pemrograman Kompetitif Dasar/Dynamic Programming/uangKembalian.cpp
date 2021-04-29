#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n, k;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> k;

	// dp[x] = minimum amount of coin that sums up to x.
	vector<int> dp(k+1, 50000);
	dp[0] = 0;
	for (int total = 0; total <= k; total++)
		for (int i = 0; i < n; i++)
			if (total - arr[i] >= 0)
				dp[total] = min(dp[total], dp[total - arr[i]] + 1);
	cout << dp[k] << '\n';
}

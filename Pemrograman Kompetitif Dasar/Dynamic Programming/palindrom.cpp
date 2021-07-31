#include "bits/stdc++.h"
using namespace std;

string s;
int dp[50][50]; // dp[L][R] = longPal(s[L...R])

int longPal(int L, int R){
	if (dp[L][R] != 0) return dp[L][R];
	if (L == R) {
		return 1;
	} else if (R-L == 1) {
		if (s[L] == s[R]) return 2;
		return 1;
	}

	if (s[L] == s[R])
		return 2 + longPal(L+1, R-1);
	return (dp[L][R] = max(longPal(L+1, R), longPal(L, R-1)));
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t, n;
	cin >> t;
	while(t--){
		cin >> s;
		n = s.size();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dp[i][j] = 0;
		cout << longPal(0, n-1) << '\n';
	}
}

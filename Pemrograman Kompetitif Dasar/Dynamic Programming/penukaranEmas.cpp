#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int solve(int n){
    int dp[n+1] = {};
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = max(i, dp[i/2] + dp[i/3] + dp[i/4]);
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    cout << solve(n) << '\n';
}

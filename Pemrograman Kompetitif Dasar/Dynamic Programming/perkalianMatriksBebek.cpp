#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pll;
#define fi first
#define se second

/*

dp[L][R] = multiply matrices in the range [L, R]
- for every range [L, R], try every split point i (L <= i < R)
- find dp[L][R] by comparing the results from combining left ([L,i]) and right ([i+1,R]) for every split

*/

const int MOD = 26101991, MAX_N = 100;
const ll INF = 1e18 + 5;

pll mat[MAX_N];
int n;

ll add(ll a, ll b) { return (a + b) % MOD; }
ll mul(ll a, ll b) { return (a * b) % MOD; }

void solve(int q) {
    ll dp[n][n][3];

    // initialize
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                dp[i][i][0] = 0, dp[i][i][1] = dp[i][i][2] = 1;
            else
                dp[i][j][0] = INF, dp[i][j][1] = dp[i][j][2] = 0;

    for (int len = 2; len <= n; len++) {
        for (int L = 0; L + len - 1 < n; L++) {
            int R = L + len - 1;
            for (int split = L; split < R; split++) {
                ll cost = dp[L][split][0] + dp[split+1][R][0] + (mat[L].fi * mat[split].se * mat[R].se);
                if (cost < dp[L][R][0]) {
                    dp[L][R][0] = cost;
                    dp[L][R][1] = mul(dp[L][split][1], dp[split+1][R][1]);
                } else if (cost == dp[L][R][0]) {
                    dp[L][R][1] = add(dp[L][R][1], mul(dp[L][split][1], dp[split+1][R][1]));
                }

                dp[L][R][2] = add(dp[L][R][2], mul(dp[L][split][2], dp[split+1][R][2]));
            }
        }
    }

    cout << dp[0][n-1][q] << '\n';
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    cin >> mat[0].fi;
    for (int i = 1; i < n; i++)
        cin >> mat[i].fi, mat[i-1].se = mat[i].fi;
    cin >> mat[n-1].se;

    int q;
    cin >> q;
    solve(q-1);
}

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

/*

Notice that, for bigger x, the resulting sum is also bigger (monotonic).
We can use binary search to find the lower and upper bound for x
such that the resulting sum is equals to M.

*/

void solve() {
    ll n, m;
    cin >> n >> m;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    auto getSum = [&](ll x) -> ll {
        ll sum = 0;
        for (int i = 0; i < n; i++)
            sum += x/a[i];
        return sum;
    };

    auto searchMax = [&](ll total) -> ll {
        ll L = 0, R = (1LL << 62), maxX = 0;
        while (L <= R) {
            ll mid = (L + R)/2, sum = getSum(mid);
            if (sum <= total) {
                maxX = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        return maxX;
    };

    ll ub = searchMax(m);
    ll lb = searchMax(m - 1);
    cout << ub - lb << '\n';
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
}

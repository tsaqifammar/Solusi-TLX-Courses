#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m, n;
    cin >> m;
    int a[m];
    for (int i = 0; i < m; i++)
        cin >> a[i];
    cin >> n;

    sort(a, a + m);

    int groupSize = m/n, rem = m % n;

    // we can distribute the extra/remaining 1's over the n groups
    // brute force: try every distribution, and check if it satisfies
    // if extra[i] = 1, then group i has the size of groupSize + 1
    int extra[n] = {0};
    for (int i = n-1; rem > 0; i--, rem--)
        extra[i] = 1;

    do {
        int ans[n - 1];
        bool sat = true;
        for (int i = 0, L = 0; i < n-1; i++) {
            L += groupSize + extra[i];
            if (a[L] == a[L-1]) {
                sat = false;
                break;
            }
            ans[i] = a[L];
        }

        if (sat) {
            for (int i = 0; i < n-1; i++)
                cout << ans[i] << " \n"[i == n-1];
            return;
        }
    } while (next_permutation(extra, extra + n));
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
}

#include <bits/stdc++.h>
using namespace std;

/*

This solution is definitely not the easiest. I suggest looking at others' solutions instead.

Idea: similar to how DSU/Union-find works.

Note: uncommenting the loop on line 61-62 might help for understanding.

*/

const int MAX_N = 1e5;
int w[MAX_N], idx[MAX_N], Parent[MAX_N], Left[MAX_N], Right[MAX_N];
int n;

int par(int i) {
    if (i == Parent[i]) return i;
    return Parent[i] = par(Parent[i]);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> w[i];

    iota(idx, idx + n, 0);
    sort(idx, idx + n, [&](int i, int j) {
        return w[i] < w[j];
    });

    for (int i = 0; i < n; i++)
        Parent[i] = Left[i] = Right[i] = i;

    int cnt = 0, total = 0;
    for (int i = 1; cnt < n && i < n; i++) {
        int cur = idx[i];
        if (Parent[cur] != cur) continue;
        if (cur - 1 >= 0) {
            int L = par(cur - 1);
            while (L >= 0 && w[L] <= w[cur]) {
                cnt++, total += w[cur];
                Parent[L] = cur;
                Left[cur] = Left[L];
                if (Left[cur] - 1 < 0) break;
                L = par(Left[cur] - 1);
            }
        }
        if (cur + 1 < n) {
            int R = par(cur + 1);
            while (R < n && w[R] <= w[cur]) {
                cnt++, total += w[cur];
                Parent[R] = cur;
                Right[cur] = Right[R];
                if (Right[cur] + 1 >= n) break;
                R = par(Right[cur] + 1);
            }
        }

        // for (int j = 0; j < n; j++)
        //     cout << w[par(j)] << " \n"[j == n-1];
    }

    cout << total << '\n';
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
}

#include "bits/stdc++.h"
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

const int nmax = 200;
const int INF = 1e9;
int n, m, q;
vvi w(nmax, vi(nmax, INF));
vvi dist;

void floyd_warshall(){
    dist = w;

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main(){
    for (int i = 0; i < nmax; i++)
        w[i][i] = 0;

    cin >> n >> m >> q;
    int x, y, z;
    for (int i = 0; i < m; i++){
        cin >> x >> y >> z;
        x--; y--;
        w[x][y] = min(z, w[x][y]);
        w[y][x] = min(z, w[y][x]);
    }
    floyd_warshall();

    int prev, total = 0;
    for (int i = 0; i < q; i++){
        cin >> x;
        x--;
        if (i != 0)
            total += dist[x][prev];
        prev = x;
    }
    cout << total << '\n';
}

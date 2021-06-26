#include "bits/stdc++.h"
using namespace std;

using pii = pair<int,int>;

int n, e;
const int INF = 1000000000;
vector<vector<pii>> g;
vector<int> d;

void dijkstra(int s) {
    d.assign(n, INF);

    d[s] = 0;
    set<pii> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : g[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
}

int main(){
    int from, to;
    cin >> n >> e >> from >> to;
    from--; to--;
    g.assign(n, {});

    int x, y, w;
    for (int i = 0; i < e; i++){
        cin >> x >> y >> w;
        g[x-1].push_back({y-1,w});
        g[y-1].push_back({x-1,w});
    }
    dijkstra(from);
    cout << d[to] << '\n';
}

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

/*

BFS, but track 2 values for the distances to every node
dist[x][0] = shortest distance to x without taking a toll road
dist[x][1] = shortest distance to x with taking a toll road

*/

void solve() {
    int N, L, T, src, target;
    cin >> N >> L >> T >> src >> target, src--, target--;

    vector<vector<pair<int, bool>>> adj(N);

    int x, y;
    for (int i = 0; i < L; i++) {
        cin >> x >> y, x--, y--;
        adj[x].push_back({y, false});
        adj[y].push_back({x, false});
    }

    for (int i = 0; i < T; i++) {
        cin >> x >> y, x--, y--;
        adj[x].push_back({y, true});
        adj[y].push_back({x, true});
    }

    queue<pair<int, bool>> q; // {node, hasTakenToll}
    int vis[N] = {0}; // 0 = not yet visited, 1 = visited w/ toll, 2 = visited w/o toll
    vector<array<int,2>> dist(N, {INF, INF});

    q.push({src, false});
    vis[src] = 1;
    dist[src][0] = dist[src][1] = 0;

    while (!q.empty()) {
        auto [cur, hasTakenToll] = q.front();
        q.pop();

        for (auto [nxt, isToll] : adj[cur]) {
            if (hasTakenToll && !isToll && vis[nxt] == 0) {
                vis[nxt] = 1;
                dist[nxt][1] = dist[cur][1] + 1;
                q.push({nxt, true});
            } else if (!hasTakenToll) {
                if (isToll && vis[nxt] == 0) {
                    vis[nxt] = 1;
                    dist[nxt][1] = dist[cur][0] + 1;
                    q.push({nxt, true});
                } else if (!isToll && vis[nxt] != 2) {
                    vis[nxt] = 2;
                    dist[nxt][0] = dist[cur][0] + 1;
                    q.push({nxt, false});
                }
            }
        }
    }

    cout << min(dist[target][0], dist[target][1]) << '\n';
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
}

/*

7 5 3 7 5
1 2
1 6
1 7
2 3
3 6
4 6
5 6
6 7

*/

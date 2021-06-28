#include "bits/stdc++.h"
using namespace std;

using ll = long long;

struct edge {
    int a, b, cost;
};

int n, m, v;
vector<edge> e;
const int INF = 1000000000;
void belmann_ford(){
    vector<int> d (n, INF);
    d[v] = 0;
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;

        for (int j = 0; j < m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost) {
                    d[e[j].b] = max(-INF, d[e[j].a] + e[j].cost);
                    x = e[j].b;
                }
    }
    if (x != -1)
        cout << "Pak Dengklek tidak mau pulang\n";
    else if (d[n-1] == INF)
        cout << "Tidak ada jalan\n";
    else
        cout << d[n-1] << '\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t; cin >> t;
    while(t--){
        e.clear();
        cin >> n >> m;
        v = 0;
        int x, y, w;
        for (int i = 0; i < m; i++){
            cin >> x >> y >> w;
            e.push_back({x,y,w});
        }
        belmann_ford();
    }
}

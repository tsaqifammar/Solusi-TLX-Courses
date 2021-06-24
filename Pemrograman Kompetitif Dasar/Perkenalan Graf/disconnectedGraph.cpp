#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    int t; cin >> t;
    while(t--){
        int n, e, q, r;
        cin >> n >> e >> q >> r;
        pii edges[e];
        bool khusus[n] = {0};
        for (int i = 0; i < e; i++){
            cin >> edges[i].first >> edges[i].second;
            edges[i].first--, edges[i].second--;
        }
        int x;
        for (int i = 0; i < q; i++){ cin >> x; khusus[x-1] = 1; }
        for (int i = 0; i < r; i++){ cin >> x; edges[x-1].first = -1; }

        // build graph
        vector<vector<int>> g(n);
        for (pii p : edges){
            if (p.first != -1){
                g[p.first].push_back(p.second);
                g[p.second].push_back(p.first);
            }
        }

        // do dfs on each connected component, and count how many are special
        bool vis[n] = {0};
        ll ans = 0, sum = 0;
        for (int i = 0; i < n; i++){
            if (vis[i]) continue;

            stack<int> st;
            st.push(i);
            vis[i] = 1;
            int cnt = (khusus[i]);
            while(!st.empty()){
                int atas = st.top(); st.pop();
                for (int v : g[atas])
                    if (!vis[v]){
                        st.push(v);
                        vis[v] = 1;
                        if (khusus[v]) cnt++;
                    }
            }
            ans += sum*cnt;
            sum += cnt;
        }
        cout << ans << '\n';
    }
}

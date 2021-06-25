#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;

int n, k;

// Do a BFS where the nodes are the 1-n permutations. Permutation x is connected to
// permutation y, if you can get from x to y in 1 operation.

int bfs(vi arr){
    if (is_sorted(arr.begin(), arr.end())) return 0;
    // bfs
    queue<vi> q;
    map<vi, bool> vis;
    map<vi, int> dist;

    q.push(arr);
    vis[arr] = true;
    dist[arr] = 0;
    while(!q.empty()){
        vi top = q.front(); q.pop();
        for (int i = 0; i <= n-k; i++){
            vi temp = top;
            reverse(temp.begin()+i, temp.begin()+i+k);
            if (!vis[temp]){
                if (is_sorted(temp.begin(), temp.end()))
                    return dist[top] + 1;
                q.push(temp);
                vis[temp] = true;
                dist[temp] = dist[top] + 1;
            }
        }
    }
    return -1;
}

int main(){
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    cout << bfs(arr) << '\n';
}

#include "bits/stdc++.h"
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other){
        return weight < other.weight;
    }
};

int n, w;
vector<Edge> edges;
int cost = 0;

void MST(){
    vector<int> tree_id(n);
    for (int i = 0; i < n; i++)
        tree_id[i] = i;

    sort(edges.begin(), edges.end());

    for (Edge e : edges){
        if (tree_id[e.u] != tree_id[e.v]){
            cost += e.weight;

            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 0; i < n; i++){
                if (tree_id[i] == old_id)
                    tree_id[i] = new_id;
            }
        }
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> w;
            if (w != 0)
                edges.push_back({i, j, w});
        }
    }
    MST();
    cout << cost << '\n';
}

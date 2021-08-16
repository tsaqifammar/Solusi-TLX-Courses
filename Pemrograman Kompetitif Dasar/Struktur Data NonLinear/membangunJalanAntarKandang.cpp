#include "bits/stdc++.h"
using namespace std;

vector<int> par;

void init(int n){
    par.resize(n);
    for (int i = 0; i < n; i++)
        par[i] = i;
}

int find_representative(int x){
    if (par[x] == x) return x;
    par[x] = find_representative(par[x]);
    return par[x];
}

void join(int a, int b){
    a = find_representative(a);
    b = find_representative(b);
    par[a] = b;
}

bool check(int a, int b){
    int repA = find_representative(a), repB = find_representative(b);
    return (repA == repB);
}

int main(){
    int n, q;
    cin >> n >> q;

    init(n);

    int type, x, y;
    for (int i = 0; i < q; i++){
        cin >> type >> x >> y;
        x--, y--;
        if (type == 1)
            join(x, y);
        else
            cout << (check(x, y) ? "Y" : "T") << '\n';
    }
}

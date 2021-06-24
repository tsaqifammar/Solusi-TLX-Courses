#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int n, m;
string p, c;
map<string, vector<string>> g;
map<string, string> Prev;

void dfs(string s){
    for (string v : g[s]){
        Prev[v] = s;
        dfs(v);
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> p >> c;
        g[p].push_back(c);
    }
    string a, b;
    cin >> a >> b;
    dfs(a);
    dfs(b);

    // trace back path from a to b
    vector<string> ans;
    string temp = a;
    while(temp != "" && temp != b){
        ans.push_back(temp);
        temp = Prev[temp];
    }
    if (temp == ""){
        // if not found, reset, and trace back path from b to a
        ans.clear();
        temp = b;
        while(temp != "" && temp != a){
            ans.push_back(temp);
            temp = Prev[temp];
        }
        if (temp == "") cout << "TIDAK MUNGKIN\n";
        else {
            ans.push_back(a);
            reverse(ans.begin(), ans.end());
            for (string s : ans) cout << s << '\n';
        }
    } else {
        ans.push_back(b);
        reverse(ans.begin(), ans.end());
        for (string s : ans) cout << s << '\n';
    }
}

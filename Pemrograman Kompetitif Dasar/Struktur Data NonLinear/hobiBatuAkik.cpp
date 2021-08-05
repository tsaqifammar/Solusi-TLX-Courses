#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    priority_queue<int> pq;
    int n, cmd, x;
    cin >> n;
    while(n--){
        cin >> cmd;
        if (cmd == 1){
            cin >> x;
            pq.push(x);
        } else if (cmd == 2){
            cout << pq.top() << '\n';
        } else {
            pq.pop();
        }
    }
}

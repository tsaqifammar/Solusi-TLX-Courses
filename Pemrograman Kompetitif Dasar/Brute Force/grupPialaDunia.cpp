#include "bits/stdc++.h"
using namespace std;

using ll = long long;

vector<int> arr(5), tmpArr(5);
vector<pair<int,int>> rel = {{3,0}, {1,1}, {0,3}};
int n;

pair<int,int> findIdx(int k){
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++){
            if (cnt == k)
                return {i, j};
            cnt++;
        }
    return {0,0};
}

bool cek(int k){
    // if every relationship has been determined, check if tempArr == arr
    if (k == n*(n-1)/2)
        return (tmpArr == arr);

    auto [p1, p2] = findIdx(k);
    bool valid = false;
    for (int i = 0; i < 3; i++){
        tmpArr[p1] += rel[i].first;
        tmpArr[p2] += rel[i].second;
        valid |= cek(k+1);
        tmpArr[p1] -= rel[i].first;
        tmpArr[p2] -= rel[i].second;
    }
    return valid;
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (cek(0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

// generate every valid combination, and check if
// the input sequence is one of them.

// there are n*(n-1)/2 relationships
// for each of them, there are 3 possibilities
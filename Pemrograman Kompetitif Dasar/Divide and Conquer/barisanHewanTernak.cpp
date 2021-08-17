#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int n, q, y;
vector<int> arr;

int bin_search(int y){
    int L = 0, R = n-1;
    while(L < R){
        int mid = (L + R)/2;
        if (arr[mid] >= y){
            R = mid;
        } else {
            L = mid + 1;
        }
    }
    return L + 1;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    cin >> n;
    arr.resize(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (i != 0) arr[i] += arr[i-1];
    }

    cin >> q;
    while(q--){
        cin >> y;
        cout << bin_search(y) << '\n';
    }
}

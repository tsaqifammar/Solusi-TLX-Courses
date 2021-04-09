#include "bits/stdc++.h"
using namespace std;

using pii = pair<int,int>;

bool comp(pii a, pii b) { return (a.second < b.second); }

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n;
	cin >> n;
	pii arr[n];
	int x, y;
	for (int i = 0; i < n; i++){
		cin >> x >> y;
		arr[i].first = x;
		arr[i].second = x+y;
	}
	sort(arr, arr+n, comp);
	int prevFinish = arr[0].second, cnt = 1;
	for (int i = 1; i < n; i++){
		if (arr[i].first < prevFinish)
			continue;
		prevFinish = arr[i].second;
		cnt++;
	}
	cout << cnt << '\n';
}

// greedily take the ones that finish early

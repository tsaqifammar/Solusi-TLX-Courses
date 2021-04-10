#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n, m;
	cin >> n >> m;
	int bebek[n], shoes[m];
	for (int i = 0; i < n; i++)
		cin >> bebek[i];
	for (int i = 0; i < m; i++)
		cin >> shoes[i];
	sort(bebek,bebek+n);
	sort(shoes,shoes+m);

	int p1 = 0, p2 = 0, cnt = 0;
	while(p1 < n && p2 < m)
		if (shoes[p2] == bebek[p1] || shoes[p2] == bebek[p1]+1)
			p1++, p2++, cnt++;
		else if (shoes[p2] > bebek[p1]+1)
			p1++;
		else
			p2++;

	cout << cnt << '\n';
}
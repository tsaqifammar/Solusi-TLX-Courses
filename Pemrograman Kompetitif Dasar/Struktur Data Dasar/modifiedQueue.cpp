#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int q;
	cin >> q;
	deque<int> dq;
	int cnt = 0;
	bool arah = 0;
	while(q--){
		string s;
		cin >> s;
		if (s == "add"){
			int x, y;
			cin >> x >> y;
			cnt += y;
			for (int i = 0; i < y; i++)
				if (arah)
					dq.push_back(x);
				else
					dq.push_front(x);
			cout << cnt << '\n';
		} else if (s == "rev"){
			arah = !arah;
		} else {
			int y;
			cin >> y;
			cnt -= y;
			for (int i = 0; i < y; i++)
				if (arah){
					if (i == 0)
						cout << dq.front() << '\n';
					dq.pop_front();
				} else {
					if (i == 0)
						cout << dq.back() << '\n';
					dq.pop_back();
				}
		}
	}
}
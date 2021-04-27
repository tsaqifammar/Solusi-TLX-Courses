#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int q;
	cin >> q;
	stack<int> st;
	int modifier = 0, cnt = 0;
	int x, y;
	while(q--){
		string s;
		cin >> s;
		if (s == "add"){
			cin >> x >> y;
			cnt += y;
			for (int i = 0; i < y; i++)
				st.push(x - modifier);
			cout << cnt << '\n';
		} else if (s == "del") {
			cin >> y;
			cnt -= y;
			for (int i = 0; i < y; i++){
				if (i == 0)
					cout << st.top() + modifier << '\n';
				st.pop();
			}
		} else if (s == "adx"){
			cin >> x;
			modifier += x;
		} else {
			cin >> x;
			modifier -= x;
		}
	}
}

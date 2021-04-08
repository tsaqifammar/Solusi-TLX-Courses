#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n;
	cin >> n;
	deque<int> dq;
	for (int i = 0; i < n; i++){
		string s;
		int x;
		cin >> s;
		if (s == "push_back"){
			cin >> x;
			dq.push_back(x);
		} else if (s == "push_front"){
			cin >> x;
			dq.push_front(x);
		} else if (s == "pop_front"){
			dq.pop_front();
		} else {
			dq.pop_back();
		}
	}

	for (auto it = dq.begin(); it != dq.end(); ++it){
		cout << *it << '\n';
	}
}
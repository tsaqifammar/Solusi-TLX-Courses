#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n, t;
	cin >> n >> t;
	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n, greater<int>());
	int count = 0;
	int i = 0, sum = 0;
	while(sum <= t){
		sum += arr[i];
		count++;
		i++;
	}
	cout << count << '\n';
}
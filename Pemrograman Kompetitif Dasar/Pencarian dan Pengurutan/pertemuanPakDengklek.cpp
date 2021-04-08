#include<bits/stdc++.h>
using namespace std;

bool comp(string a, string b){
	int lenA = a.size(), lenB = b.size();
	if (lenA != lenB){
		return lenA < lenB;
	}
	return a < b;
}

int main(){
	int n;
	cin >> n;
	string arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n, comp);
	for (int i = 0; i < n; i++){
		cout << arr[i] << "\n";
	}
}

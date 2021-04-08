#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n >> n;
	int arr1[n][n], arr2[n][n];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> arr1[i][j];
		}
	}
	cin >> n >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> arr2[i][j];
		}
	}
	bool identik = true;
	for (int i = 0; i < n && identik; i++){
		for (int j = 0; j < n; j++){
			if (arr1[i][j] != arr2[i][j]){
				identik = false;
				break;
			}
		}
	}
	if (identik){
		cout << "identik\n";
		return 0;
	}
	identik = true;
	for (int i = 0; i < n && identik; i++){
		for (int j = 0; j < n; j++){
			if (arr1[i][j] != arr2[i][n-j-1]){
				identik = false;
				break;
			}
		}
	}
	if (identik){
		cout << "vertikal\n";
		return 0;
	}
	identik = true;
	for (int i = 0; i < n && identik; i++){
		for (int j = 0; j < n; j++){
			if (arr1[i][j] != arr2[n-i-1][j]){
				identik = false;
				break;
			}
		}
	}
	if (identik){
		cout << "horisontal\n";
		return 0;
	}
	identik = true;
	for (int i = 0; i < n && identik; i++){
		for (int j = 0; j < n; j++){
			if (arr1[i][j] != arr2[j][i]){
				identik = false;
				break;
			}
		}
	}
	if (identik){
		cout << "diagonal kanan bawah\n";
		return 0;
	}
	identik = true;
	for (int i = 0; i < n && identik; i++){
		for (int j = 0; j < n; j++){
			if (arr1[i][j] != arr2[n-j-1][n-i-1]){
				identik = false;
				break;
			}
		}
	}
	if (identik){
		cout << "diagonal kiri bawah\n";
		return 0;
	}
	cout << "tidak identik\n";
}
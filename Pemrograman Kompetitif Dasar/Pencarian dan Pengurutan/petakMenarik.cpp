#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	int arr[n][m];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	for (int j = 0; j < m; j++){
		for (int i = 0; i < n; i++){
			int x;
			int atas = ((i-1 >= 0)?arr[i-1][j]:1);
			int bawah = ((i+1 < n)?arr[i+1][j]:1);
			int kiri = ((j-1 >= 0)?arr[i][j-1]:1);
			int kanan = ((j+1 < m)?arr[i][j+1]:1);
			x = atas*bawah*kanan*kiri;
			if (x == k){
				cout << i+1 << " " << j+1 << "\n";
				return 0;
			}
		}
	}
	cout << "0 0\n";
	return 0;
}

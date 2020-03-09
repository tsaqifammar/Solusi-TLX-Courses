#include<iostream>
using namespace std;

int main(){
	int n, m, p;

	cin >> n >> m >> p;

	int arr1[m][n], arr2[p][m], arr3[n][p];
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr1[j][i];
		}
	}
	for (int i = 0; i < m; i++){
		for (int j = 0; j < p; j++){
			cin >> arr2[j][i];
		}
	}

	for (int i = 0; i < p; i++){
		for (int j = 0; j < n; j++){
			int sum = 0;
			for (int k = 0; k < m; k++){
				sum += arr1[k][j] * (arr2[i][k]);
			}
			arr3[i][j] = sum;
		}
	}

	if ((n != 0) && (m != 0) && (p != 0)){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < p; j++){
				if (j < (p-1)){
					cout << arr3[j][i] << " ";
				} else {
					cout << arr3[j][i] << endl;
				}
			}
		}
	}
}

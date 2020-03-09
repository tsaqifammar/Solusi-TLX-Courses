#include<iostream>
using namespace std;

int main(){
    int m, n;

    cin >> m >> n;
    int arr[m][n];

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = m-1; j >= 0; j--){
            if (j > 0){
            	cout << arr[j][i] << " ";
			} else {
				cout << arr[j][i] << endl;
			}
        }
    }
}

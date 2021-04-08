#include<bits/stdc++.h>
using namespace std;


int m, n;
char arr[25][25];
int visited[25][25];
char val;

int hitung(int i, int j){
	int infected = 1;
	if (i-1 >= 0 && arr[i-1][j] == val && visited[i-1][j] == 0){
		visited[i-1][j] = 1;
		infected += hitung(i-1, j);
	}
	if (i+1 < m && arr[i+1][j] == val && visited[i+1][j] == 0){
		visited[i+1][j] = 1;
		infected += hitung(i+1, j);
	}
	if (j-1 >= 0 && arr[i][j-1] == val && visited[i][j-1] == 0){
		visited[i][j-1] = 1;
		infected += hitung(i, j-1);
	}
	if (j+1 < n && arr[i][j+1] == val && visited[i][j+1] == 0){
		visited[i][j+1] = 1;
		infected += hitung(i, j+1);
	}

	return infected;
}

void boom(int i, int j){
	if (arr[i][j] == '.') return;
	arr[i][j] = '.';
	if (i-1 >= 0 && arr[i-1][j] == val && visited[i-1][j] == 0){
		visited[i-1][j] = 1;
		boom(i-1, j);
	}
	if (i+1 < m && arr[i+1][j] == val && visited[i+1][j] == 0){
		visited[i+1][j] = 1;
		boom(i+1, j);
	}
	if (j-1 >= 0 && arr[i][j-1] == val && visited[i][j-1] == 0){
		visited[i][j-1] = 1;
		boom(i, j-1);
	}
	if (j+1 < n && arr[i][j+1] == val && visited[i][j+1] == 0){
		visited[i][j+1] = 1;
		boom(i, j+1);
	}
}

int main(){
	cin >> m >> n;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	int max = -1, maxI = 0, maxJ = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){

			for (int k = 0; k < m; k++)
				for (int l = 0; l < n; l++)
					visited[k][l] = 0;

			visited[i][j] = 1; val = arr[i][j];
			int count = hitung(i, j);
			if (count > max) {
				max = count;
				maxI = i;
				maxJ = j;
			}
		}
	}
	for (int k = 0; k < m; k++)
		for (int l = 0; l < n; l++)
			visited[k][l] = 0;
	visited[maxI][maxJ] = 1; val = arr[maxI][maxJ];
	boom(maxI, maxJ);

	for (int i = m-2; i >= 0; i--){
		for (int j = n-1; j >= 0; j--){
			int k = i, l = j;
			while(arr[k+1][l] == '.' && k < m-1){
				swap(arr[k][l], arr[k+1][l]);
				k++;
			}
		}
	}
		
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cout << arr[i][j] << ((j < n-1) ? " " : "");
		}
		cout << endl;
	}
}


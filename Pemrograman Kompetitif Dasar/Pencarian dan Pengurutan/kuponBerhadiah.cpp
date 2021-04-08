#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n, x;
	cin >> n >> x;
	int mat[n];
	for (int i = 0; i < n; i++){
		cin >> mat[i];	
	}
	int idxMin = 0;
	for (int i = 1; i < n; i++){
		if (abs(mat[i]-x) < abs(mat[idxMin]-x)){
			idxMin = i;
		} else if (abs(mat[i]-x) == abs(mat[idxMin]-x)){
			if (mat[idxMin] > mat[i]){
				idxMin = i;
			}
		}
	}
	cout << mat[idxMin] << endl;
}

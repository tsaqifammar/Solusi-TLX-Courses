#include<iostream>
#include<string>
#include<cmath>
using namespace std;

string jawaban[128*128];
int n;
int pow2 = 1;
int mat[128][128];

void doStuff(){
	for (int i = 0; i < n; i++){
		int len = jawaban[i].size();
		int x = 0, y = 0, k = pow2;
		int lenTemp = k;
		k /= pow(2, len-1);
		for (int j = 1; j < len; j++){
			if (jawaban[i][j] == '1'){
				 y += lenTemp/2;
			} else if (jawaban[i][j] == '2'){
				 x += lenTemp/2;
			} else if (jawaban[i][j] == '3'){
				x += lenTemp/2;
				y += lenTemp/2;
			}
			lenTemp /= 2;
		}
		for (int j = x; j < x + k; j++){
			for (int m = y; m < y + k; m++){
				mat[j][m] = 1;
			}
		}
	}
}

int main(){
	for (int i = 0; i < 128; i++){
		for (int j = 0; j < 128; j++){
			mat[i][j] = 0;
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> jawaban[i];
	}
	int N, M;
	cin >> N >> M;
	int maxRc = max(N, M);
	
	while (pow2 < maxRc){
		pow2 *= 2;
	}
	
	doStuff();
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (j < M-1){
				cout << mat[i][j] << " ";
			} else {
				cout << mat[i][j] << "\n";
			}
		}
	}
	return 0;
}

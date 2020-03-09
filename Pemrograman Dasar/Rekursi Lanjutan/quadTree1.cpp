#include<iostream>
#include<string>
using namespace std;

int mat[128][128];
string jawaban[128*128];
int nJawaban;

bool isHomogen(int r, int c, int k){
	int val = mat[r][c];
	for (int i = r; i < r + k; i++){
		for (int j = c; j < c + k; j++){
			if (mat[i][j] != val){
				return false;
			}
		}
	}
	return true;
}

void quadTree(int r, int c, int k, string s){
	if (isHomogen(r,c,k)){
		if (mat[r][c] == 1){
			jawaban[nJawaban] = "1" + s;
			nJawaban++;
		}
	} else {
		quadTree(r, c, k/2, s + "0");
		quadTree(r, c + (k/2), k/2, s + "1");
		quadTree(r + (k/2), c, k/2, s + "2");
		quadTree(r + (k/2), c + (k/2), k/2, s + "3");
	}
	
}

int main(){
	int r, c;
	cin >> r >> c;
	
	int maxRc = max(r, c);
	int pow2 = 1;
	while (pow2 < maxRc){
		pow2 *= 2;
	}
	
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cin >> mat[i][j];
		}
	}
	
	quadTree(0, 0, pow2, "");
	cout << nJawaban << endl;
	for (int i = 0; i < nJawaban; i++){
		cout << jawaban[i] << "\n";
	}
}

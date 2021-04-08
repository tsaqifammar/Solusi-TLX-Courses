#include<iostream>
using namespace std;

int R, C;
int mat[20][8];

int ilangin(){
	bool fullLine;
	int xDeepest = -1;
	for (int i = 0; i < R; i++){
		fullLine = true;
		if (mat[i][0] == 1){
			for (int j = 0; j < C; j++){
				if (mat[i][j] == 0){
					fullLine = false;
					break;
				}
			}
			if (fullLine == true){
				for (int j = 0; j < C; j++){
					mat[i][j] = 0;
					xDeepest = i;
				}	
			}
		}
	}
	return xDeepest;
}

void doStuff(){
	int x = ilangin();
	while (x != -1){
		for (int i = x-1; i >= 0; i--){
			for (int j = 0; j < C; j++){
				if (mat[i][j] == 1){
					int absis = i;
					do{
						mat[absis][j] = 0;
						mat[absis + 1][j] = 1;
						absis++;
					} while(!(mat[absis+1][j] == 1 || absis >= R));
				}
			}
		}
		x = ilangin();
	}
}

int main(){
	cin >> R >> C;
	string matTemp[R];
	for (int i = 0; i < R; i++){
		cin >> matTemp[i];
	}
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			mat[i][j] = matTemp[i][j] - 48;
		}
	}
	doStuff();
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cout << mat[i][j];
		}
		cout << endl;
	}
}

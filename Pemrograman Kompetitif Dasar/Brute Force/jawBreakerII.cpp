#include<iostream>
using namespace std;

int terpilih;
int count = 1;
int M, N;
int mat[25][25];
char matc[25][25];

void solusi(int x, int y){
    if (x != 0 && matc[x-1][y] != '*'){
        if (mat[x-1][y] == terpilih){
        	matc[x-1][y] = '*';
            count++;
            solusi(x-1, y);
        }
    }
    if (y != 0 && matc[x][y-1] != '*'){
        if (mat[x][y-1] == terpilih){
        	matc[x][y-1] = '*';
            count++;
            solusi(x, y-1);
        }
    }
    if (x != 24 && matc[x+1][y] != '*'){
        if (mat[x+1][y] == terpilih){
        	matc[x+1][y] = '*';
            count++;
            solusi(x+1, y);
        }
    }
    if (y != 24 && matc[x][y+1] != '*'){
        if (mat[x][y+1] == terpilih){
        	matc[x][y+1] = '*';
            count++;
            solusi(x, y+1);
        }
    }
}

int main(){
    cin >> M >> N;
    
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            cin >> mat[i][j];
        }
    }
	int maxo = 0;
    for (int x = 0; x < M; x++){
    	for (int y = 0; y < N; y++){
    		// reset matriks bintang (sudah dikunjungi)
    		for (int i = 0; i < M; i++){
    			for (int j = 0; j < N; j++){
    				matc[i][j] = '-';
				}
			}
		    terpilih = mat[x][y];             
		    matc[x][y] = '*';
		    solusi(x, y);
		    if (count > maxo){
		    	maxo = count;
			}
			count = 1;
		}
	}
    cout << maxo*(maxo-1) << endl;
    
    return 0;
}

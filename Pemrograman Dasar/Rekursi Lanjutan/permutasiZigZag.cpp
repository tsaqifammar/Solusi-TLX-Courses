#include<iostream>
using namespace std;

int N;
int catat[10];
bool pernah[10];

bool zigzag(){
	for (int i = 1; i < N-1; i++){
		bool tengahKecil = (catat[i] < catat[i-1] && catat[i] < catat[i+1]);
		bool tengahBesar = (catat[i] > catat[i-1] && catat[i] > catat[i+1]);
		if (!tengahKecil && !tengahBesar){
			return false;
		}
	}
	return true;
}

void tulis(int kedalaman){
	if (kedalaman >= N){
		if (zigzag()){
			for (int i = 0; i < N; i++){
				printf("%d", catat[i]);
			}
			cout << endl;
		}
	} else {
		for (int i = 1; i <= N; i++){
			if (!pernah[i]){
				pernah[i] = true;
				catat[kedalaman] = i;
				tulis(kedalaman+1);
				pernah[i] = false;
			}
		}
	}
}

int main(){
	int kedalaman = 0;
	
	cin >> N;
	
	tulis(kedalaman);
	
}

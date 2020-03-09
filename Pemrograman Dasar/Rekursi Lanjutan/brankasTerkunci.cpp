#include<iostream>
using namespace std;

int N, len;
int catat[15];
void solusi(int awal){
	if (awal == 0){
		for (int i = 1; i <= N-len+1; i++){
			catat[awal] = i;
			solusi(awal+1);
		}
	} else if (awal >= len){
		for (int i = 0; i < len; i++){
			if (i < len-1){
				cout << catat[i] << " ";
			} else {
				cout << catat[i] << "\n";
			}
		}	
	} else {
		for (int i = catat[awal-1]+1; i <= N; i++){
			catat[awal] = i;
			solusi(awal+1);
		}
	}
}

int main(){
	cin >> N >> len;
	
	solusi(0);
}

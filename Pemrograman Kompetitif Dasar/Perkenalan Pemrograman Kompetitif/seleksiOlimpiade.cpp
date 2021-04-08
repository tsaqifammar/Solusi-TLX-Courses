#include<iostream>
using namespace std;

struct peserta{
	string id;
	int n1, n2, n3;
};

peserta arr[80];

void tukar(peserta &x, peserta &y){
	peserta temp = x;
	x = y;
	y = temp;
}

void sort(int n){
	for (int i = 1; i < n; i++){
		int j = i;
		bool keluar = false;
		if (arr[j-1].n1 > arr[j].n1){
			keluar = true;
		} else if (arr[j-1].n1 == arr[j].n1){
			if (arr[j-1].n2 > arr[j].n2){
				keluar = true;
			} else if (arr[j-1].n2 == arr[j].n2){
				if (arr[j-1].n3 > arr[j].n3){
					keluar = true;
				} else if (arr[j-1].n3 == arr[j].n3){
					keluar = true;
				}
			}
		}
		while (j > 0 && !keluar){
			tukar(arr[j], arr[j-1]);
			j--;
			keluar = false;
			if (arr[j-1].n1 > arr[j].n1){
				keluar = true;
			} else if (arr[j-1].n1 == arr[j].n1){
				if (arr[j-1].n2 > arr[j].n2){
					keluar = true;
				} else if (arr[j-1].n2 == arr[j].n2){
					if (arr[j-1].n3 > arr[j].n3){
						keluar = true;
					} else if (arr[j-1].n3 == arr[j].n3){
						keluar = true;
					}
				}
			}
		}
	}
}

// n = banyak peserta, m = banyak yang diterima, orang = yang dicari
string solusi(int n, int m, string orang){
	sort(n);
	int i;
	for (i = 0; i < n; i++){
		if (arr[i].id == orang){
			break;
		}
	}
	i++;
	if (i <= m){
		return "YA";
	}
	return "TIDAK";
}

int main(){
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		int n, m;
		string orang;
		cin >> n >> m;
		cin >> orang;
		for (int j = 0; j < n; j++){
			cin >> arr[j].id >> arr[j].n3 >> arr[j].n2 >> arr[j].n1;
		}
		cout << solusi(n, m, orang) << "\n";
	}
	return 0;
}

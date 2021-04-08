#include<iostream>
using namespace std;

struct orang {
	string nama;
	string no;
};

int main(){
	int n, t;
	cin >> n >> t;
	orang arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i].nama >> arr[i].no;
	}
	for (int i = 0; i < t; i++){
		string name;
		cin >> name;
		bool ketemu = false;
		int L = 0, R = n-1;
		
		while (L <= R && !ketemu){
			int mid = L + (R-L)/2;
			if (arr[mid].nama < name){
				L = mid + 1;
			} else if (arr[mid].nama > name){
				R = mid - 1;
			} else {
				cout << arr[mid].no << endl;
				ketemu = true;
			}
		}
		if (ketemu == false){
			cout << "NIHIL\n";
		}
	}
	return 0;
}

#include<iostream>
#include<cmath>
using namespace std;

struct titik{
	int x,y;
};

titik mat[300];
int n;

void tukar(titik &t1, titik &t2){
	// tukar titik
	titik temp = t1;
	t1 = t2;
	t2 = temp;
}

void urut(){
	// urut ascending berdasarkan absis
	for (int i = 1; i < n; i++){
		int j = i;
		while (j > 0 && mat[j-1].x > mat[j].x){
			tukar(mat[j-1], mat[j]);
			j--;
		}
	}
}

double luasSegitiga(titik t2, titik t1, titik t3){
	// mencari luas segitiga dengan shoelace formula
	return abs(t1.x*t2.y + t2.x*t3.y + t3.x*t1.y - t2.x*t1.y - t3.x*t2.y - t1.x*t3.y)/2.0;
} 
int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> mat[i].x >> mat[i].y;
	}
	
	urut();
	
	double min =  200000001;
	for (int i = 0; i < n-2; i++){
		for (int j = i+1; j < n-1; j++){
			for (int k = j+1; k < n; k++){
				double luas = luasSegitiga(mat[i], mat[j], mat[k]);
				if (luas < min){
					min = luas;
				} else if (luas == min){
					cout << "-1.00\n";
					goto HELLO;
				}
			}
		}
	}
	printf("%.2lf\n", min);
	HELLO:{}
	
	return 0;
}

#include<iostream>
#include<cmath>
using namespace std;

string solusi(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	// kalau sama dengan
	if ((x3 == x1 || x3 == x2 || x4 == x1 || x4 == x2)||(y3 == y1 || y3 == y2 || y4 == y1 || y4 == y2)){
		return "YA";
	}
	int xBesar = max(x1,x2), xKecil = min(x1,x2), yBesar = max(y1,y2), yKecil = min(y1,y2);
	
	// kalau satu titik berada di dalam kotak dan satu nya di luar
	bool t3Dalam = (x3 < xBesar && x3 > xKecil && y3 < yBesar && y3 > yKecil);
	bool t4Dalam = (x4 < xBesar && x4 > xKecil && y4 < yBesar && y4 > yKecil);
	if (t3Dalam && !t4Dalam){
		return "YA";
	} else if (!t3Dalam && t4Dalam){
		return "YA";
	}
	
	// kalau kedua titik di dalam kotak
	if (t3Dalam && t4Dalam){
		return "TIDAK";
	}
	
	double m = (y3-y4)/(x3-x4);
	 
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		cout << solusi(x1, y1, x2, y2, x3, y3, x4, y4) << endl;
	}
	return 0;
}

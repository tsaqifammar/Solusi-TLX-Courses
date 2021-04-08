#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1;
	cin >> x2 >> y2 >> r2;
	
	float jarakPusat = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	
	bool nyentuh = (jarakPusat <= r1+r2 && jarakPusat > abs(r1-r2) || jarakPusat == abs(r1-r2));
	if (nyentuh){
		cout << "bersentuhan\n";
	} else {
		cout << "tidak bersentuhan\n";
	}
}

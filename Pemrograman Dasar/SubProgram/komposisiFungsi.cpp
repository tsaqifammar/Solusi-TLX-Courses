#include<iostream>
#include<cmath>
using namespace std;

int fungsi(int a, int b, int x) {
    return abs(a*x + b);
}

int main(){
    int a,b,k,x, hasil;

    cin >> a >> b >> k >> x;
    hasil = fungsi(a,b, x);
    for (int i = 0; i < k-1; i++){
        hasil = fungsi(a, b, hasil);
    }
    cout << hasil << endl;
}

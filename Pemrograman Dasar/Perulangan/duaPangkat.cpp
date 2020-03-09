#include <iostream>
#include <cmath>
using namespace std;

string solusi(int x){
    float a = log2(x);
    if (a-int(a) < 0.000000001){
        return "ya";
    } else {
        return "bukan";
    }
}

int main(){
    int x;
    cin >> x;
    cout << solusi(x) << endl;
}

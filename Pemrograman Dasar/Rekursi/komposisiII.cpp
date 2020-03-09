#include<iostream>
#include<cmath>
using namespace std;

int solusi(int a, int b, int k, int x) {
    if (k == 0){
        return x;
    }
    return abs(a*solusi(a,b,k-1,x)+ b);
}

int main(){
    int a, b, k, x;
    cin >> a >> b >> k >> x;
    cout << solusi(a,b,k,x) << endl;
}

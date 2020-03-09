#include<iostream>
#include<cmath>
using namespace std;

string solusi(int x){
    if (x == 1){
        return "BUKAN";
    }
    for (int i = 2; i <= sqrt(x); i++){
        if (x%i == 0){
            return "BUKAN";
        }
    }
    return "YA";
}

int main(){
    int n,x;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        cout << solusi(x) << endl;
    }
}

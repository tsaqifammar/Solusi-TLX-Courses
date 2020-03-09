#include<iostream>
using namespace std;

void Tukar(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int main(){
    int n, T;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    cin >> T;
    char P, Q;
    int x, y;
    for (int i = 0; i < T; i++){
        cin >> P >> x >> Q >> y;
        x--;
        y--;
        if (P == 'A' && Q == 'A'){
            Tukar(a[x], a[y]);
        } else if (P == 'A' && Q == 'B'){
            Tukar(a[x], b[y]);
        } else if (P == 'B' && Q == 'A'){
            Tukar(b[x], a[y]);
        } else if (P == 'B' && Q == 'B'){
            Tukar(b[x], b[y]);
        }
    }

    for (int i = 0; i < n; i++){
        if (i < n-1){
            cout << a[i] << " ";
        } else {
            cout << a[i] << endl;
        }
    }

    for (int i = 0; i < n; i++){
        if (i < n-1){
            cout << b[i] << " ";
        } else {
            cout << b[i] << endl;
        }
    }
}

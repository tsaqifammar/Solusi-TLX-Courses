#include<iostream>
using namespace std;

int main(){
    int n;

    cin >> n;
    int x;
    x = -1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < i; j++){
            x++;
            cout << x;
            if (x == 9){
                x = -1;
            }
        }
        cout << endl;
    }
}

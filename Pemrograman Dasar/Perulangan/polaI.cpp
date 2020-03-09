#include<iostream>
using namespace std;

int main(){
    int n, x;

    cin >> n >> x;
    for (int i = 1; i <=n; i++){
        if (i%x == 0) {
            if (i <= n-1){
                cout << "* ";
            } else {
                cout << "*" << endl;
            }
        } else {
            if (i <= n-1){
                cout << i << " ";
            } else {
                cout << i << endl;
            }
        }
    }
}

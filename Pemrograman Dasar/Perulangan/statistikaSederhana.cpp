#include<iostream>
using namespace std;

int main(){
    int x, a, min, max;
    cin >> x;
    for (int i = 0; i < x; i++){
        cin >> a;
        if (i == 0){
            min = a;
            max = a;
        } else {
            if (a > max){
                max = a;
            }
            if (a < min){
                min = a;
            }
        }
    }
    cout << max << " " << min << endl;
}

#include<iostream>
using namespace std;

int reverse(int x){
    int hasil = 0;
    while(x > 0){
        hasil = hasil*10 + x%10;
        x /= 10;
    }
    return hasil;
}

int main(){
    int x,y;
    cin >> x >> y;
    
    x = reverse(x);
    y = reverse(y);
    
    cout << reverse(x+y) << endl;
}

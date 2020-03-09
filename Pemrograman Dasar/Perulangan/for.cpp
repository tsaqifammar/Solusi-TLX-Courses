#include<iostream>
using namespace std;

int main(){
    int a, sum, x;
    sum = 0;
    cin >> a;
    for (int i = 1; i <= a; i++){
        cin >> x;
        sum += x; 
    }
    cout << sum << endl;
    
}

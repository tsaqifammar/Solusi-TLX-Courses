#include<iostream>
using namespace std;

int fak(int n) {
    if (n == 0){
        return 1; 
    }
    if (n%2 == 1){
        return n*fak(n-1);
    } else {
        return n/2 * fak(n-1);
    }
}

int main(){
    int n;
    cin >> n;
    cout << fak(n) << endl;
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long a, b, c, d, atas, bawah, fpb;
    
    cin >> a >> b;
    cin >> c >> d;
    
    atas = a*d + b*c;
    bawah = b*d;
    
    
    if ((bawah < 0)){
        bawah *= -1;
        atas *= -1;
    }
        
    if (atas > bawah) {
        fpb = abs(__gcd(atas, bawah));
    } else {
        fpb = abs(__gcd(bawah, atas));
    }
    
    atas /= fpb;
    bawah /= fpb;
    cout << atas << " " << bawah << endl;
    return 0;
}

#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n, d;
    cin >> n >> d;
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++){
        cin >> arr1[i] >> arr2[i];
    }
    int min, max;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            int x = pow(abs(arr1[j]-arr1[i]), d) + pow(abs(arr2[j]-arr2[i]), d);
            if (i == 0){
                min = x;
                max = x;
            } else {
                if (x > max){
                    max = x;
                }
                if (x < min){
                    min = x;
                }
            }
        }
    }
    cout << min << " " << max << endl;
}

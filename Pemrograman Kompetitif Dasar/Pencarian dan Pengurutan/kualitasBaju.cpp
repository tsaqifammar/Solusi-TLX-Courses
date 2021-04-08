#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    float arr[n];
    for (int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    sort(arr, arr+n);
    if (n%2 == 1){
    	printf("%.1f\n", arr[n/2]);
    } else {
    	printf("%.1f\n", (arr[n/2]+arr[n/2 - 1])/2.0);
    }
    return 0;
}

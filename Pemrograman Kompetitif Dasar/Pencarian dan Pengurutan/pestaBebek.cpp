#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> arr;
    for (int i = 0; i < n; i++){
        string str;
        cin >> str;
        int len = arr.size();
        int j = 0;
        for (; j < len; j++){
            if (str < arr[j]) break;
        }
        arr.insert(arr.begin()+j, str);
        cout << j+1 << "\n";
    }
    return 0;
}

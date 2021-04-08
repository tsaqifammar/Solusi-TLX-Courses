#include<bits/stdc++.h>
using namespace std;

struct ea {
    double w, c;
};

bool comp(ea x, ea y){
    return x.c > y.c;
}

int main(){
    int n, x;
    cin >> n >> x;
    ea boom[n];
    for (int i = 0;i < n; i++) cin >> boom[i].w;
    for (int i = 0;i < n; i++) {
        cin >> boom[i].c;
        boom[i].c /= boom[i].w;
    }
    sort(boom, boom+n, comp);

    double sudah = 0, bayar = 0;
    int i = 0;
    while(i < n){
        int sisa = x - sudah;
        if (boom[i].w <= sisa) {
            sudah += boom[i].w;
            bayar += boom[i].w*boom[i].c;
        } else {
            sudah += sisa;
            bayar += boom[i].c * sisa;
        }
        i++;
        if (sudah > x) break;
    }
    printf("%.5lf\n", bayar);
}

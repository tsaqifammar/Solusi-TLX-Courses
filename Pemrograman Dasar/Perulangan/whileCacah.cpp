#include <cstdio>

int main() {
    int x, sum;
    sum = 0;
    while (scanf("%d", &x) != EOF) {
        sum += x;
    }
    printf("%d\n", sum);
}

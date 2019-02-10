#include <bits/stdc++.h>
using namespace std;
double pi = 3.14159265358979;
int n;

int main() {
    scanf("%d", &n);
    int r[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", r + i);
    }
    sort(r, r + n);
    double res = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == n % 2) {
            res -= r[i] * r[i] * pi;
        } else {
            res += r[i] * r[i] * pi;
        }
    }
    printf("%lf\n", res);
}

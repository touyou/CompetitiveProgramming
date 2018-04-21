#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    int m[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
        x -= m[i];
    }
    sort(m, m+n);
    printf("%d\n", n+x/m[0]);
}


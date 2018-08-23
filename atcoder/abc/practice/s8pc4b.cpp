#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int a[16];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int maxa = a[0];
    int minc[16] = {0};
    k--;
    for (int i = 1; i < n; i++) {
        if (maxa >= a[i]) minc[i] = maxa - a[i] + 1;
        else {
            maxa = a[i];
            k--;
        }
    }
}

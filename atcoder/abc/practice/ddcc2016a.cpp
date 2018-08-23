#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c; scanf("%d%d", &r, &c);
    int maxcnt = r / c + 1;
    int res = 0;
    for (int y = c; y <= r; y+=c) {
        for (int x = c; x <= r; x+=c) {
            if (x*x+y*y <= r*r) res++;
        }
    }
    printf("%d\n", res * 4);
}

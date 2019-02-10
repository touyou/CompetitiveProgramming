#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int res;
string s;
int d;

void move(int dist, int dir) {
    if (dist < a) res += a * dir;
    else if (dist > b) res += b * dir;
    else res += dist * dir;
}

int main() {
    scanf("%d%d%d", &n, &a, &b);
    res = 0;
    for (int i = 0; i < n; i++) {
        cin >> s >> d;
        if (s == "East") {
            move(d, 1);
        } else {
            move(d, -1);
        }
    }

    if (res < 0) printf("West %d\n", -1 * res);
    else if (res > 0) printf("East %d\n", res);
    else puts("0");
}

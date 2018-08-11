#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n; scanf("%d", &n);
    string s = "";
    ll x = 2;
    int i = 0;
    if (n == 0) {
        puts("0");
        return 0;
    }
    while (n != 0) {
        if (n % x != 0) {
            s = "1" + s;
            n -= (x / 2) * (i % 2 == 0 ? 1 : -1);
        } else {
            s = "0" + s;
        }
        x *= 2;
        i++;
    }
    cout << s << endl;
}

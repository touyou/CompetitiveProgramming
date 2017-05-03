#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    while (scanf("%d", &n) && n != -1) {
        string res = "";
        if (n == 0) {
            printf("0\n");
            continue;
        }
        while (n > 0) {
            res += (n % 4 + '0');
            n /= 4;
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
}

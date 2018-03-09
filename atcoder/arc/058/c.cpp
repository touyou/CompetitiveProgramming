#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    bool d[10];
    for (int i = 0; i < k; i++) {
        int di;
        scanf("%d", &di);
        d[di] = true;
    }
    for (;; n++) {
        string number = to_string(n);
        int i = 0;
        for (; i < number.length(); i++) {
            if (d[number[i] - '0']) break;
        }
        if (i == number.length()) {
            cout << n << endl;
            break;
        }
    }
}

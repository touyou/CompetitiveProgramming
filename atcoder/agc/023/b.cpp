#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; scanf("%d", &n);
    string s[300];
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        s[i] = str;
    }
    int res = 0;
    for (int k = 0; k < n; k++) {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][(j+k)%n] != s[j][(i+k)%n]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) res++;
    }
    cout << res * n << endl;
}


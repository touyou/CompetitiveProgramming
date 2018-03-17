#include <bits/stdc++.h>
using namespace std;
string s[100], t[100];
int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) cin >> s[i];
    scanf("%d", &m);
    for (int i = 0; i < m; i++) cin >> t[i];
    int res = 0;
    map<string, int> cnt;
    for (int i = 0; i < n; i++) {
        if (cnt.find(s[i]) != cnt.end()) {
            cnt[s[i]]++;
        } else {
            cnt[s[i]] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        int c = cnt[s[i]];
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) c--;
        }
        res = max(res, c);
    }
    printf("%d\n", res);
}

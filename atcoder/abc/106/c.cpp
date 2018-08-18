#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s; cin >> s;
    ll k; cin >> k;
    int pos = 0;
    while (s[pos] == '1') pos++;
    if (pos >= k) cout << 1 << endl;
    else cout << s[pos] << endl;
}

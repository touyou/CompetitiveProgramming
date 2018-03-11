#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
typedef long long ll;

int len;

int main() {
    string s;
    cin >> s;
    ll res = 0;
    for (int i = 0; i < 1 << (s.length() - 1); i++) {
        int prev = 0;
        for (int j = 0; j < s.length(); j++) {
            if (i >> j & 1) {
                res += stoll(s.substr(prev, j - prev + 1));
                prev = j + 1;
            }
        }
        if (prev < s.length()) {
            res += stoll(s.substr(prev, s.length() - prev));
        }
    }
    cout << res << endl;
}

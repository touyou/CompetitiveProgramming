#include <bits/stdc++.h>
using namespace std;
int main() {
    int h, w;
    scanf("%d%d", &h, &w);
    string s[50];
    for (auto i = 0; i < h; i++) cin >> s[i];
    bool flag = true;
    for (auto i = 0; i < h; i++) {
        for (auto j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                if (i - 1 >= 0 && s[i-1][j] == '#') continue;
                if (i + 1 < h && s[i+1][j] == '#') continue;
                if (j - 1 >= 0 && s[i][j-1] == '#') continue;
                if (j + 1 < w && s[i][j+1] == '#') continue;
                flag = false;
                break;
            }
        }
    }
    puts(flag ? "Yes" : "No");
}
